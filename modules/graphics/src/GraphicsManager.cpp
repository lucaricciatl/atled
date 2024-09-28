#include "GraphicsManager.hpp"

#include <DisplayFactory.hpp>
#include <chrono>
#include <cmath>
#include <iostream>
#include <memory>
#include <thread>

#include "GraphicsContext.hpp"
#include "PolyLine2D.hpp"
#include "PolygonBuffer2D.hpp"
#include "ShaderManager.hpp"


namespace {
constexpr unsigned int defaultFramerate = 30;
float times = 0.0f;  // Initialize time variable
DisplayType displayType = DisplayType::Raylib;
}  // namespace

namespace graphics {

GraphicsManager::GraphicsManager() {
  mContext = std::make_shared<GraphicsContext>();
  mThread = std::make_unique<std::thread>();
  mDisplay = DisplayFactory::CreateDisplay(displayType);
  if (!mDisplay) {
      throw std::runtime_error("Failed to create display device!");
  }
};

// Destructor
GraphicsManager::~GraphicsManager() {
  // Stop the thread
  Stop();
}

void GraphicsManager::SetConfigs(GfxConfig aGfxConfigs) {
  mConfigs = std::make_shared<GfxConfig>(
      aGfxConfigs);  // Create a shared pointer to a copy of aGfxConfigs
};

void GraphicsManager::SetTargetFramerate(unsigned int frameRate) {
  mFrameRate = frameRate;
}

std::shared_ptr<GraphicsContext> GraphicsManager::GetGraphicsContext() {
  return mContext;
}

void GraphicsManager::Stop() {
  // Stop the thread and join it
  mRunning = false;
  if (mThread->joinable()) {
    mThread->join();
  }
}

void GraphicsManager::Start() {
  mContext->InitWindowManager(mConfigs->WindowConfig);
  mRunning = true;
  RenderLoop();

  // CameraLoop();
}

void GraphicsManager::CameraStep() {
  using namespace std::chrono;
  auto frameDuration =
      milliseconds(1000 / mFrameRate);  // Same frame duration as RenderLoop

  auto frameStart = steady_clock::now();

  // Update camera here
  if (mCamera) {
    try {
      mCamera->Update();  // Assuming CameraManager has an Update function
                          // that updates camera position, orientation, etc.
    } catch (const std::exception& e) {
      std::cerr << "Camera update threw an exception: " << e.what()
                << std::endl;
      mRunning = false;  // Stop the loop on exception
    }
  }

  auto frameEnd = steady_clock::now();
  auto elapsed = duration_cast<milliseconds>(frameEnd - frameStart);
  auto sleepTime = frameDuration - elapsed;

  // Sleep for the remaining time in the frame if needed
  if (sleepTime > milliseconds(0)) {
    std::this_thread::sleep_for(sleepTime);
  }
}

// The rendering loop method
void GraphicsManager::RenderLoop() {
  using namespace std::chrono;
  auto frameDuration = milliseconds(1000 / mFrameRate);
  while (mRunning) {
    auto frameStart = steady_clock::now();

    if (true) {
      try {
        Render();

      } catch (const std::exception& e) {
        std::cerr << "Render function threw an exception: " << e.what()
                  << std::endl;
        mRunning = false;  // Stop the loop on exception
      }
    }

    auto frameEnd = steady_clock::now();
    auto elapsed = duration_cast<milliseconds>(frameEnd - frameStart);
    auto sleepTime = frameDuration - elapsed;

    if (sleepTime > milliseconds(0)) {
      std::this_thread::sleep_for(sleepTime);
    }
  }
}

void GraphicsManager::Render() {
  if (mContext->isReady) {
    mContext->Begin();

    mContext->mLayerManager.AddLayer(1);
    mContext->mLayerManager.AddLayer(2);
    auto layer = mContext->mLayerManager.GetLayerById(1);
    auto layer2 = mContext->mLayerManager.GetLayerById(2);
    auto bm = layer->GetBufferManager();
    std::shared_ptr<Buffer2D> pb = bm->createBuffer(BufferType::POINT2D);
    std::shared_ptr<Buffer2D> lb = bm->createBuffer(BufferType::LINE2D);
    std::shared_ptr<Buffer2D> polyBuffer = bm->createBuffer(BufferType::POLY2D);
    std::shared_ptr<Buffer2D> polyBuffer2 =
        bm->createBuffer(BufferType::POLY2D);
    // 1. Draw a line with oscillating points
    {
      std::vector<ColoredPoint2D> linePoints;
      int x1 = 50, y1 = 50;
      int x2 = 250, y2 = 250;
      int numPoints = 200;  // Number of points along the line
      for (int i = 0; i <= numPoints; ++i) {
        float t = static_cast<float>(i) / numPoints;
        int x = static_cast<int>(x1 + t * (x2 - x1));
        int y = static_cast<int>(y1 + t * (y2 - y1));

        // Apply sinusoidal oscillation
        float oscillation =
            100.0f *
            sin(times + i * 0.1f);  // Amplitude and frequency of oscillation
        y += static_cast<int>(
            oscillation);  // Modify y-position with oscillation

        linePoints.emplace_back(x, y, RED);
      }
      pb->SetBuffer(linePoints);
      pb->DrawBuffer();
    }

    // 2. Draw an oscillating circle using lines
    {
      std::vector<ColoredPoint2D> circleLines;
      int centerX = 600, centerY = 600, radius = 100;
      int segments = 100;  // Number of segments to approximate the circle
      for (int i = 0; i < segments; ++i) {
        float theta2 = (PI * (i)) * 2 / segments;

        // Oscillate the radius
        float oscillatingRadius = radius + 100.0f * abs(sin(times * 0.01f));
        int x2 = static_cast<int>(centerX + oscillatingRadius * cos(theta2));
        int y2 = static_cast<int>(centerY + oscillatingRadius * sin(theta2));

        circleLines.emplace_back(x2, y2, GREEN);
      }
      circleLines.emplace_back(circleLines[0]);
      lb->SetBuffer(circleLines);
      lb->DrawBuffer();
    }

    std::vector<ColoredPoint2D> points2;
    auto colrt = RED;
    int x1 = static_cast<int>(400 + 200);
    int y1 = static_cast<int>(200 + 130);
    points2.emplace_back(x1, y1, colrt);
    int x2 = static_cast<int>(400 + 130);
    int y2 = static_cast<int>(200 + 120);
    points2.emplace_back(x2, y2, colrt);

    int x3 = static_cast<int>(400 + 100);
    int y3 = static_cast<int>(200 + 0);
    points2.emplace_back(x3, y3, colrt);

    int x4 = static_cast<int>(400 + 0);
    int y4 = static_cast<int>(200 + 100);
    points2.emplace_back(x4, y4, colrt);
    // Set the points buffer to the polygon buffer
    polyBuffer2->SetBuffer(points2);
    polyBuffer2->DrawBuffer();  // Draw the oscillating polygon

    // 3. Draw an oscillating irregular polygon
    {
      std::vector<ColoredPoint2D> points;
      auto colrt = RED;
      points.emplace_back(static_cast<int>(700 + 0), static_cast<int>(700 + 0),
                          colrt);  // Example points
      for (int i = 0; i < (13 * sin(times * 0.1)); ++i) {
        // Apply oscillation to the polygon points
        int x = static_cast<int>(700 + 100 * sin(2 * PI / 12 * i));
        int y = static_cast<int>(700 + 100 * cos(2 * PI / 12 * i));
        points.emplace_back(x, y, colrt);
      }

      // Set the points buffer to the polygon buffer
      polyBuffer->SetBuffer(points);
      polyBuffer->DrawBuffer();  // Draw the oscillating polygon
    }

    // 4. Draw an oscillating irregular polygon

    auto col = BLACK;
    mContext->Clear(col);
    mContext->End();

    times += 0.01f;  // Increment time for oscillation
  }
}
}  // namespace graphics