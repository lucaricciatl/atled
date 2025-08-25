#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include <memory>
#include "IKeyboard.hpp"
#include "IMouse.hpp"
#include "IKeyboard.hpp"
#include "IMouse.hpp"
#include "MouseFactory.hpp"
#include "KeyboardFactory.hpp"
#include "queue"
#include "Key.hpp"
namespace input {
    

class InputManager {
public:
    InputManager();
    InputManager(KeyboardType keyboardType, MouseType mouseType);
    ~InputManager();

    // Initialize and shutdown functions to start and stop input processing
    void Init();
    void Shutdown();

    // Update function to be called in the main loop to poll inputs
    void Update();

    // Keyboard functions
    bool IsKeyPressed(int key) const;
    bool IsKeyPressedRepeat(int key) const;
    bool IsKeyDown(int key) const;
    bool IsKeyReleased(int key) const;
    bool IsKeyUp(int key) const;
    int GetKeyPressed() const;
    int GetCharPressed() const;
    std::queue<int> GetPressedKeys();

    // Mouse functions
    void ShowCursor() const;
    void HideCursor() const;
    bool IsCursorHidden() const;
    void EnableCursor() const;
    void DisableCursor() const;
    bool IsCursorOnScreen() const;

    bool IsMouseButtonPressed(int button) const;
    bool IsMouseButtonDown(int button) const;
    bool IsMouseButtonReleased(int button) const;
    bool IsMouseButtonUp(int button) const;
    //bool IsHardEscapeCombinationEnabled(){} const;
    float GetMouseDeltaX() const;
    float GetMouseDeltaY() const;

    int GetMouseX() const;
    int GetMouseY() const;
    MousePosition GetMousePosition() const;
    MousePosition GetMouseDelta() const;
    void SetMousePosition(int x, int y);
    void SetMouseOffset(int offsetX, int offsetY);
    void SetMouseScale(float scaleX, float scaleY);

    float GetMouseWheelMove() const;
    MousePosition GetMouseWheelMoveV() const;
    void SetMouseCursor(int cursor);

private:
    std::unique_ptr<IKeyboard> keyboardInput;
    std::unique_ptr<IMouse> mouseInput;
    void UpdateKeyStates();

};

} // namespace input

#endif // INPUTMANAGER_HPP
