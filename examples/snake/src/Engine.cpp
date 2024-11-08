#include "engine.hpp"
#include "CoreEngine.hpp"
#include <iostream>
#include <thread>
#include <chrono>

using namespace graphics;

// Default implementation of OnUpdate
void  Engine::OnUpdate() {
    // Default behavior for update
    std::cout << "Updating engine state..." << std::endl;
    // Placeholder for game logic or engine state updates
}

// Default implementation of OnShutdown
void Engine::OnShutdown() {
    std::cout << "Performing engine shutdown tasks..." << std::endl;
    // Placeholder for cleanup or resource deallocation
}

// Default implementation of OnStart
void Engine::OnStart() {
    auto ctx = graphicsManager->GetGraphicsContext();
    ctx->SetSize(900, 900);
    ctx->SetTitle("Window");
    auto configs = graphics::GfxConfig({ FLAG_WINDOW_RESIZABLE, FLAG_VSYNC_HINT,
                                        FLAG_WINDOW_HIGHDPI, FLAG_MSAA_4X_HINT });
    graphicsManager->SetConfigs(configs);
    ctx->InitWindowManager();

    auto arc = Model2DFactory::CreateArc();
    arc->SetCenter(Coordinates2D(200, 200));
    arc->SetStartAngle(-180);
    arc->SetEndAngle(0);
    arc->SetRadius(100);
    arc->SetThickness(12);
    auto col = Color(244, 244, 9, 50);
    arc->SetColor(col);
    graphicsManager->AddArc(1, arc);

    auto circle = Model2DFactory::CreateCircle();
    circle->SetCenter(Coordinates2D(200, 400));
    circle->SetRadius(100);
    circle->SetColor(col);
    graphicsManager->AddCircle(2, circle);

    auto rectangle = Model2DFactory::CreateRectangle();
    rectangle->SetUpperLeft(Coordinates2D(200, 700));
    rectangle->SetBottomRight(Coordinates2D(400, 900));
    rectangle->SetColor(col);
    rectangle->SetRotation(20);
    graphicsManager->AddRectangle(3, rectangle);

    auto line = Model2DFactory::CreateLine();
    line->SetStartPoint(Coordinates2D(500, 500));
    line->SetColor(col);
    line->SetEndPoint(Coordinates2D(500, 600));
    line->SetThickness(3);
    graphicsManager->AddLine(4, line);
}

void Engine::OnRender() {
    graphicsManager->Render();
}
