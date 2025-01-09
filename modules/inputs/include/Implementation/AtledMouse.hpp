#ifndef ATLED_MOUSE_HPP
#define ATLED_MOUSE_HPP

#include "IMouse.hpp"
#include <atomic>
#include <thread>

namespace input {

/// Concrete mouse implementation named "AtledMouse"
class AtledMouse : public IMouse {
public:
    AtledMouse();
	~AtledMouse();
    // Cursor control functions
    void ShowCursor() override;
    void HideCursor() override;
    bool IsCursorHidden() const override;
    void EnableCursor() override;
    void DisableCursor() override;
    bool IsCursorOnScreen() const override;

    // Mouse button functions
    bool IsButtonPressed(int button) const override;
    bool IsButtonDown(int button) const override;
    bool IsButtonReleased(int button) const override;
    bool IsButtonUp(int button) const override;

    // Mouse position functions
    int GetMouseX() const override;
    int GetMouseY() const override;
    MousePosition GetMousePosition() const override;
    MousePosition GetMouseDelta() const override;
    void SetMousePosition(int x, int y) override;
    void SetMouseOffset(int offsetX, int offsetY) override;
    void SetMouseScale(float scaleX, float scaleY) override;

    // Mouse wheel functions
    float GetMouseWheelMove() const override;
    MousePosition GetMouseWheelMoveV() const override;

    // Mouse cursor functions
    void SetMouseCursor(int cursor) override;

    // Thread control
    void Start() override;
    void Stop() override;

private:
    // Common data members
    bool   cursorHidden   = false;
    int    mouseX         = 0;
    int    mouseY         = 0;
    int    deltaX         = 0;
    int    deltaY         = 0;
    float  wheelMove      = 0.0f;          // For simple vertical wheel
    int    wheelMoveX     = 0;             // For horizontal scrolling
    int    wheelMoveY     = 0;             // For vertical scrolling
    float  scaleX         = 1.0f;          // Mouse coordinate scaling
    float  scaleY         = 1.0f;

    // Thread control
    std::atomic<bool> running;
    std::thread       thread;

    // Platform-specific fields
#ifdef _WIN32
    // e.g. HCURSOR hCursor;
#elif __linux__
    struct _XDisplay* display = nullptr;   // Forward-declared type from <X11/Xlib.h>
#endif

    // Internal function for background updates, if desired
    void runUpdateLoop();
};

} // namespace input

#endif // ATLED_MOUSE_HPP
