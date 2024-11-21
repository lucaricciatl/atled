#include "CameraManager.hpp"
#include "Component.hpp"
#include "AtledEngine.hpp"
#include "Entity.hpp"
#include "EngineBuilder.hpp"
#include "FrameComponent.hpp" // Include the FrameComponent
#include <memory>
#include "EventBus.hpp"

int main() {
    // Create the engine
    engine::EngineBuilder<AtledEngine> builder;

    std::unique_ptr<AtledEngine> coreEngine = builder
        .SetImplementation(engine::EngineImplementation::Raylib)
        .Build();

    // Create an entity and add components
    auto entity = coreEngine->CreateEntity();

    // Add a FrameComponent to the entity
    physics::Position defaultPosition(0.0, 0.0, 0.0);
    math::Quaternion defaultOrientation(1.0, 0.0, 0.0, 0.0);
    auto frameComponent = std::make_shared<FrameComponent>(
        entity.get(),
        defaultPosition, // Initial position (x, y, z)
        defaultOrientation // Initial orientation
    );

    // Start the engine (game loop begins)
    coreEngine->Start();

    return 0;
}
