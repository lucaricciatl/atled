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
#include "Text.hpp"
#include "Light.hpp"
#include "LightComponent.hpp"
#include "Palette.hpp"
#include "GuiBoxComponent.hpp"
#include "Main.h"
#include "ComputerUse.hpp"

// Example GUI setup function
void SetupGUI(AtledEngine* engine) {
    // Create an entity for our GUI element
    auto guiEntity = engine->CreateEntity();
    
    // Add frame component for positioning
    auto frameComp = guiEntity->AddComponent<FrameComponent>();
    
    // Add GUI box component
    auto guiBox = guiEntity->AddComponent<GuiBoxComponent>();
    // Configure the GUI box
    guiBox->SetSize(1920.0f-6, 1080.0f-6);
    guiBox->SetPosition({3.0f, 3.0f});
    guiBox->SetBackgroundColor(graphics::Color(0.0, 0.0, 0.0, 0.0));
    guiBox->SetBorderColor(graphics::Color(1, 0.255, 0.255, 0.5));
    guiBox->SetBorderThickness(3.0f);
    guiBox->SetCornerRadius(0.0f);
}

void SetupComputerUSe(AtledEngine* engine) {
    // Create an entity for our GUI element
    auto ComputerUseEntity = engine->CreateEntity();
    ComputerUseEntity->AddComponent<ComputerUse>();
    
}

int main() {
    // Engine setup
    engine::EngineBuilder<AtledEngine> builder;
    std::unique_ptr<AtledEngine> coreEngine = builder.Configure().Build();

    // Setup GUI elements
    SetupGUI(coreEngine.get());

    SetupComputerUSe(coreEngine.get());
    // Start the engine
    coreEngine->Start();
    
    // Cleanup and shutdown
    coreEngine->Shutdown();

    return 0;
}
