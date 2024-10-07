#include "GraphicsManager.hpp"

#include <DisplayFactory.hpp>
#include <chrono>
#include <cmath>
#include <iostream>
#include <memory>
#include <thread>
#include "Arc.hpp"
#include "ShapeFactory.hpp"
#include "Shape.hpp"
#include "GraphicsContext.hpp"
#include "PolyLine2D.hpp"
#include "PolygonBuffer2D.hpp"


namespace {
constexpr unsigned int defaultFramerate = 30;
float times = 0.0f;  // Initialize time variable
DisplayType displayType = DisplayType::Raylib;
}  // namespace

namespace graphics {

GraphicsManager::GraphicsManager() {
  mContext = std::make_shared<GraphicsContext>();
  mThread = std::make_unique<std::thread>();
  SetTargetFramerate(defaultFramerate);
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
        if (mContext->isReady) {
          if (!WindowShouldClose())  // Detect window close button or ESC key
          {
            // Draw
            //-----------------------------------------------------

            Render();

            //-----------------------------------------------------
          } else {
            CloseWindow();
          }
        }

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

void GraphicsManager::Init() {

}

void GraphicsManager::Render() {
  BeginDrawing();
  EndDrawing();
}

// drawing methods
void GraphicsManager::AddArc(const int& aLayerId, std::shared_ptr<Arc> aArc) {
  mContext->mLayerManager.AddLayer(aLayerId);
  auto layer = mContext->mLayerManager.GetLayerById(aLayerId);
  layer->GetBufferManager()->AddShapeBuffer(aArc);
};

void GraphicsManager::AddCircle(const int& aLayerId, std::shared_ptr<Circle> aCircle) {
  mContext->mLayerManager.AddLayer(aLayerId);
  auto layer = mContext->mLayerManager.GetLayerById(aLayerId);
  layer->GetBufferManager()->AddShapeBuffer(aCircle);
};

void GraphicsManager::DrawLayer(const int& aLayerId) {
  auto layer = mContext->mLayerManager.GetLayerById(aLayerId);
  layer->Draw();
};

}  // namespace graphics

