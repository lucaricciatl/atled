#include "input.hpp"

namespace core{
namespace input {

bool IsKeyPressed(int key) {
    return ::IsKeyPressed(key);  // Calls Raylib's IsKeyPressed
}

bool IsKeyPressedRepeat(int key) {
    return ::IsKeyPressed(key);  // This is dependent on the platform, keeping as placeholder
}

bool IsKeyDown(int key) {
    return ::IsKeyDown(key);  // Calls Raylib's IsKeyDown
}

bool IsKeyReleased(int key) {
    return ::IsKeyReleased(key);  // Calls Raylib's IsKeyReleased
}

bool IsKeyUp(int key) {
    return ::IsKeyUp(key);  // Calls Raylib's IsKeyUp
}

int GetKeyPressed(void) {
    return ::GetKeyPressed();  // Calls Raylib's GetKeyPressed
}

int GetCharPressed(void) {
    return ::GetCharPressed();  // Calls Raylib's GetCharPressed
}

void SetExitKey(int key) {
    ::SetExitKey(key);  // Calls Raylib's SetExitKey
}

} // namespace input


namespace input {

bool IsGamepadAvailable(int gamepad) {
    return ::IsGamepadAvailable(gamepad);  // Calls Raylib's IsGamepadAvailable
}

const char* GetGamepadName(int gamepad) {
    return ::GetGamepadName(gamepad);  // Calls Raylib's GetGamepadName
}

bool IsGamepadButtonPressed(int gamepad, int button) {
    return ::IsGamepadButtonPressed(gamepad, button);  // Calls Raylib's IsGamepadButtonPressed
}

bool IsGamepadButtonDown(int gamepad, int button) {
    return ::IsGamepadButtonDown(gamepad, button);  // Calls Raylib's IsGamepadButtonDown
}

bool IsGamepadButtonReleased(int gamepad, int button) {
    return ::IsGamepadButtonReleased(gamepad, button);  // Calls Raylib's IsGamepadButtonReleased
}

bool IsGamepadButtonUp(int gamepad, int button) {
    return ::IsGamepadButtonUp(gamepad, button);  // Calls Raylib's IsGamepadButtonUp
}

int GetGamepadButtonPressed(void) {
    return ::GetGamepadButtonPressed();  // Calls Raylib's GetGamepadButtonPressed
}

int GetGamepadAxisCount(int gamepad) {
    return ::GetGamepadAxisCount(gamepad);  // Calls Raylib's GetGamepadAxisCount
}

float GetGamepadAxisMovement(int gamepad, int axis) {
    return ::GetGamepadAxisMovement(gamepad, axis);  // Calls Raylib's GetGamepadAxisMovement
}

int SetGamepadMappings(const char* mappings) {
    return ::SetGamepadMappings(mappings);  // Calls Raylib's SetGamepadMappings
}

void SetGamepadVibration(int gamepad, float leftMotor, float rightMotor) {
    ::SetGamepadVibration(gamepad, leftMotor, rightMotor);  // Calls Raylib's SetGamepadVibration
}

} // namespace input

namespace input {

bool IsMouseButtonPressed(int button) {
    return ::IsMouseButtonPressed(button);  // Calls Raylib's IsMouseButtonPressed
}

bool IsMouseButtonDown(int button) {
    return ::IsMouseButtonDown(button);  // Calls Raylib's IsMouseButtonDown
}

bool IsMouseButtonReleased(int button) {
    return ::IsMouseButtonReleased(button);  // Calls Raylib's IsMouseButtonReleased
}

bool IsMouseButtonUp(int button) {
    return ::IsMouseButtonUp(button);  // Calls Raylib's IsMouseButtonUp
}

int GetMouseX(void) {
    return ::GetMouseX();  // Calls Raylib's GetMouseX
}

int GetMouseY(void) {
    return ::GetMouseY();  // Calls Raylib's GetMouseY
}

Vector2 GetMousePosition(void) {
    return ::GetMousePosition();  // Calls Raylib's GetMousePosition
}

Vector2 GetMouseDelta(void) {
    return ::GetMouseDelta();  // Calls Raylib's GetMouseDelta
}

void SetMousePosition(int x, int y) {
    ::SetMousePosition(x, y);  // Calls Raylib's SetMousePosition
}

void SetMouseOffset(int offsetX, int offsetY) {
    ::SetMouseOffset(offsetX, offsetY);  // Calls Raylib's SetMouseOffset
}

void SetMouseScale(float scaleX, float scaleY) {
    ::SetMouseScale(scaleX, scaleY);  // Calls Raylib's SetMouseScale
}

float GetMouseWheelMove(void) {
    return ::GetMouseWheelMove();  // Calls Raylib's GetMouseWheelMove
}

Vector2 GetMouseWheelMoveV(void) {
    return ::GetMouseWheelMoveV();  // Calls Raylib's GetMouseWheelMoveV
}

void SetMouseCursor(int cursor) {
    ::SetMouseCursor(cursor);  // Calls Raylib's SetMouseCursor
}

} // namespace input


namespace input {

int GetTouchX(void) {
    return ::GetTouchX();  // Calls Raylib's GetTouchX
}

int GetTouchY(void) {
    return ::GetTouchY();  // Calls Raylib's GetTouchY
}

Vector2 GetTouchPosition(int index) {
    return ::GetTouchPosition(index);  // Calls Raylib's GetTouchPosition
}

int GetTouchPointId(int index) {
    return ::GetTouchPointId(index);  // Calls Raylib's GetTouchPointId
}

int GetTouchPointCount(void) {
    return ::GetTouchPointCount();  // Calls Raylib's GetTouchPointCount
}

void ShowCursor(void) {
    ::ShowCursor();  // Calls Raylib's ShowCursor
}

void HideCursor(void) {
    ::HideCursor();  // Calls Raylib's HideCursor
}

bool IsCursorHidden(void) {
    return ::IsCursorHidden();  // Calls Raylib's IsCursorHidden
}

void EnableCursor(void) {
    ::EnableCursor();  // Calls Raylib's EnableCursor
}

void DisableCursor(void) {
    ::DisableCursor();  // Calls Raylib's DisableCursor
}

bool IsCursorOnScreen(void) {
    return ::IsCursorOnScreen();  // Calls Raylib's IsCursorOnScreen
}

} // namespace input


namespace input {

void SetGesturesEnabled(unsigned int flags) {
    ::SetGesturesEnabled(flags);  // Calls Raylib's SetGesturesEnabled
}

bool IsGestureDetected(unsigned int gesture) {
    return ::IsGestureDetected(gesture);  // Calls Raylib's IsGestureDetected
}

int GetGestureDetected(void) {
    return ::GetGestureDetected();  // Calls Raylib's GetGestureDetected
}

float GetGestureHoldDuration(void) {
    return ::GetGestureHoldDuration();  // Calls Raylib's GetGestureHoldDuration
}

Vector2 GetGestureDragVector(void) {
    return ::GetGestureDragVector();  // Calls Raylib's GetGestureDragVector
}

float GetGestureDragAngle(void) {
    return ::GetGestureDragAngle();  // Calls Raylib's GetGestureDragAngle
}

Vector2 GetGesturePinchVector(void) {
    return ::GetGesturePinchVector();  // Calls Raylib's GetGesturePinchVector
}

float GetGesturePinchAngle(void) {
    return ::GetGesturePinchAngle();  // Calls Raylib's GetGesturePinchAngle
}

} // namespace input
}