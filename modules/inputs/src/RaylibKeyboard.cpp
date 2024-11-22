#include "RaylibKeyboard.hpp"
#include "raylib.hpp"
#include <iostream>
#include <chrono>

namespace input{
RaylibKeyboard::RaylibKeyboard() : running(false), keyStates(512, false), prevKeyStates(512, false), keyStatesBuffer(512, false) {
}

void RaylibKeyboard::Start() {
    if (running == false) {
        running = true;
        processingThread = std::thread(&RaylibKeyboard::ProcessingThread, this);
    }
}

void RaylibKeyboard::Stop() {
    if (running.load()) {
        running = false;
        if (processingThread.joinable()) {
            processingThread.join();
        }
    }
}

void RaylibKeyboard::Update() {
    // This method must be called from the main thread
    // Update prevKeyStates
    {
        std::lock_guard<std::mutex> lockState(keyStateMutex);
        prevKeyStates = keyStates;
    }

    // Update keyStatesBuffer with the current keyboard state
    for (int key = 0; key < 512; ++key) {
        keyStatesBuffer[key] = raylib::IsKeyDown(key);
    }

    // Update keyStates
    {
        std::lock_guard<std::mutex> lockState(keyStateMutex);
        keyStates = keyStatesBuffer;
    }

    // Get key presses and add to queue
    int keyPressed = raylib::GetKeyPressed();
    while (keyPressed != 0) {
        {
            std::lock_guard<std::mutex> lockQueue(keyQueueMutex);
            keyQueue.push(keyPressed);
        }
        keyPressed = raylib::GetKeyPressed();
    }

    // Get char presses and add to queue
    int charPressed = raylib::GetCharPressed();
    while (charPressed != 0) {
        {
            std::lock_guard<std::mutex> lockCharQueue(charQueueMutex);
            charQueue.push(charPressed);
            std::cout << charPressed << std::endl;
        }
        charPressed = raylib::GetCharPressed();

    }

}

void RaylibKeyboard::ProcessingThread() {
    while (running) {
        // Lock key state mutex to safely update key states
        Update();
    }
}

bool RaylibKeyboard::IsKeyPressed(int key) {
    std::lock_guard<std::mutex> lock(keyStateMutex);
    if (key >= 0 && key < static_cast<int>(keyStates.size())) {
        return (keyStates[key] && !prevKeyStates[key]);
    }
    return false;
}

bool RaylibKeyboard::IsKeyPressedRepeat(int key) {
    // Implement repeat logic if needed
    // For now, we'll treat it the same as IsKeyPressed
    return IsKeyPressed(key);
}

bool RaylibKeyboard::IsKeyDown(int key) {
    std::lock_guard<std::mutex> lock(keyStateMutex);
    if (key >= 0 && key < static_cast<int>(keyStates.size())) {
        return keyStates[key];
    }
    return false;
}

bool RaylibKeyboard::IsKeyReleased(int key) {
    std::lock_guard<std::mutex> lock(keyStateMutex);
    if (key >= 0 && key < static_cast<int>(keyStates.size())) {
        return (!keyStates[key] && prevKeyStates[key]);
    }
    return false;
}

bool RaylibKeyboard::IsKeyUp(int key) {
    return !IsKeyDown(key);
}

int RaylibKeyboard::GetKeyPressed() {
    std::lock_guard<std::mutex> lock(keyQueueMutex);
    if (!keyQueue.empty()) {
        int key = keyQueue.front();
        keyQueue.pop();
        return key;
    }
    return 0;
}

int RaylibKeyboard::GetCharPressed() {
    std::lock_guard<std::mutex> lock(charQueueMutex);
    if (!charQueue.empty()) {
        int character = charQueue.front();
        charQueue.pop();
        return character;
    }
    return 0;
}

std::queue<int> RaylibKeyboard::GetPressedKeys() {
    std::lock_guard<std::mutex> lock(keyQueueMutex);
    return keyQueue; // Return a copy of the queue
}

}