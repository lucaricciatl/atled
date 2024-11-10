#include "engine.hpp"
#include "CoreEngine.hpp"
#include "InputManager.hpp"
#include "Model2DFactory.hpp"
#include "Model3DFactory.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib> // For rand()
#include <mutex>
#include "Sphere.hpp"

using namespace graphics;
using namespace input;

std::mutex graphicsMutex; // Mutex to protect graphicsManager access
bool running = true; // Flag to control the input thread

// Default implementation of OnUpdate
void Engine::OnUpdate() {

    if (inputManager->IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        int mouseX = inputManager->GetMouseX();
        int mouseY = inputManager->GetMouseY();
        int modelType = rand() % 4; // Extend range to 4 to include 3D sphere
        Color randomColor(rand() % 256, rand() % 256, rand() % 256, 128);

        std::lock_guard<std::mutex> lock(graphicsMutex); // Lock graphicsManager for thread-safe access
        if (modelType == 0) { // Random Circle
            auto circle = Model2DFactory::CreateCircle();
            circle->SetCenter(Coordinates2D(mouseX, mouseY));
            circle->SetRadius(50 + rand() % 50);
            circle->SetColor(randomColor);
            graphicsManager->AddCircle(rand(), circle);
        }
        else if (modelType == 1) { // Random Rectangle
            auto rectangle = Model2DFactory::CreateRectangle();
            rectangle->SetUpperLeft(Coordinates2D(mouseX - 50, mouseY - 50));
            rectangle->SetBottomRight(Coordinates2D(mouseX + 50, mouseY + 50));
            rectangle->SetColor(randomColor);
            graphicsManager->AddRectangle(rand(), rectangle);
        }
        else if (modelType == 2) { // Random Line
            auto line = Model2DFactory::CreateLine();
            line->SetStartPoint(Coordinates2D(mouseX, mouseY));
            line->SetEndPoint(Coordinates2D(mouseX + 100, mouseY + 100));
            line->SetThickness(2 + rand() % 3);
            line->SetColor(randomColor);
            graphicsManager->AddLine(rand(), line);
        }
        else { // Random Sphere (3D)
            auto sphere = Model3DFactory::CreateSphere();
            sphere->SetCenterPos({ static_cast<float>(mouseX), static_cast<float>(mouseY), -2.0f }); // Set a default Z position
            sphere->SetRadius(20.0f + rand() % 30); // Random radius between 20 and 50
            sphere->SetColor(randomColor);
            graphicsManager->AddSphere(rand(), sphere);
        }
    }
}

// Default implementation of OnStart
void Engine::OnStart() {
    auto ctx = graphicsManager->GetGraphicsContext();
    ctx->SetSize(900, 900);
    ctx->SetTitle("Window");
    auto configs = graphics::GfxConfig({ FLAG_WINDOW_RESIZABLE, FLAG_VSYNC_HINT, FLAG_WINDOW_HIGHDPI, FLAG_MSAA_4X_HINT });
    graphicsManager->SetConfigs(configs);
    ctx->InitWindowManager();
}

// Default implementation of OnShutdown
void Engine::OnShutdown() {
    std::cout << "Performing engine shutdown tasks..." << std::endl;
}

// Default implementation of OnRender
void Engine::OnRender() {
    std::lock_guard<std::mutex> lock(graphicsMutex); // Lock during rendering
    graphicsManager->Render();
}
