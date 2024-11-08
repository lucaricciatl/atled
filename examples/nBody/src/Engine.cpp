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
    auto configs = graphics::GfxConfig({ FLAG_WINDOW_RESIZABLE, FLAG_VSYNC_HINT,
                                        FLAG_WINDOW_HIGHDPI, FLAG_MSAA_4X_HINT });
    graphicsManager->SetConfigs(configs);
    ctx->InitWindowManager();

    simulation.InitializeBodies();

    // Add each circle from the simulation to the graphics manager once
    for (const auto& circle : simulation.GetCircles()) {
        graphicsManager->AddCircle(1, circle);  // Add to layer 1
    }

    std::cout << "Simulation initialized with " << simulation.GetCircles().size() << " bodies." << std::endl;
}

// Updates simulation state every frame
void Engine::OnUpdate() {
    simulation.Update(0.02);  // Update the simulation with deltaTime

    std::cout << "Simulation updated for deltaTime = " << 0.02 << std::endl;
}

// Renders the current simulation state
void Engine::OnRender() {
    graphicsManager->Clear(::Color(0,0,0,0));
    graphicsManager->Render();  // Render all shapes (already added in OnStart)
}

// Clean up resources when the engine shuts down
void Engine::OnShutdown() {
    std::cout << "Engine shutting down and cleaning up resources..." << std::endl;

    // Perform any cleanup if needed (e.g., deallocating resources, saving state, etc.)
}
