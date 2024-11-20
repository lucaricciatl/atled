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

    // Create a thread to run the Update logic
    updateThread = std::thread([this]() {
        while (isRunning) {
            float deltaTime = GetDeltaTime();
            Update(deltaTime);
        }
        });
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
    // Update the InputManager to process current input states
    inputManager->Update();

    // Get the list of keys that changed state this frame
    std::queue<int> keysChanged = inputManager->GetPressedKeys();

    // Process each key in the queue
    while (!keysChanged.empty()) {
        int key = keysChanged.front();
        keysChanged.pop(); // Remove the processed key from the queue

        bool pressed = inputManager->IsKeyPressed(key);
        bool released = inputManager->IsKeyReleased(key);
        bool down = inputManager->IsKeyDown(key);
        bool up = inputManager->IsKeyUp(key);

        // Only generate events for meaningful changes
        if (pressed || released) {
            InputEvent event(static_cast<Key>(key), pressed, released, down, up);
            eventBus->Publish(event);
        }
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