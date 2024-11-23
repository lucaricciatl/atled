#include "engine.hpp"
#include "CoreEngine.hpp"
#include "InputManager.hpp"
#include <iostream>
#include "CameraFactory.hpp"
#include "CameraManager.hpp"
#include <thread>
#include <chrono>
#include <cstdlib> // For rand()
#include <mutex>
#include "Sphere.hpp"
#include "ITextDrawer.hpp"
#include "RaylibtextDrawer.hpp"
#include "Model2DFactory.hpp"
#include "Model3DFactory.hpp"

#include <memory>
using namespace graphics;
using namespace input;

std::mutex graphicsMutex; // Mutex to protect graphicsManager access
bool running = true; // Flag to control the input thread

// Default implementation of OnUpdate
void Engine::OnUpdate() {
    if (inputManager->IsKeyDown(KEY_W)) {
        cameraManager->SetCameraTargetY(cameraManager->GetCameraTargetY() - 0.2f); // Move view up
    }
    if (inputManager->IsKeyDown(KEY_S)) {
        cameraManager->SetCameraTargetY(cameraManager->GetCameraTargetY() + 0.2f); // Move view down
    }
    if (inputManager->IsKeyDown(KEY_A)) {
        cameraManager->SetCameraTargetX(cameraManager->GetCameraTargetX() - 0.2f); // Move view left
    }
    if (inputManager->IsKeyDown(KEY_D)) {
        cameraManager->SetCameraTargetX(cameraManager->GetCameraTargetX() + 0.2f); // Move view right
    }

    // Zoom logic
    float mouseWheelMove = inputManager->GetMouseWheelMove();
    if (mouseWheelMove != 0.0f) {
        float currentZoom = cameraManager->GetCameraZoom();
        cameraManager->SetCameraZoom(currentZoom + mouseWheelMove * 0.1f); // Adjust zoom speed with the multiplier
    }

    // Adjust mouse offset and scale dynamically
    int offsetX = static_cast<int>(cameraManager->GetCameraTargetX());
    int offsetY = static_cast<int>(cameraManager->GetCameraTargetY());
    float scaleX = cameraManager->GetCameraZoom();
    float scaleY = cameraManager->GetCameraZoom();

    raylib::SetMouseOffset(offsetX, offsetY);   // Adjust mouse offset based on camera target
    raylib::SetMouseScale(1/scaleX, 1/scaleY);     // Scale mouse position to match zoom level

    // Existing model creation logic
    if (inputManager->IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        int mouseX = inputManager->GetMouseX();
        int mouseY = inputManager->GetMouseY();
        int modelType = rand() % 4; // Extend range to 4 to include 3D sphere
        Color randomColor(rand() % 256, rand() % 256, rand() % 256, 128);

        std::lock_guard<std::mutex> lock(graphicsMutex); // Lock graphicsManager for thread-safe access
        if (modelType == 0) { // Random Circle
            auto circle = Model3DFactory::CreateSphere();
            graphicsManager->AddShape(rand(), circle);
        }

    }
}


// Default implementation of OnStart
void Engine::OnStart() {
    auto ctx = graphicsManager->GetGraphicsContext();
    ctx->SetSize(900, 900);
    ctx->SetTitle("Window");
    auto configs = graphics::GraphicsConfig({ FLAG_WINDOW_RESIZABLE, FLAG_VSYNC_HINT, FLAG_WINDOW_HIGHDPI, FLAG_MSAA_4X_HINT });
    graphicsManager->SetConfigs(configs);
    ctx->InitWindowManager();

}

// Default implementation of OnShutdown
void Engine::OnShutdown() {
    std::cout << "Performing engine shutdown tasks..." << std::endl;
}

// Default implementation of OnRender
void Engine::OnRender() {
    std::lock_guard<std::mutex> lock(graphicsMutex); // Lock during rendering
    graphicsManager->Render();
    RaylibTextDrawer td;
    td.DrawText("HI :)", 400, 400, 20, Color{255, 160, 120, 255});
    graphicsManager->Clear(BLACK);
}
