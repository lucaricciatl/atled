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
    builder.SetTargetFramerate(100);
    std::unique_ptr<AtledEngine> coreEngine = builder.Configure().Build();

    auto entity = coreEngine->CreateEntity();
    auto mc = entity->AddComponent<ParticlesSystemComponent>();
    mc->SetParticleLifetime(6);
    mc->SetParticlesCollision(false);
    mc->SetParticleStartSize(0.01);
    mc->SetNumberOfParticles(10000);

    //mc2->AddEntitiesFromList(entity->GetChildren());
    auto entitycam = coreEngine->CreateEntity();
    entitycam->AddComponent<FreeCameraComponent>();
    coreEngine->Start();

    coreEngine->Shutdown();

    return 0;
}
