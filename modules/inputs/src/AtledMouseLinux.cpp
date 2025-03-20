#ifdef __APPLE__

#include "AtledMouse.hpp"
#include <stdexcept>
#include <iostream>
#include <thread>
#include <chrono>

namespace input {

AtledMouse::AtledMouse() : running(false)
{
    // For macOS, initialization can use native APIs if needed.
    // For now, we leave this as a stub.
}

AtledMouse::~AtledMouse() {
    Stop();
}

//---------------------
// Cursor control
//---------------------
void AtledMouse::ShowCursor()         { cursorHidden = false; }
void AtledMouse::HideCursor()         { cursorHidden = true; }
bool AtledMouse::IsCursorHidden() const { return cursorHidden; }
void AtledMouse::EnableCursor()       { ShowCursor(); }
void AtledMouse::DisableCursor()      { HideCursor(); }
bool AtledMouse::IsCursorOnScreen() const {
    // For macOS, consider using CGDisplayBounds or similar.
    return true; // Stub: assume always on screen
}

//---------------------
// Mouse button states
//---------------------
bool AtledMouse::IsButtonPressed(int button) const { return false; }
bool AtledMouse::IsButtonDown(int button) const    { return false; }
bool AtledMouse::IsButtonReleased(int button) const{ return !IsButtonDown(button); }
bool AtledMouse::IsButtonUp(int button) const      { return !IsButtonDown(button); }

//---------------------
// Mouse position
//---------------------
int AtledMouse::GetMouseX() const                { return mouseX; }
int AtledMouse::GetMouseY() const                { return mouseY; }
MousePosition AtledMouse::GetMousePosition() const { return { mouseX, mouseY }; }
MousePosition AtledMouse::GetMouseDelta() const    { return { deltaX, deltaY }; }
void AtledMouse::SetMousePosition(int x, int y)    { mouseX = x; mouseY = y; }
void AtledMouse::SetMouseOffset(int offsetX, int offsetY) {
    SetMousePosition(mouseX + offsetX, mouseY + offsetY);
}
void AtledMouse::SetMouseScale(float sx, float sy) { scaleX = sx; scaleY = sy; }

//---------------------
// Mouse wheel
//---------------------
float AtledMouse::GetMouseWheelMove() const        { return wheelMove; }
MousePosition AtledMouse::GetMouseWheelMoveV() const {
    // Cast to int if MousePosition members are int.
    return { static_cast<int>(wheelMoveX), static_cast<int>(wheelMoveY) };
}

//---------------------
// Mouse cursor
//---------------------
void AtledMouse::SetMouseCursor(int cursor) {
    // macOS specific implementation can use NSCursor (if using Cocoa) or CGEvent.
    // For now, this method is a stub.
}

//---------------------
// Thread control
//---------------------
void AtledMouse::Start() {
    if (running) return;
    running = true;
    thread = std::thread(&AtledMouse::runUpdateLoop, this);
}

void AtledMouse::Stop() {
    if (!running) return;
    running = false;
    if (thread.joinable()) {
        thread.join();
    }
}

void AtledMouse::runUpdateLoop() {
    while (running) {
        // In a real macOS implementation, update mouse state (position, etc.)
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

} // namespace input

#endif // __APPLE__
