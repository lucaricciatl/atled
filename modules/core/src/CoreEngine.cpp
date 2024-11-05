// CoreEngine.cpp
#include "CoreEngine.hpp"

namespace engine {

CoreEngine::CoreEngine(std::unique_ptr<input::InputManager> inputMgr, std::unique_ptr<graphics::IGraphicManager> graphicsMgr)
    : inputManager(std::move(inputMgr)),
      graphicsManager(std::move(graphicsMgr)),
      isRunning(false)
{
}

CoreEngine::~CoreEngine() {
    Shutdown();
}

void CoreEngine::Initialize() {
    // Initialize input and graphics managers
    inputManager->Initialize();
    graphicsManager->Init();

    isRunning = true;
}

void CoreEngine::Run() {
    if (!isRunning) {
        Initialize();
    }
    MainLoop();
}

void CoreEngine::Shutdown() {
    if (isRunning) {
        // Shutdown graphics and input managers
        inputManager->Shutdown();
        isRunning = false;
    }
}

void CoreEngine::MainLoop() {
    while (isRunning) {
        // Update input
        inputManager->Update();

        // Example: Handle input to control engine state
        if (inputManager->IsKeyPressed(KEY_ESCAPE)) {
            isRunning = false;
        }

        // Example: Add some rendering logic
        // graphicsManager->Clear(RAYWHITE);
        // ... Add drawing primitives ...

        // Optionally, include logic to synchronize with rendering thread
    }
}

} // namespace engine
