#include <AtledEngine.hpp>
#include <EngineBuilder.hpp>
#include <Frame.hpp>
#include <FrameComponent.hpp>
#include <FreeCameraComponent.hpp>
#include <Palette.hpp>
#include <ShapeComponent.hpp>
#include <atomic>
#include <iostream>
#include <mutex>
#include <random>
#include <thread>
#include <vector>
#include "ForceFieldComponent.hpp"
#include "ParticlesSystemComponent.hpp"

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
    auto mc = entity->AddComponent<ParticlesSystemComponent>();
    mc->SetParticleLifetime(10);
    mc->SetParticleStartSize(0.08);
    mc->SetNumberOfParticles(5000);
    auto entity2 = coreEngine->CreateEntity();
    entity2->GetComponent<FrameComponent>()->SetPosition(0,0,20);
    auto mc2 = entity2->AddComponent<GravitationalFieldComponent>();
    mc2->SetStrength(70);
    mc2->SetRadius(1);
    mc2->AddEntitiesFromList(entity->GetChildren());
    auto entitycam = coreEngine->CreateEntity();
    entitycam->AddComponent<FreeCameraComponent>();
    coreEngine->Start();

    coreEngine->Shutdown();

    return 0;
}
