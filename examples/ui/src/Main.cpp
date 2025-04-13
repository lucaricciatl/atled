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
#include "GuiBoxComponent.hpp"
#include "Main.h"

// Example GUI setup function
void SetupGUI(AtledEngine* engine) {
    // Create an entity for our GUI element
    auto guiEntity = engine->CreateEntity();
    
    // Add frame component for positioning
    auto frameComp = guiEntity->AddComponent<FrameComponent>();
    
    // Add GUI box component
    auto guiBox = guiEntity->AddComponent<GuiBoxComponent>();
    
    // Configure the GUI box
    guiBox->SetSize(900.0f, 100.0f);
    guiBox->SetPosition({100.0f, 200.0f});
    guiBox->SetBackgroundColor(graphics::Color(0.255, 0.255, 0.255, 0.255));
    guiBox->SetBorderColor(graphics::Color(0.255, 0.255, 0.255, 0.255));
    guiBox->SetBorderThickness(3.0f);
    guiBox->SetCornerRadius(5.0f);
}

int main() {
    // Engine setup
    engine::EngineBuilder<AtledEngine> builder;
    std::unique_ptr<AtledEngine> coreEngine = builder.Configure().Build();

    // Setup GUI elements
    SetupGUI(coreEngine.get());

    // Start the engine
    coreEngine->Start();
    
    // Cleanup and shutdown
    coreEngine->Shutdown();

    return 0;
}
