#ifndef KEYBOARDINPUT_HPP
#define KEYBOARDINPUT_HPP

#include "IKeyboard.hpp"
#include <thread>
#include <atomic>
#include <mutex>
#include <queue>
#include <vector>

namespace input {

class RaylibKeyboard : public IKeyboard {
public:
    RaylibKeyboard();

    // Override functions from the interface
    void Start() override;
    void Stop() override;
    void Update() override;

    bool IsKeyPressed(int key) override;
    bool IsKeyPressedRepeat(int key) override;
    bool IsKeyDown(int key) override;
    bool IsKeyReleased(int key) override;
    bool IsKeyUp(int key) override;
    int GetKeyPressed() override;
    int GetCharPressed() override;
    std::queue<int> GetPressedKeys() override;

private:
    void ProcessingThread();

    std::thread processingThread;
    std::atomic<bool> running;

    std::mutex keyStateMutex;
    std::vector<bool> keyStates;
    std::vector<bool> prevKeyStates;
    std::vector<bool> keyStatesBuffer;

    std::mutex keyQueueMutex;
    std::queue<int> keyQueue;

    std::mutex charQueueMutex;
    std::queue<int> charQueue;
};

} // namespace input

#endif // KEYBOARDINPUT_HPP
