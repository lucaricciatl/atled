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
    guiBox->SetSize(200.0f, 100.0f);
    guiBox->SetPosition({100.0f, 100.0f});
    guiBox->SetBackgroundColor(graphics::Color(230, 230, 230, 255));
    guiBox->SetBorderColor(graphics::Color(50, 50, 50, 255));
    guiBox->SetBorderThickness(2.0f);
    guiBox->SetCornerRadius(5.0f);
}

// Example GUI creation function
void CreateTestGUI(AtledEngine* engine) {
    // Create multiple GUI elements for testing
    const int numBoxes = 3;
    const float spacing = 120.0f;
    
    for (int i = 0; i < numBoxes; i++) {
        auto entity = engine->CreateEntity();
        auto guiBox = entity->AddComponent<GuiBoxComponent>();
        
        // Configure each box with different properties
        guiBox->SetSize(100.0f, 100.0f);
        guiBox->SetPosition({50.0f + (spacing * i), 200.0f});
        
        // Set different colors for each box
        graphics::Color boxColor(
            50 + (i * 70),  // R
            100 + (i * 50), // G
            150 + (i * 30), // B
            255            // A
        );
        
        guiBox->SetBackgroundColor(boxColor);
        guiBox->SetBorderThickness(2.0f);
        guiBox->SetCornerRadius(5.0f * (i + 1));
    }
}

int main() {
    // Engine setup
    engine::EngineBuilder<AtledEngine> builder;
    std::unique_ptr<AtledEngine> coreEngine = builder.Configure().Build();

    // Setup GUI elements
    SetupGUI(coreEngine.get());
    
    // Create test GUI elements
    CreateTestGUI(coreEngine.get());

    // Start the engine
    coreEngine->Start();
    
    // Cleanup and shutdown
    coreEngine->Shutdown();

    return 0;
}
