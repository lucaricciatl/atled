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
#include <cmath> // For sin and cos

void Engine::OnUpdate() {
    static float angle = 0.0f; // Angle of rotation in radians
    const float radius = 5.0f; // Distance from the object
    const float rotationSpeed = 0.0001f; // Speed of rotation

    // Update the angle to create rotation
    angle += rotationSpeed;

    // Calculate the new camera position based on the angle
    float x = radius * cos(angle);
    float y = radius * sin(angle);

    // Set the new camera position
    cameraManager->SetCameraPosition({x, y, 1}); // Keep Y constant for a horizontal rotation
    cameraManager->SetCameraTarget({0, 0, -5});    // Keep the target fixed on the object
}




// Default implementation of OnStart
void Engine::OnStart() {
    auto ctx = graphicsManager->GetGraphicsContext();
    ctx->SetSize(900, 900);
    ctx->SetTitle("Window");
    auto configs = graphics::GfxConfig({ FLAG_WINDOW_RESIZABLE, FLAG_VSYNC_HINT, FLAG_WINDOW_HIGHDPI, FLAG_MSAA_4X_HINT });
    graphicsManager->SetConfigs(configs);
    ctx->InitWindowManager();
    cameraManager->SetFovy(45);
    cameraManager->SetCameraProjection(CAMERA_PERSPECTIVE);
    int modelType = rand() % 4; // Extend range to 4 to include 3D sphere
    Color randomColor(rand() % 256, rand() % 256, rand() % 256, 128);
    Color col(2, 2, 2, 255);
    auto cube = Model3DFactory::CreateCube();
    cube->SetCenterPos({ 0, 0,-5.0f }); // Set a default Z position
    cube->EnableWireframe();
    cube->SetWireframeColor(col);

    graphicsManager->AddCube(rand(), cube);
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
