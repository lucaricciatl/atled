#include "GraphicsManager.hpp"

#include <chrono>
#include <iostream>
#include <thread>
#include "GraphicsContext.hpp"
#include "PolyLine2D.hpp"
#include <memory>
#include <Device.hpp>
#include "PolygonBuffer2D.hpp"
#include "ShaderManager.hpp"
#include <cmath>
namespace {
constexpr unsigned int defaultFramerate = 30;
float times = 0.0f;  // Initialize time variable

}

namespace graphics {

GraphicsManager::GraphicsManager() {
  mContext = std::make_shared<GraphicsContext>();
  mThread = std::make_unique<std::thread>();
  mDevice = Device().Create();
};

// Destructor
GraphicsManager::~GraphicsManager() {
  // Stop the thread
  Stop();
}

  void GraphicsManager::SetConfigs(GfxConfig aGfxConfigs){
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

  //CameraLoop();

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
    auto layer = mContext->mLayerManager.GetLayerById(1);
    auto bm = layer->GetBufferManager();
    auto lb = bm->GetLineBuffer();
    auto pb = bm->GetPointBuffer();
    auto polyBuffer = bm->GetPolygonBuffer();

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

        linePoints.emplace_back(x, y, raylib::RED);
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
        float theta2 = (PI * (i ))*2 / segments;


        // Oscillate the radius
        float oscillatingRadius = radius + 100.0f * abs(sin(times * 0.01f));
        int x2 = static_cast<int>(centerX + oscillatingRadius * cos(theta2));
        int y2 = static_cast<int>(centerY + oscillatingRadius * sin(theta2));

        circleLines.emplace_back(x2, y2, raylib::GREEN);
      }
      circleLines.emplace_back(circleLines[0]);
      lb->SetBuffer(circleLines);
      lb->DrawBuffer();
    }

    // 3. Draw an oscillating irregular polygon
    {
      std::vector<ColoredPoint2D> points;
      points.emplace_back(static_cast<int>(700 + 0), static_cast<int>(700 + 0),
                          raylib::RED);  // Example points
      for (int i = 0; i < 50; ++i) {
        // Apply oscillation to the polygon points
        int x = static_cast<int>(700 + 100 * sin(i * 0.01));
        int y = static_cast<int>(700 + 100 * cos(i * 0.01));
        points.emplace_back(x, y, raylib::RED);
      }

      // Set the points buffer to the polygon buffer
      polyBuffer->SetBuffer(points);
      polyBuffer->DrawBuffer();  // Draw the oscillating polygon
    }

    auto col = raylib::Color(0, 0, 0, 0);
    mContext->Clear(col);
    mContext->End();

    times += 0.01f;  // Increment time for oscillation
  }
}
}  // namespace graphics