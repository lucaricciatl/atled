#ifndef KEYBOARDINPUT_HPP
#define KEYBOARDINPUT_HPP

#include <thread>
#include <atomic>
#include <mutex>
#include <queue>
#include <vector>

class KeyboardInput {
public:
    KeyboardInput();
    ~KeyboardInput();

    // Start and stop the processing thread
    void Start();
    void Stop();

    // This method must be called from the main thread in your main loop
    void Update();

    // Input-related functions
    bool IsKeyPressed(int key);
    bool IsKeyPressedRepeat(int key);
    bool IsKeyDown(int key);
    bool IsKeyReleased(int key);
    bool IsKeyUp(int key);
    int GetKeyPressed();
    int GetCharPressed();

private:
    void ProcessingThread();

    std::thread processingThread;
    std::atomic<bool> running;

    // Double buffer for key states
    std::mutex keyStateMutex;
    std::vector<bool> keyStates;       // Current key states
    std::vector<bool> prevKeyStates;   // Previous key states
    std::vector<bool> keyStatesBuffer; // Buffer updated in Update()

    // Key and character queues
    std::mutex keyQueueMutex;
    std::queue<int> keyQueue;

    std::mutex charQueueMutex;
    std::queue<int> charQueue;

};

#endif // KEYBOARDINPUT_HPP
