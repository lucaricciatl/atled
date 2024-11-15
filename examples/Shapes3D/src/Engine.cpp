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

    // Existing model creation logic
    if (inputManager->IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        int mouseX = inputManager->GetMouseX();
        int mouseY = inputManager->GetMouseY();
        cameraManager->SetFovy(45);
        int modelType = rand() % 4; // Extend range to 4 to include 3D sphere
        Color randomColor(rand() % 256, rand() % 256, rand() % 256, 128);

            auto cube = Model3DFactory::CreateCube();
            cube->SetCenterPos({ 0, 0,-5.0f }); // Set a default Z position
            graphicsManager->AddCube(rand(), cube);
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
