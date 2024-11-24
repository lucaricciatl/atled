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




    // Start the engine (game loop begins)
    coreEngine->Start();

    return 0;
}
