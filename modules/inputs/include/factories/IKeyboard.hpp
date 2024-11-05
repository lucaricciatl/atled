#ifndef KEYBOARDINPUTINTERFACE_HPP
#define KEYBOARDINPUTINTERFACE_HPP

namespace input {

class IKeyboard {
public:
    virtual ~IKeyboard() = default;

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
};

} // namespace input

#endif // KEYBOARDINPUTINTERFACE_HPP
