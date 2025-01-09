#ifdef __linux__

#include "AtledMouse.hpp"
#include <stdexcept>
#include <iostream>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/XTest.h>
#include <unistd.h>

namespace input {

AtledMouse::AtledMouse()
    : running(false)
{
    // Open the X display
    display = XOpenDisplay(nullptr);
    if (!display) {
        throw std::runtime_error("Unable to open X display");
    }
}

AtledMouse::~AtledMouse() {
    Stop();
    if (display) {
        XCloseDisplay(display);
        display = nullptr;
    }
}

//---------------------
// Cursor control
//---------------------
void AtledMouse::ShowCursor() {
    cursorHidden = false;
    // On X11, showing/hiding the cursor typically requires changing the cursor to an invisible one. 
    // For simplicity, we won't do it here. 
    // One approach: create a blank Pixmap as the cursor, or revert to the default.
}

void AtledMouse::HideCursor() {
    cursorHidden = true;
    // In X11, hiding means setting an invisible cursor. 
    // For brevity, we leave this as a stub. Implementation can be done via XCreatePixmapCursor.
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
    // We can query pointer info to see if it's on the default root window.
    // This is a simplistic check:
    if (!display) return false;
    Window root = DefaultRootWindow(display);

    Window root_return, child_return;
    int root_x, root_y;
    int win_x, win_y;
    unsigned int mask_return;
    Bool result = XQueryPointer(display, root, &root_return, &child_return,
                                &root_x, &root_y, &win_x, &win_y, &mask_return);
    return (result == True);
}

//---------------------
// Mouse button states
//---------------------
bool AtledMouse::IsButtonPressed(int button) const {
    // “Pressed” might mean a transition. We'll do a direct "down" check.
    return IsButtonDown(button);
}

bool AtledMouse::IsButtonDown(int button) const {
    if (!display) return false;

    // Map your button index to X11 button masks:
    //   button 1 -> Button1Mask, etc.
    // We'll do a simple approach:
    unsigned int mask_return;
    Window root = DefaultRootWindow(display);
    Window root_return, child_return;
    int root_x, root_y, win_x, win_y;

    XQueryPointer(display, root, &root_return, &child_return,
                  &root_x, &root_y, &win_x, &win_y, &mask_return);

    switch (button) {
        case 0: // Left
            return (mask_return & Button1Mask) != 0;
        case 1: // Right
            return (mask_return & Button3Mask) != 0;
        case 2: // Middle
            return (mask_return & Button2Mask) != 0;
        default:
            return false;
    }
}

bool AtledMouse::IsButtonReleased(int button) const {
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
    if (!display) {
        throw std::runtime_error("X display not initialized");
    }

    Window root = DefaultRootWindow(display);
    // Warp pointer
    if (XWarpPointer(display, None, root, 0, 0, 0, 0, x, y) != Success) {
        throw std::runtime_error("Failed to move mouse cursor on Linux");
    }
    XFlush(display);

    mouseX = x;
    mouseY = y;
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
    // In X11, you'd typically load or create a Cursor and then call XDefineCursor.
    // We'll leave this as a stub.
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

void AtledMouse::runUpdateLoop() {
    // Basic example: poll mouse position every so often
    int oldX = 0, oldY = 0;

    while (running) {
        if (display) {
            Window root = DefaultRootWindow(display);
            Window root_return, child_return;
            int root_x, root_y;
            int win_x, win_y;
            unsigned int mask_return;

            if (XQueryPointer(display, root, &root_return, &child_return,
                              &root_x, &root_y, &win_x, &win_y, &mask_return)) 
            {
                deltaX = root_x - mouseX;
                deltaY = root_y - mouseY;

                mouseX = root_x;
                mouseY = root_y;
            }
        }
        // Wheel movement in X11 often comes from XNextEvent (ButtonPress for 4/5/6/7).
        // For a continuous poll approach, you'd have to integrate with the event loop or
        // detect them in another way (e.g. XRecord extension). We'll keep it as a stub.

        usleep(10'000); // Sleep 10 ms
    }
}

} // namespace input

#endif // __linux__
