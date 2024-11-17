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
#include "Cube.hpp"

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
    mCameraManager->BeginActiveCamera();
    for (const auto& [layerId, primitives] : layers) {
        DrawLayer(layerId);
    }
    mCameraManager->EndActiveCamera();
    GetGraphicsContext()->EndDrawing(); // Finish the current frame
}

void GraphicsManager::AddLine3D(const int& aLayerId, std::shared_ptr<Line3D> aLine3D) {
std::lock_guard<std::mutex> lock(layersMutex);
layers[aLayerId].push_back(std::static_pointer_cast<Model>(aLine3D));
}

void GraphicsManager::AddArc(const int& aLayerId, std::shared_ptr<Arc> aArc) {
    std::lock_guard<std::mutex> lock(layersMutex);
    layers[aLayerId].push_back(std::static_pointer_cast<Model>(aArc));
}

void GraphicsManager::AddCircle(const int& aLayerId, std::shared_ptr<Circle> aCircle) {
    std::lock_guard<std::mutex> lock(layersMutex);
    layers[aLayerId].push_back(std::static_pointer_cast<Model>(aCircle));
}

void GraphicsManager::AddRectangle(const int& aLayerId, std::shared_ptr<Rectangle> aRectangle) {
    std::lock_guard<std::mutex> lock(layersMutex);
    layers[aLayerId].push_back(std::static_pointer_cast<Model>(aRectangle));
}

void GraphicsManager::AddLine(const int& aLayerId, std::shared_ptr<Line> aLine) {
    std::lock_guard<std::mutex> lock(layersMutex);
    layers[aLayerId].push_back(std::static_pointer_cast<Model>(aLine));
}

void GraphicsManager::AddPolyline(const int& aLayerId, std::shared_ptr<Polyline> aPolyline) {
    std::lock_guard<std::mutex> lock(layersMutex);
    layers[aLayerId].push_back(std::static_pointer_cast<Model>(aPolyline));
}

void GraphicsManager::AddTriangle(const int& aLayerId, std::shared_ptr<Triangle> aTriangle) {
    std::lock_guard<std::mutex> lock(layersMutex);
    layers[aLayerId].push_back(std::static_pointer_cast<Model>(aTriangle));
}

void GraphicsManager::AddSphere(const int& aLayerId, std::shared_ptr<Sphere> aSphere) {
    std::lock_guard<std::mutex> lock(layersMutex);
    layers[aLayerId].push_back(std::static_pointer_cast<Model>(aSphere));
}

void GraphicsManager::AddCube(const int& aLayerId, std::shared_ptr<Cube> aCube) {
    std::lock_guard<std::mutex> lock(layersMutex);
    layers[aLayerId].push_back(std::static_pointer_cast<Model>(aCube));
}

void GraphicsManager::AddPolygon(const int& aLayerId, std::shared_ptr<Polygon> aPolygon) {
    std::lock_guard<std::mutex> lock(layersMutex);
    layers[aLayerId].push_back(std::static_pointer_cast<Model>(aPolygon));
}

void GraphicsManager::Clear(::Color aColor) {
    mContext->Clear(aColor);
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
