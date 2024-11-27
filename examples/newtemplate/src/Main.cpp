#include "CameraManager.hpp"
#include "Component.hpp"
#include "AtledEngine.hpp"
#include "Entity.hpp"
#include "EngineBuilder.hpp"
#include "FrameComponent.hpp" // Include the FrameComponent
#include <memory>
#include "EventBus.hpp"
#include "ShapeComponent.hpp"
#include <Circle.hpp>
#include <Action.hpp>
#include <Bindings.hpp>
#include <FrameController.hpp>

int main() {
    // Create the engine
    engine::EngineBuilder<AtledEngine> builder;

    std::unique_ptr<AtledEngine> coreEngine = builder
        .SetImplementation(engine::EngineImplementation::Raylib)
        .Build();

    // Create an entity and add components
    auto entity = coreEngine->CreateEntity();
    entity->GetComponent<FrameComponent>()->GetFrame()->SetPosition(834, 343, 897);
    entity->AddComponent<ShapeComponent>();

    auto shape = entity->GetComponent<ShapeComponent>();
    shape->SetModel<Cube>();

    auto inputBindings = std::make_shared<Bindings>();

    inputBindings->BindKeyToAction(Key::KEY_W, Action::MoveForward);
    inputBindings->BindKeyToAction(Key::KEY_S, Action::MoveBackward);
    inputBindings->BindKeyToAction(Key::KEY_A, Action::MoveLeft);
    inputBindings->BindKeyToAction(Key::KEY_D, Action::MoveRight);


    entity->AddComponent<FrameController>();


    // Start the engine (game loop begins)
    coreEngine->Start();

    return 0;
}
