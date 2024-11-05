#include "CoreEngine.hpp"

namespace core {

CoreEngine::CoreEngine(std::unique_ptr<input::InputManager> inputMgr /*, std::unique_ptr<graphics::GraphicsManager> graphicsMgr */)
    : inputManager(std::move(inputMgr))
    // , graphicsManager(std::move(graphicsMgr))
    , isRunning(false) {
}

CoreEngine::~CoreEngine() {
    Shutdown();
}

void CoreEngine::Initialize() {
    // Initialize input and graphics managers
    inputManager->Initialize();
    // graphicsManager->Initialize();
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
        // graphicsManager->Shutdown();
        inputManager->Shutdown();
        isRunning = false;
    }
}

void CoreEngine::MainLoop() {
    while (isRunning) {
        // Update input
        inputManager->Update();

        // Update game logic
        // ...

        // Render graphics
        // graphicsManager->Render();

        // Example: Check for exit condition (e.g., ESC key)
        if (inputManager->IsKeyPressed(KEY_ESCAPE)) {
            isRunning = false;
        }

        // Optionally add a small sleep or frame rate limiter
    }
}

} // namespace engine
