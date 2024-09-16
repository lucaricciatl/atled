#include "GraphicsManager.hpp"

#include <chrono>
#include <iostream>
#include <thread>
#include <cmath>
#include <vector>
#include "GraphicsContext.hpp"
#include "PolyLine2D.hpp"

namespace {
constexpr unsigned int defaultFramerate = 30;
}  // namespace

namespace graphics {

GraphicsManager::GraphicsManager() {
  mContext = std::make_shared<GraphicsContext>();
  mThread = std::make_unique<std::thread>();
}

GraphicsManager::~GraphicsManager() {
  Stop();
}

void GraphicsManager::SetConfigs(GfxConfig aGfxConfigs) {
  mConfigs = std::make_shared<GfxConfig>(std::move(aGfxConfigs));
}

void GraphicsManager::SetTargetFramerate(unsigned int aFrameRate) {
  mFrameRate = aFrameRate;
}

std::shared_ptr<GraphicsContext> GraphicsManager::GetGraphicsContext() {
  return mContext;
}

void GraphicsManager::Stop() {
  mRunning = false;
  if (mThread->joinable()) {
    mThread->join();
  }
}

void GraphicsManager::Start() {
  mContext->InitWindowManager(mConfigs->WindowConfig);
  mRunning = true;
  RenderLoop();
}

void GraphicsManager::CameraStep() {
  using namespace std::chrono;
  constexpr auto frameDuration = milliseconds(1000 / defaultFramerate);

  const auto frameStart = steady_clock::now();
  
  if (mCamera) {
    try {
      mCamera->Update();
    } catch (const std::exception& e) {
      std::cerr << "Camera update threw an exception: " << e.what() << std::endl;
      mRunning = false;
    }
  }

  const auto frameEnd = steady_clock::now();
  const auto elapsed = duration_cast<milliseconds>(frameEnd - frameStart);
  const auto sleepTime = frameDuration - elapsed;

  if (sleepTime > milliseconds(0)) {
    std::this_thread::sleep_for(sleepTime);
  }
}

void GraphicsManager::RenderLoop() {
  using namespace std::chrono;
  const auto frameDuration = milliseconds(1000 / mFrameRate);
  
  while (mRunning) {
    const auto frameStart = steady_clock::now();
    
    try {
      Render();
    } catch (const std::exception& e) {
      std::cerr << "Render function threw an exception: " << e.what() << std::endl;
      mRunning = false;
    }

    const auto frameEnd = steady_clock::now();
    const auto elapsed = duration_cast<milliseconds>(frameEnd - frameStart);
    const auto sleepTime = frameDuration - elapsed;

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

    std::vector<ColoredPoint2D> points;
    points.reserve(1000);
    
    for (int i = 0; i < 1000; ++i) {
      points.emplace_back(
        static_cast<int>(200 + 100 * std::sin(i * 0.01)),
        static_cast<int>(200 + 100 * std::cos(i * 0.01)),
        raylib::RED
      );
    }

    lb->SetBuffer(points);
    lb->DrawBuffer();
    mContext->Clear(raylib::Color(0, 0, 0, 0));
    mContext->End();

    points.shrink_to_fit();  // Optimize memory
  } else {
    std::cerr << "Error: Graphics context is not initialized." << std::endl;
  }
}

}  // namespace graphics