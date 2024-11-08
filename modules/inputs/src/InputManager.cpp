#include "InputManager.hpp"

namespace input {

InputManager::InputManager(KeyboardType keyboardType, MouseType mouseType) {
    // Create keyboard and mouse inputs based on the specified types
    keyboardInput = KeyboardFactory::CreateKeyboardInput();
    mouseInput = MouseFactory::CreateMouse();
}

InputManager::~InputManager() {
    Shutdown();
}

InputManager::InputManager() {};

void InputManager::Init() {
    keyboardInput->Start();
    mouseInput->Start();
}

void InputManager::Shutdown() {
    keyboardInput->Stop();
    mouseInput->Stop();
}

void InputManager::Update() {
    keyboardInput->Update();
}

// Keyboard functions
bool InputManager::IsKeyPressed(int key) const {
    return keyboardInput->IsKeyPressed(key);
}

bool InputManager::IsKeyPressedRepeat(int key) const {
    return keyboardInput->IsKeyPressedRepeat(key);
}

bool InputManager::IsKeyDown(int key) const {
    return keyboardInput->IsKeyDown(key);
}

bool InputManager::IsKeyReleased(int key) const {
    return keyboardInput->IsKeyReleased(key);
}

bool InputManager::IsKeyUp(int key) const {
    return keyboardInput->IsKeyUp(key);
}

int InputManager::GetKeyPressed() const {
    return keyboardInput->GetKeyPressed();
}

int InputManager::GetCharPressed() const {
    return keyboardInput->GetCharPressed();
}

// Mouse functions
void InputManager::ShowCursor() const {
    mouseInput->ShowCursor();
}

void InputManager::HideCursor() const {
    mouseInput->HideCursor();
}

bool InputManager::IsCursorHidden() const {
    return mouseInput->IsCursorHidden();
}

void InputManager::EnableCursor() const {
    mouseInput->EnableCursor();
}

void InputManager::DisableCursor() const {
    mouseInput->DisableCursor();
}

bool InputManager::IsCursorOnScreen() const {
    return mouseInput->IsCursorOnScreen();
}

bool InputManager::IsMouseButtonPressed(int button) const {
    return mouseInput->IsButtonPressed(button);
}

bool InputManager::IsMouseButtonDown(int button) const {
    return mouseInput->IsButtonDown(button);
}

bool InputManager::IsMouseButtonReleased(int button) const {
    return mouseInput->IsButtonReleased(button);
}

bool InputManager::IsMouseButtonUp(int button) const {
    return mouseInput->IsButtonUp(button);
}

int InputManager::GetMouseX() const {
    return mouseInput->GetMouseX();
}

int InputManager::GetMouseY() const {
    return mouseInput->GetMouseY();
}

MousePosition InputManager::GetMousePosition() const {
    return mouseInput->GetMousePosition();
}

MousePosition InputManager::GetMouseDelta() const {
    return mouseInput->GetMouseDelta();
}

void InputManager::SetMousePosition(int x, int y) {
    mouseInput->SetMousePosition(x, y);
}

void InputManager::SetMouseOffset(int offsetX, int offsetY) {
    mouseInput->SetMouseOffset(offsetX, offsetY);
}

void InputManager::SetMouseScale(float scaleX, float scaleY) {
    mouseInput->SetMouseScale(scaleX, scaleY);
}

float InputManager::GetMouseWheelMove() const {
    return mouseInput->GetMouseWheelMove();
}

MousePosition InputManager::GetMouseWheelMoveV() const {
    return mouseInput->GetMouseWheelMoveV();
}

void InputManager::SetMouseCursor(int cursor) {
    mouseInput->SetMouseCursor(cursor);
}

} // namespace input
