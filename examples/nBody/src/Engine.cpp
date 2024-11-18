#include "Engine.hpp"
#include "CoreEngine.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include "NBodySimulation.hpp"

using namespace graphics;




// Called at the start of the engine, initializes simulation and graphics setup
void Engine::OnStart() {
    std::cout << "Engine starting..." << std::endl;

    // Initialize bodies in the simulation
    auto ctx = graphicsManager->GetGraphicsContext();
    ctx->SetSize(900, 900);
    ctx->SetTitle("Window");
    auto configs = graphics::GraphicsConfig({ FLAG_WINDOW_RESIZABLE, FLAG_VSYNC_HINT,
                                        FLAG_WINDOW_HIGHDPI, FLAG_MSAA_4X_HINT });
    graphicsManager->SetConfigs(configs);
    ctx->InitWindowManager();

    simulation.InitializeBodies();

    // Add each circle from the simulation to the graphics manager once
    for (auto& circle : simulation.GetCircles()) {
        graphicsManager->AddShape(1, std::dynamic_pointer_cast<graphics::Model2D>(circle));  // Cast explicitly

    }

    std::cout << "Simulation initialized with " << simulation.GetCircles().size() << " bodies." << std::endl;
}


// Clean up resources when the engine shuts down
void Engine::OnShutdown() {
    std::cout << "Engine shutting down and cleaning up resources..." << std::endl;

    // Perform any cleanup if needed (e.g., deallocating resources, saving state, etc.)
}


// Updates simulation state every frame
void Engine::OnUpdate() {
    // Pan the camera using arrow keys or WASD
    if (inputManager->IsKeyDown(KEY_W)) {
        cameraManager->SetCameraTargetY(cameraManager->GetCameraTargetY() - 1); // Move view up
    }
    if (inputManager->IsKeyDown(KEY_S)) {
        cameraManager->SetCameraTargetY(cameraManager->GetCameraTargetY() + 1); // Move view down
    }
    if (inputManager->IsKeyDown(KEY_A)) {
        cameraManager->SetCameraTargetX(cameraManager->GetCameraTargetX() - 1); // Move view left
    }
    if (inputManager->IsKeyDown(KEY_D)) {
        cameraManager->SetCameraTargetX(cameraManager->GetCameraTargetX() + 1); // Move view right
    }

    // Zoom in/out with mouse wheel
    float mouseWheelMove = inputManager->GetMouseWheelMove();
    if (mouseWheelMove != 0.0f) {
        float currentZoom = cameraManager->GetCameraZoom();
        cameraManager->SetCameraZoom(currentZoom + mouseWheelMove * 0.1f);
    }

    // Update the simulation state
            // Apply target-based adjustments to objects
    float targetOffsetX = cameraManager->GetCameraTargetX();
    float targetOffsetY = cameraManager->GetCameraTargetY();


    simulation.Update(0.001);  // Update the simulation with deltaTime
    std::cout << "Simulation updated for deltaTime = " << 0.001 << std::endl;
}


void Engine::OnRender() {
    graphicsManager->Clear(::Color(0, 0, 0, 0));

    // Render all shapes
    graphicsManager->Render();

}

