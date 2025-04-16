#include <AtledEngine.hpp>
#include <EngineBuilder.hpp>
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
#include "FixedCameraComponent.hpp"
#include "Palette.hpp"

int main() {
    // Engine setup
    engine::EngineBuilder<AtledEngine> builder;
    std::unique_ptr<AtledEngine> coreEngine = builder.Configure().Build();

    auto entity2 = coreEngine->CreateEntity();
    entity2->GetComponent<FrameComponent>()->SetPosition(0, 0, 0.0f);
    auto mc1 = entity2->AddComponent<ShapeComponent>();
    mc1->SetModel<Cube>();
    auto shapephisic1 = entity2->AddComponent<RigidBodyComponent>();
    shapephisic1->SetStatic(true);

    auto entitycam = coreEngine->CreateEntity();
    entitycam->AddComponent<FixedCameraComponent>();
    entitycam->GetComponent<FixedCameraComponent>()->SetPosition({5, 5, 5});
    entitycam->GetComponent<FixedCameraComponent>()->SetTarget({0, 0, 0});

    coreEngine->Start();
    coreEngine->Shutdown();

    return 0;
}
