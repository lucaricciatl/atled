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
#include <vector>
#include "raylib.hpp"
#include "Point2D.hpp"
#include "Cube.hpp"

namespace graphics {

GraphicsManager::GraphicsManager()
    : mFrameRate(60),
      mContext(std::make_shared<GraphicsContext>()),
      mConfigs(std::make_shared<GraphicsConfig>()),
      mDisplay(std::make_unique<RaylibDisplay>()) // Instantiate with RaylibDisplay (or another display backend)
{
}

GraphicsManager::~GraphicsManager() {
    // No need to call Stop() as threading is removed
}

void GraphicsManager::SetConfigs(const GraphicsConfig& gfxConfigs) {
    mConfigs = std::make_shared<GraphicsConfig>(gfxConfigs);
    GetGraphicsContext()->SetFlags(mConfigs);
}

void GraphicsManager::SetTargetFramerate(unsigned int frameRate) {
    mFrameRate = frameRate;
}

std::shared_ptr<GraphicsContext> GraphicsManager::GetGraphicsContext() {
    return mContext;
}

void GraphicsManager::Init() {
    // Initialization logic for context and display
    GetGraphicsContext()->InitWindowManager(); // Initialize context with display

    
}

void GraphicsManager::Start() {
    auto frameDuration = std::chrono::milliseconds(1000 / mFrameRate);

    while (true) {
        auto frameStart = std::chrono::steady_clock::now();

        Render();
        

        // Frame rate control
        auto frameEnd = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(frameEnd - frameStart);
        if (elapsed < frameDuration) {
            std::this_thread::sleep_for(frameDuration - elapsed);
        }
    }
}

void GraphicsManager::SetCameraMng(std::shared_ptr<graphics::CameraManager> aCameraMng) {
    mCameraManager = aCameraMng;
}
void GraphicsManager::Render() {
    std::lock_guard<std::mutex> lock(layersMutex);
    GetGraphicsContext()->BeginDrawing();
    Clear(BLACK);
    mCameraManager->BeginActiveCamera();
    for (const auto& [layerId, primitives] : layers) {
        DrawLayer(layerId);
    }

    mCameraManager->EndActiveCamera();

    GetGraphicsContext()->EndDrawing(); // Finish the current frame

}


void GraphicsManager::Clear(raylib::Color aColor) {
    mContext->Clear(aColor);
}

void GraphicsManager::AddShape(const int& aLayerId, std::shared_ptr<Model> aShape) {
    std::lock_guard<std::mutex> lock(layersMutex); // Ensure thread safety
    layers[aLayerId].push_back(aShape);           // Add the shape to the appropriate layer
}

void GraphicsManager::DrawLayer(const int& aLayerId) {
    // Check if the specified layer exists in the map
    if (layers.find(aLayerId) != layers.end()) {
        // Iterate over each Model in the layer
        for (const auto& primitive : layers[aLayerId]) {
            primitive->Draw();  // Calls the specific Draw implementation for each model
        }
    }
}

} // namespace graphics
