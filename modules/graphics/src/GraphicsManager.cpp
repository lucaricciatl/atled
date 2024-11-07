#include "GraphicsManager.hpp"
#include "RaylibDisplay.hpp" // Assuming RaylibDisplay is a concrete implementation of IDisplay
#include <chrono>
#include <cmath>
#include <iostream>
#include <memory>
#include "Arc.hpp"
#include "Model2DFactory.hpp"
#include "Model2D.hpp"
#include "GraphicsContext.hpp"
#include "PolyLine2D.hpp"
#include "PolygonBuffer2D.hpp"

namespace graphics {

GraphicsManager::GraphicsManager()
    : mFrameRate(60),
      mContext(std::make_shared<GraphicsContext>()),
      mConfigs(std::make_shared<GfxConfig>()),
      mDisplay(std::make_unique<RaylibDisplay>()) // Instantiate with RaylibDisplay (or another display backend)
{
}

GraphicsManager::~GraphicsManager() {
    // No need to call Stop() as threading is removed
}

void GraphicsManager::SetConfigs(const GfxConfig& gfxConfigs) {
    *mConfigs = gfxConfigs;
}

void GraphicsManager::SetTargetFramerate(unsigned int frameRate) {
    mFrameRate = frameRate;
}

std::shared_ptr<GraphicsContext> GraphicsManager::GetGraphicsContext() {
    return mContext;
}

void GraphicsManager::Init() {
    // Initialization logic for context and display
    mContext->InitWindowManager(); // Initialize context with display
}

void GraphicsManager::Start() {
    auto frameDuration = std::chrono::milliseconds(1000 / mFrameRate);

    while (true) {
        auto frameStart = std::chrono::steady_clock::now();
        mContext->BeginDrawing();
        Render();
        

        // Frame rate control
        auto frameEnd = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(frameEnd - frameStart);
        if (elapsed < frameDuration) {
            std::this_thread::sleep_for(frameDuration - elapsed);
        }
        mContext->EndDrawing(); // Finish the current frame
    }

}

void GraphicsManager::Render() {
    Clear(RAYWHITE); // Clear with white color

    std::lock_guard<std::mutex> lock(layersMutex);
    for (const auto& [layerId, primitives] : layers) {
        DrawLayer(layerId);
    }

}

// Thread-related methods removed

// Add primitive methods (no changes)
void GraphicsManager::AddArc(const int& aLayerId, std::shared_ptr<Arc> aArc) {
    std::lock_guard<std::mutex> lock(layersMutex);
    layers[aLayerId].push_back(aArc);
}

void GraphicsManager::AddCircle(const int& aLayerId, std::shared_ptr<Circle> aCircle) {
    std::lock_guard<std::mutex> lock(layersMutex);
    layers[aLayerId].push_back(aCircle);
}

void GraphicsManager::AddRectangle(const int& aLayerId, std::shared_ptr<Rectangle> aRectangle) {
    std::lock_guard<std::mutex> lock(layersMutex);
    layers[aLayerId].push_back(aRectangle);
}

void GraphicsManager::AddLine(const int& aLayerId, std::shared_ptr<Line> aLine) {
    std::lock_guard<std::mutex> lock(layersMutex);
    layers[aLayerId].push_back(aLine);
}

void GraphicsManager::AddPolyline(const int& aLayerId, std::shared_ptr<Polyline> aPolyline) {
    std::lock_guard<std::mutex> lock(layersMutex);
    layers[aLayerId].push_back(aPolyline);
}

void GraphicsManager::AddTriangle(const int& aLayerId, std::shared_ptr<Triangle> aTriangle) {
    std::lock_guard<std::mutex> lock(layersMutex);
    layers[aLayerId].push_back(aTriangle);
}

void GraphicsManager::AddPolygon(const int& aLayerId, std::shared_ptr<Polygon> aPolygon) {
    std::lock_guard<std::mutex> lock(layersMutex);
    layers[aLayerId].push_back(aPolygon);
}

void GraphicsManager::DrawLayer(const int& aLayerId) {
    if (layers.find(aLayerId) != layers.end()) {
        for (const auto& primitive : layers[aLayerId]) {
            primitive->Draw();
        }
    }
}

void GraphicsManager::Clear(::Color aColor) {
    mContext->Clear(aColor);
}

} // namespace graphics
