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

#include "Light.hpp"
#include "LightComponent.hpp"
#include "Palette.hpp"

int main() {
    // Engine setup
    engine::EngineBuilder<AtledEngine> builder;

    std::unique_ptr<AtledEngine> coreEngine = builder.Configure().Build();

    auto entity = coreEngine->CreateEntity();
    auto mc = entity->AddComponent<ShapeComponent>();
    mc->SetModel<Circle>();
    auto circle = mc->GetModel<Circle>();
    circle->SetCenter(Coordinates2D(400, 200));
    circle->SetRadius(70);
    circle->SetColor(getColor("Elegant Soft Gray"));
    coreEngine->Start();
    coreEngine->Shutdown();

    return 0;
}