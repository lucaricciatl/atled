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

    std::unique_ptr<AtledEngine> coreEngine =
        builder.InitializeFromJsonFile("C:\\Users\\ricciluca\\dev\\ActiveStories\\atled\\config.json").Build();

    coreEngine->Start();
    coreEngine->Shutdown();

    return 0;
}
