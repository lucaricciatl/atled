// CoreEngine.cpp
#include "CoreEngine.hpp"

#include <ResourceManager.hpp>
#include <iostream>
#include <memory>

#include "PhysicsManager.hpp"

namespace engine {
void CoreEngine::pollInput() {
    while (isRunning) {
        inputManager->Update();  // Poll inputs
    }
}

CoreEngine::CoreEngine(std::unique_ptr<input::InputManager> inputMgr,
                       std::unique_ptr<graphics::IGraphicManager> graphicsMgr,
                       std::shared_ptr<graphics::CameraManager> cameraMgr,
                       std::shared_ptr<resources::ResourceManager> resMgr,
                       std::shared_ptr<physics::PhysicsManager> physicsManager)
    : inputManager(std::move(inputMgr)), graphicsManager(std::move(graphicsMgr)), cameraManager(std::move(cameraMgr)) {}

void CoreEngine::Init() {
    inputManager->Init();  // Initialize input manager

    cameraManager->Start();
}

void CoreEngine::Start() {
    Init();
    OnStart();
    isRunning = true;
    // Start the input handling thread
    inputThread = std::make_unique<std::thread>(&CoreEngine::pollInput, this);
    EngineLoop();
}

void CoreEngine::Stop() { isRunning = false; }

void CoreEngine::Shutdown() {
    isRunning = false;  // Stop the input thread
    if (inputThread && inputThread->joinable()) {
        inputThread->join();  // Wait for the input thread to finish
    }
    OnShutdown();
}

void CoreEngine::EngineLoop() {
    while (isRunning) {
        OnUpdate();
        OnRender();
    }
}
}  // namespace engine
