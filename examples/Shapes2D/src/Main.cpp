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
#include "Main.h"

void createRandomShape(std::unique_ptr<AtledEngine> &coreEngine) {
    auto entity = coreEngine->CreateEntity();
    auto mc = entity->AddComponent<ShapeComponent>();

    // Random number generator setup
    std::random_device rd;
    std::mt19937 gen(rd());

    // Random shape type (0 = circle, 1 = rectangle)
    std::uniform_int_distribution<> shapeType(0, 1);

    // Random position distributions (assuming 800x600 window)
    std::uniform_int_distribution<> xPos(0, 800);
    std::uniform_int_distribution<> yPos(0, 600);

    // Random size distribution
    std::uniform_int_distribution<> size(30, 100);

    // Random color selection
    std::vector<std::string> colorNames = {
        "Soft Pink",     "Peach",      "Light Yellow",   "Mint Green", "Sky Blue",     "Lavender",
        "Lilac",         "Blush Pink", "Rose Pink",      "Coral",      "Soft Blue",    "Aqua",
        "Soft Purple",   "Lime Green", "Bubblegum Pink", "Bright Red", "Vivid Orange", "Sunflower Yellow",
        "Emerald Green", "Ocean Blue", "Royal Purple",   "Hot Pink"};

    std::uniform_int_distribution<> colorIndex(0, colorNames.size() - 1);

    if (shapeType(gen) == 0) {
        // Create Circle
        mc->SetModel<Circle>();
        auto circle = mc->GetModel<Circle>();
        circle->SetCenter(Coordinates2D(xPos(gen), yPos(gen)));
        circle->SetRadius(size(gen));
        circle->SetColor(getColor(colorNames[colorIndex(gen)]));
    } else {
        // Create Rectangle
        mc->SetModel<graphics::Rectangle>();
        auto rectangle = mc->GetModel<graphics::Rectangle>();
        int x = xPos(gen);
        int y = yPos(gen);
        int sizeVal = size(gen);
        rectangle->SetUpperLeft(Coordinates2D(x, y));
        rectangle->SetBottomRight(Coordinates2D(x + sizeVal, y + sizeVal));
        rectangle->SetColor(getColor(colorNames[colorIndex(gen)]));
    }
}

int main() {
    // Engine setup
    engine::EngineBuilder<AtledEngine> builder;
    std::unique_ptr<AtledEngine> coreEngine = builder.Configure().Build();

    // Create multiple random shapes
    const int NUM_SHAPES = 10;
    for (int i = 0; i < NUM_SHAPES; i++) {
        createRandomShape(coreEngine);
    }

    coreEngine->Start();
    coreEngine->Shutdown();

    return 0;
}
