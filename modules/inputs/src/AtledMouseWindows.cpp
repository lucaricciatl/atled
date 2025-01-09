#ifdef _WIN32

#include "AtledMouse.hpp"
#include <stdexcept>
#include <iostream>
#include <windows.h>

namespace input {

AtledMouse::AtledMouse() 
    : running(false)
{
    // Windows-specific initialization if needed
}

AtledMouse::~AtledMouse() {
    Stop();
    // Windows-specific cleanup if needed
}

//---------------------
// Cursor control
//---------------------
void AtledMouse::ShowCursor() {
    cursorHidden = false;
    //::ShowCursor(TRUE);  // Win32 API: increments an internal counter
}

void AtledMouse::HideCursor() {
    cursorHidden = true;
    //::ShowCursor(FALSE); // Win32 API: decrements an internal counter
}

bool AtledMouse::IsCursorHidden() const {
    return cursorHidden;
}

void AtledMouse::EnableCursor() {
    ShowCursor();
}

void AtledMouse::DisableCursor() {
    HideCursor();
}

bool AtledMouse::IsCursorOnScreen() const {
    // In Windows, we can get cursor position and check if it's inside the screen bounds
    POINT pt;
    if (::GetCursorPos(&pt)) {
        // Optionally check if pt is within a monitor's rect
        return true;
    }
    return false;
}

//---------------------
// Mouse button states
//---------------------
//
// Common Win32 virtual key codes for mouse:
//   VK_LBUTTON (0x01)
//   VK_RBUTTON (0x02)
//   VK_MBUTTON (0x04)
//   VK_XBUTTON1 (0x05)
//   VK_XBUTTON2 (0x06)
//
bool AtledMouse::IsButtonPressed(int button) const {
    // Example: "pressed" might mean just transitioned from up to down
    // Real implementation would track prior states. For simplicity, just return "down"
    return IsButtonDown(button);
}

bool AtledMouse::IsButtonDown(int button) const {
    SHORT state = 0;
    switch (button) {
        case 0: state = GetAsyncKeyState(VK_LBUTTON);   break;
        case 1: state = GetAsyncKeyState(VK_RBUTTON);   break;
        case 2: state = GetAsyncKeyState(VK_MBUTTON);   break;
        default: return false;
    }
    // High bit set means the key is currently down
    return (state & 0x8000) != 0;
}

bool AtledMouse::IsButtonReleased(int button) const {
    // Example: "released" might mean just transitioned from down to up
    // For simplicity, invert "pressed"
    return !IsButtonDown(button);
}

bool AtledMouse::IsButtonUp(int button) const {
    return !IsButtonDown(button);
}

//---------------------
// Mouse position
//---------------------
int AtledMouse::GetMouseX() const {
    return mouseX;
}

int AtledMouse::GetMouseY() const {
    return mouseY;
}

MousePosition AtledMouse::GetMousePosition() const {
    return { mouseX, mouseY };
}

MousePosition AtledMouse::GetMouseDelta() const {
    return { deltaX, deltaY };
}

void AtledMouse::SetMousePosition(int x, int y) {
    // Update our internal tracking
    mouseX = x;
    mouseY = y;

    // Move actual OS cursor
    if (!::SetCursorPos(x, y)) {
        throw std::runtime_error("Failed to move mouse cursor on Windows");
    }
}

void AtledMouse::SetMouseOffset(int offsetX, int offsetY) {
    SetMousePosition(mouseX + offsetX, mouseY + offsetY);
}

void AtledMouse::SetMouseScale(float sx, float sy) {
    scaleX = sx;
    scaleY = sy;
}

//---------------------
// Mouse wheel
//---------------------
float AtledMouse::GetMouseWheelMove() const {
    return wheelMove;
}

MousePosition AtledMouse::GetMouseWheelMoveV() const {
    return { wheelMoveX, wheelMoveY };
}

//---------------------
// Mouse cursor
//---------------------
void AtledMouse::SetMouseCursor(int cursor) {
    // You could load a cursor resource or pick a system cursor based on "cursor"
    // Example (for default arrow):
    // HCURSOR hCurs = ::LoadCursor(NULL, IDC_ARROW);
    // ::SetCursor(hCurs);
}

//---------------------
// Thread control
//---------------------
void AtledMouse::Start() {
    if (running) {
        return;
    }
    running = true;
    thread = std::thread(&AtledMouse::runUpdateLoop, this);
}

void AtledMouse::Stop() {
    if (!running) {
        return;
    }
    running = false;
    if (thread.joinable()) {
        thread.join();
    }
}

//---------------------
// Internal update loop
//---------------------
void AtledMouse::runUpdateLoop() {
    // Basic example: poll cursor pos & wheel moves
    POINT ptOld{ 0, 0 };
    POINT ptNew{ 0, 0 };

    // Use Windows Raw Input or DirectInput for more advanced usage
    while (running) {
        // Get current position
        if (::GetCursorPos(&ptNew)) {
            // delta
            deltaX = ptNew.x - ptOld.x;
            deltaY = ptNew.y - ptOld.y;

            // update internal
            mouseX = ptNew.x;
            mouseY = ptNew.y;

            // store old
            ptOld = ptNew;
        }

        // Wheel movement: 
        // On Windows, you typically read the wheel via WM_MOUSEWHEEL or raw input. 
        // This loop won't capture it unless you do more advanced hooking. 
        // We'll leave it as a stub or as an exercise.

        ::Sleep(10); // avoid busy loop
    }
}

} // namespace input

#endif // _WIN32
