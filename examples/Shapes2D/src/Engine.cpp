#include "engine.hpp"
#include "CoreEngine.hpp"
#include "InputManager.hpp"
#include "Model2DFactory.hpp"
#include "Model3DFactory.hpp"
#include <iostream>
#include "CameraFactory.hpp"
#include "CameraManager.hpp"
#include <thread>
#include <chrono>
#include <cstdlib> // For rand()
#include <mutex>
#include "Sphere.hpp"

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

    SetMouseOffset(offsetX, offsetY);   // Adjust mouse offset based on camera target
    SetMouseScale(1/scaleX, 1/scaleY);     // Scale mouse position to match zoom level

    // Existing model creation logic
    if (inputManager->IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        int mouseX = inputManager->GetMouseX();
        int mouseY = inputManager->GetMouseY();
        int modelType = rand() % 4; // Extend range to 4 to include 3D sphere
        Color randomColor(rand() % 256, rand() % 256, rand() % 256, 128);

        std::lock_guard<std::mutex> lock(graphicsMutex); // Lock graphicsManager for thread-safe access
        if (modelType == 0) { // Random Circle
            auto circle = Model2DFactory::CreateCircle();
            circle->SetCenter(Coordinates2D(mouseX, mouseY));
            circle->SetRadius(50 + rand() % 50);
            circle->SetColor(randomColor);
            graphicsManager->AddShape(rand(), std::dynamic_pointer_cast<graphics::Model2D>(circle));
        }
        else if (modelType == 1) { // Random Rectangle
            auto rectangle = Model2DFactory::CreateRectangle();
            rectangle->SetUpperLeft(Coordinates2D(mouseX - 50 , mouseY - 50));
            rectangle->SetBottomRight(Coordinates2D(mouseX + 50 , mouseY + 50 ));
            rectangle->SetColor(randomColor);
            graphicsManager->AddShape(rand(), std::dynamic_pointer_cast<graphics::Model2D>(rectangle));
        }
        else if (modelType == 2) { // Random Line
            auto line = Model2DFactory::CreateLine();
            line->SetStartPoint(Coordinates2D(mouseX , mouseY ));
            line->SetEndPoint(Coordinates2D(mouseX + 100 , mouseY + 100));
            line->SetThickness(2 + rand() % 3);
            line->SetColor(randomColor);
            graphicsManager->AddShape(rand(), std::dynamic_pointer_cast<graphics::Model2D>(line));
        }
    }
}


// Default implementation of OnStart
void Engine::OnStart() {
    auto ctx = graphicsManager->GetGraphicsContext();
    ctx->SetSize(900, 900);
    ctx->SetTitle("Window");
    auto configs = graphics::GfxConfig({ FLAG_WINDOW_RESIZABLE, FLAG_VSYNC_HINT, FLAG_WINDOW_HIGHDPI, FLAG_MSAA_4X_HINT });
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
    graphicsManager->Clear(BLACK);
}
