#include "Keyboard.hpp"
#include "gfx.hpp"
#include "input.hpp"
#include <iostream>
#include <chrono>

namespace input{
KeyboardInput::KeyboardInput() : running(false), keyStates(512, false), prevKeyStates(512, false), keyStatesBuffer(512, false) {
}

KeyboardInput::~KeyboardInput() {
    Stop();
}

void KeyboardInput::Start() {
    if (!running.load()) {
        running = true;
        processingThread = std::thread(&KeyboardInput::ProcessingThread, this);
    }
}

void KeyboardInput::Stop() {
    if (running.load()) {
        running = false;
        if (processingThread.joinable()) {
            processingThread.join();
        }
    }
}

void KeyboardInput::Update() {
    // This method must be called from the main thread

    // Update prevKeyStates
    {
        std::lock_guard<std::mutex> lockState(keyStateMutex);
        prevKeyStates = keyStates;
    }

    // Update keyStatesBuffer with the current keyboard state
    for (int key = 0; key < 512; ++key) {
        keyStatesBuffer[key] = input::IsKeyDown(key);
    }

    // Update keyStates
    {
        std::lock_guard<std::mutex> lockState(keyStateMutex);
        keyStates = keyStatesBuffer;
    }

    // Get key presses and add to queue
    int keyPressed = input::GetKeyPressed();
    while (keyPressed != 0) {
        {
            std::lock_guard<std::mutex> lockQueue(keyQueueMutex);
            keyQueue.push(keyPressed);
        }
        keyPressed = input::GetKeyPressed();
    }

    // Get char presses and add to queue
    int charPressed = input::GetCharPressed();
    while (charPressed != 0) {
        {
            std::lock_guard<std::mutex> lockCharQueue(charQueueMutex);
            charQueue.push(charPressed);
        }
        charPressed = input::GetCharPressed();
    }

}

void KeyboardInput::ProcessingThread() {
  while (running.load()) {
    // Process queued characters
    Update();
    int character;
    while (true) {
      {
        std::lock_guard<std::mutex> lock(charQueueMutex);
        if (charQueue.empty()) {
          break;
        }
        character = charQueue.front();
        charQueue.pop();
      }
      // Print the character
      std::cout << static_cast<char>(character) << std::flush;
    }
  }
}

bool KeyboardInput::IsKeyPressed(int key) {
    std::lock_guard<std::mutex> lock(keyStateMutex);
    if (key >= 0 && key < static_cast<int>(keyStates.size())) {
        return (keyStates[key] && !prevKeyStates[key]);
    }
    return false;
}

bool KeyboardInput::IsKeyPressedRepeat(int key) {
    // Implement repeat logic if needed
    // For now, we'll treat it the same as IsKeyPressed
    return IsKeyPressed(key);
}

bool KeyboardInput::IsKeyDown(int key) {
    std::lock_guard<std::mutex> lock(keyStateMutex);
    if (key >= 0 && key < static_cast<int>(keyStates.size())) {
        return keyStates[key];
    }
    return false;
}

bool KeyboardInput::IsKeyReleased(int key) {
    std::lock_guard<std::mutex> lock(keyStateMutex);
    if (key >= 0 && key < static_cast<int>(keyStates.size())) {
        return (!keyStates[key] && prevKeyStates[key]);
    }
    return false;
}

bool KeyboardInput::IsKeyUp(int key) {
    return !IsKeyDown(key);
}

int KeyboardInput::GetKeyPressed() {
    std::lock_guard<std::mutex> lock(keyQueueMutex);
    if (!keyQueue.empty()) {
        int key = keyQueue.front();
        keyQueue.pop();
        return key;
    }
    return 0;
}

int KeyboardInput::GetCharPressed() {
    std::lock_guard<std::mutex> lock(charQueueMutex);
    if (!charQueue.empty()) {
        int character = charQueue.front();
        charQueue.pop();
        return character;
    }
    return 0;
}

}