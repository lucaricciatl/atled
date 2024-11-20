#include "InputSystem.hpp"
#include "InputEvent.hpp"
#include "Key.hpp"
#include <thread>
#include <atomic>
#include <queue>
#include <iostream>

InputSystem::InputSystem(input::InputManager* inputMgr, EventBus* eventBus)
    : inputManager(inputMgr), eventBus(eventBus), isRunning(false) {
}

void InputSystem::Start() {
    isRunning = true;
}

void InputSystem::Init() {
    inputManager->Init();
    Start();
}

void InputSystem::Stop() {
    isRunning = false;
    if (updateThread.joinable()) {
        updateThread.join(); // Ensure the thread finishes execution
    }
}

void InputSystem::Update(float deltaTime) {

}

float InputSystem::GetDeltaTime() {
    static auto lastTime = std::chrono::high_resolution_clock::now();
    auto currentTime = std::chrono::high_resolution_clock::now();
    float deltaTime = std::chrono::duration<float>(currentTime - lastTime).count();
    lastTime = currentTime;
    return deltaTime;
}

InputSystem::~InputSystem() {
    Stop(); // Ensure the thread stops before destruction
}