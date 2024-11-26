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
    for (int key = 0; key <= 255; ++key) { // Adjust the range as needed
        previousKeyStates[key] = false;
    }
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
    // Update the input manager (if necessary)
    inputManager->Update();

    // Iterate through all possible key codes
    for (int key = 0; key <= 255; ++key) { // Adjust the range as needed
        bool isCurrentlyDown = inputManager->IsKeyDown(key);
        bool wasPreviouslyDown = previousKeyStates[key];

        bool pressed = !wasPreviouslyDown && isCurrentlyDown;
        bool released = wasPreviouslyDown && !isCurrentlyDown;
        bool down = isCurrentlyDown;
        bool up = !isCurrentlyDown;

        if (pressed || released) {
            // Map integer key code to Key enum
            Key keyEnum = static_cast<Key>(key);
            if (keyEnum == Key::KEY_NULL) continue;

            InputEvent event(keyEnum, pressed, released, down, up);
            eventBus->Publish(event);
        }

        previousKeyStates[key] = isCurrentlyDown;
    }
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