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
#include <EngineBuilder.hpp>
#include <FreeCameraComponent.hpp>
#include <RigidBodyComponent.hpp>

int main() {
    // Engine setup
    engine::EngineBuilder<AtledEngine> builder;

    std::unique_ptr<AtledEngine> coreEngine = builder
        .SetKeyboardType(input::KeyboardType::Raylib)
        .SetMouseType(input::MouseType::Raylib)
        .SetGraphicsType(graphics::GraphicsType::Raylib)
        .SetCameraType(graphics::CameraType::Raylib)
        .SetWorldType(graphics::WorldType::World3D)
        .SetTargetFramerate(60) // Set frame rate suitable for the game speed
        .Build();

    auto entity = coreEngine->CreateEntity();
    auto mc = entity->AddComponent<ShapeComponent>();
    mc->SetModel<Plane>(Vector3(0, -0.1, 0), Vector2(10, 10), Color(255, 255, 255, 180));
    auto shapephisic = entity->AddComponent<RigidBodyComponent>();
    shapephisic->SetCollidable(true);
    shapephisic->SetStatic(true);

    auto entity2 = coreEngine->CreateEntity();
    entity2->GetComponent<FrameComponent>()->SetPosition(0, 2, 0);
    auto mc1 = entity2->AddComponent<ShapeComponent>();
    mc1->SetModel<Sphere>(0.5, Vector3(0, 0, 0), 10, 10, Color(255, 255, 255, 180));
    auto shapephisic1 = entity2->AddComponent<RigidBodyComponent>();
    shapephisic1->SetCollidable(true);
    shapephisic1->SetUseGravity(true);
    //auto mc2 = entity->AddComponent<WorldComponent>();
    // Run the engine in the main thread
    auto entitycam = coreEngine->CreateEntity();
    entitycam->AddComponent<FreeCameraComponent>();
    coreEngine->Start();

    coreEngine->Shutdown();

    return 0;
}

