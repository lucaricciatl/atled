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

int main() {
    // Engine setup
    engine::EngineBuilder<AtledEngine> builder;

    std::unique_ptr<AtledEngine> coreEngine = builder.Configure().Build();

    auto entity = coreEngine->CreateEntity();
    auto mc = entity->AddComponent<ShapeComponent>();
    mc->SetModel<Plane>(math::Vector3(0, -0.1, 0), Vector2(10, 10), graphics::getColor("Timeless Gray"));
    // auto mc2 = entity->AddComponent<WorldComponent>();
    // Run the engine in the main thread
    auto entitycam = coreEngine->CreateEntity();
    entitycam->AddComponent<FreeCameraComponent>();
    coreEngine->Start();

    coreEngine->Shutdown();

    return 0;
}
