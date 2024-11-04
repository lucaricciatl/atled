#include "GraphicsManager.hpp"

#include <DisplayFactory.hpp>
#include <chrono>
#include <cmath>
#include <iostream>
#include <memory>
#include <thread>
#include "Arc.hpp"
#include "Model2DFactory.hpp"
#include "Model2D.hpp"
#include "GraphicsContext.hpp"
#include "PolyLine2D.hpp"
#include "PolygonBuffer2D.hpp"


namespace {
constexpr unsigned int defaultFramerate = 30;
float times = 0.0f; 
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

GraphicsManager::~GraphicsManager() {
  Stop();
}

void GraphicsManager::SetConfigs(GfxConfig aGfxConfigs) {
  mConfigs = std::make_shared<GfxConfig>(
      aGfxConfigs);  
};

void GraphicsManager::SetTargetFramerate(unsigned int frameRate) {
  mFrameRate = frameRate;
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

void GraphicsManager::RenderLoop() {
  using namespace std::chrono;
  auto frameDuration = milliseconds(1000 / mFrameRate);
  while (mRunning) {
    auto frameStart = steady_clock::now();

    if (true) {
      try {
        if (mContext->isReady) {
          if (!WindowShouldClose()) 
          {
            // Draw
            Render();
          } else {
            CloseWindow();
          }
        }

      } catch (const std::exception& e) {
        std::cerr << "Render function threw an exception: " << e.what()
                  << std::endl;
        mRunning = false;  
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

void GraphicsManager::AddRectangle(const int& aLayerId,
                                std::shared_ptr<Rectangle> aRectangle) {
  mContext->mLayerManager.AddLayer(aLayerId);
  auto layer = mContext->mLayerManager.GetLayerById(aLayerId);
  layer->GetBufferManager()->AddShapeBuffer(aRectangle);
};

void GraphicsManager::AddLine(const int& aLayerId,
                                   std::shared_ptr<Line> aLine) {
  mContext->mLayerManager.AddLayer(aLayerId);
  auto layer = mContext->mLayerManager.GetLayerById(aLayerId);
  layer->GetBufferManager()->AddShapeBuffer(aLine);
};

void GraphicsManager::AddPolyline(const int& aLayerId,
                                  std::shared_ptr<Polyline> aPolyline) {
  mContext->mLayerManager.AddLayer(aLayerId);
  auto layer = mContext->mLayerManager.GetLayerById(aLayerId);
  layer->GetBufferManager()->AddShapeBuffer(aPolyline);
}

void GraphicsManager::AddTriangle(const int& aLayerId, std::shared_ptr<Triangle> aTriangle) {
    mContext->mLayerManager.AddLayer(aLayerId);
    auto layer = mContext->mLayerManager.GetLayerById(aLayerId);
    layer->GetBufferManager()->AddShapeBuffer(aTriangle);
}

void GraphicsManager::AddPolygon(const int& aLayerId, std::shared_ptr<Polygon> aPolygon) {
    mContext->mLayerManager.AddLayer(aLayerId);
    auto layer = mContext->mLayerManager.GetLayerById(aLayerId);
    layer->GetBufferManager()->AddShapeBuffer(aPolygon);
}
void GraphicsManager::DrawLayer(const int& aLayerId) {
  auto layer = mContext->mLayerManager.GetLayerById(aLayerId);
  layer->Draw();
};

void GraphicsManager::Clear(::Color aColor){
  mContext->Clear(aColor);
};

}  // namespace graphics

