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

#include "Palette.hpp"

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

    auto sphereEntity = coreEngine->CreateEntity();
    sphereEntity->GetComponent<FrameComponent>()->SetPosition(0, 2, 0.0f);
    auto sphere = sphereEntity->AddComponent<ShapeComponent>();
    sphere->SetModel<Sphere>();

    // sphere->SetMaterial("plastic grey");
    // sphere->SetShader("blur");

    // sphere->SetMaterial(material);
    // sphere->SetShader(shader);

    auto entitycam = coreEngine->CreateEntity();
    entitycam->AddComponent<FreeCameraComponent>();
    coreEngine->Start();
    coreEngine->Shutdown();

    return 0;
}
