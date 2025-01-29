#include <AtledEngine.hpp>
#include <Color.hpp>
#include <EngineBuilder.hpp>
#include <Frame.hpp>
#include <FrameComponent.hpp>
#include <FreeCameraComponent.hpp>
#include <RigidBodyComponent.hpp>
#include <ShapeComponent.hpp>
#include <atomic>
#include <iostream>
#include <mutex>
#include <random>
#include <thread>
#include <vector>
#include "LightComponent.hpp"
#include "Palette.hpp"
#include "Light.hpp"
int main() {
    // Engine setup
    engine::EngineBuilder<AtledEngine> builder;

    std::unique_ptr<AtledEngine> coreEngine = builder.SetKeyboardType(input::KeyboardType::Raylib)
                                                  .SetMouseType(input::MouseType::Raylib)
                                                  .SetGraphicsType(graphics::GraphicsType::Raylib)
                                                  .SetCameraType(graphics::CameraType::Raylib)
                                                  .SetWorldType(graphics::WorldType::World3D)
                                                  .SetTargetFramerate(60)  // Set frame rate suitable for the game speed
                                                  .Build();

    auto entity = coreEngine->CreateEntity();
    auto mc = entity->AddComponent<ShapeComponent>();

    mc->SetModel<Plane>(math::Vector3(0, 0, 0), Vector2(10, 10), getColor("Timeless Gray"));
    auto entity2 = coreEngine->CreateEntity();
    entity2->GetComponent<FrameComponent>()->SetPosition(0, 1, 0.0f);
    auto mc1 = entity2->AddComponent<ShapeComponent>();
    mc1->SetModel<Cube>();
    // auto mc2 = entity->AddComponent<WorldComponent>();
    // Run the engine in the main thread
    auto entity3 = coreEngine->CreateEntity();
    entity3->GetComponent<FrameComponent>()->SetPosition(1, 1, 0.0f);
    auto mc2 = entity3->AddComponent<LightComponent>();

    auto entitycam = coreEngine->CreateEntity();
    entitycam->AddComponent<FreeCameraComponent>();
    coreEngine->Start();
    coreEngine->Shutdown();

    return 0;
}
