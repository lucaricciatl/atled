#ifndef KEYBOARDINPUTINTERFACE_HPP
#define KEYBOARDINPUTINTERFACE_HPP
#include "queue"
namespace input {
enum class KeyboardType{
    Invalid,
    Raylib};

class IKeyboard {
public:
    // Start and stop the processing thread
    virtual void Start() = 0;
    virtual void Stop() = 0;

    // Update method to be called from the main thread
    virtual void Update() = 0;

    // Input-related functions
    virtual bool IsKeyPressed(int key) = 0;
    virtual bool IsKeyPressedRepeat(int key) = 0;
    virtual bool IsKeyDown(int key) = 0;
    virtual bool IsKeyReleased(int key) = 0;
    virtual bool IsKeyUp(int key) = 0;
    virtual int GetKeyPressed() = 0;
    virtual int GetCharPressed() = 0;
    virtual std::queue<int> GetPressedKeys() = 0;

};

} // namespace input

#endif // KEYBOARDINPUTINTERFACE_HPP
