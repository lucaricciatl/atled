#include <AtledEngine.hpp>
#include <ShapeComponent.hpp>
#include <FrameComponent.hpp>
#include <Frame.hpp>
#include <random>
#include <vector>
#include <thread>
#include <atomic>
#include <iostream>
#include <mutex>

// NBodySimulation class declaration (assumed to exist)
#include "NBodySimulation.hpp"
#include <EngineBuilder.hpp>
#include <FreeCameraComponent.hpp>
#include "raylib.hpp"

int main() {
    // Engine setup
    engine::EngineBuilder<AtledEngine> builder;

    std::unique_ptr<AtledEngine> coreEngine = builder
        .SetKeyboardType(input::KeyboardType::Raylib)
        .SetMouseType(input::MouseType::Raylib)
        .SetGraphicsType(graphics::GraphicsType::Raylib)
        .SetCameraType(graphics::CameraType::Raylib)
        .SetWorldType(graphics::WorldType::World2D)
        .SetTargetFramerate(60) // Set frame rate suitable for the game speed
        .Build();

    // Random number generator setup
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distX(0.0f, 200.0f); // Range for X positions
    std::uniform_real_distribution<float> distY(0.0f, 200.0f); // Range for Y positions
    std::uniform_real_distribution<float> distMass(1.0e12f, 1.0e14f); // Range for masses
    std::uniform_real_distribution<float> distColor(0, 1); // Range for RGB color values

    // List to store entities
    std::vector<std::shared_ptr<Entity>> entities;

    // Generate 50 entities with random positions and appearance
    for (int i = 0; i < 100; ++i) {
        auto entity = coreEngine->CreateEntity();

        // Add FrameComponent
        auto frameComponent = entity->AddComponent<FrameComponent>();
        if (frameComponent) {
            frameComponent->SetPosition(distX(gen), distY(gen), 0.0f); // Set random position
        }

        // Add ShapeComponent
        auto shapeComponent = entity->AddComponent<ShapeComponent>();
        if (shapeComponent) {
            shapeComponent->SetModel<Circle>();
            auto circle = shapeComponent->GetModel<Circle>();
            if (circle) {
                circle->SetRadius(2.0f); // Set a fixed radius for all entities
                circle->SetColor(graphics::Color(distColor(gen), distColor(gen), distColor(gen), 0.8)); // Set random color
            }
        }

        // Add entity to the list
        entities.push_back(entity);
    }

    // Print how many entities were created
    std::cout << "Created " << entities.size() << " entities." << std::endl;

    // Atomic flag to control simulation thread lifecycle
    std::atomic<bool> running = true;

    // Mutex for thread safety
    std::mutex entityMutex;

    // NBodySimulation instance
    NBodySimulation simulation(entities);

    // Simulation thread
    std::thread simulationThread([&]() {
        while (running) {
            {
                std::lock_guard<std::mutex> lock(entityMutex); // Protect shared resources
                simulation.Update(0.016f); // Update simulation with a fixed timestep (16ms)
            }
        }
        });
    // Run the engine in the main thread
    coreEngine->Start();

    // Stop simulation thread when engine stops
    running = false;
    if (simulationThread.joinable()) {
        simulationThread.join();
    }

    coreEngine->Shutdown();

    return 0;
}
