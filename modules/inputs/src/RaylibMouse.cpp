#include "RaylibMouse.hpp"
#include "glwp.hpp"
#include <iostream>

namespace input {

RaylibMouse::RaylibMouse() : running(false) {}

// Cursor control functions
void RaylibMouse::ShowCursor() { ::ShowCursor(); }
void RaylibMouse::HideCursor() { ::HideCursor(); }
bool RaylibMouse::IsCursorHidden() const { return ::IsCursorHidden(); }
void RaylibMouse::EnableCursor() { ::EnableCursor(); }
void RaylibMouse::DisableCursor() { ::DisableCursor(); }
bool RaylibMouse::IsCursorOnScreen() const { return ::IsCursorOnScreen(); }

// RaylibMouse button functions
bool RaylibMouse::IsButtonPressed(int button) const {
  return ::IsMouseButtonPressed(button);
}
bool RaylibMouse::IsButtonDown(int button) const {
  return ::IsMouseButtonDown(button);
}
bool RaylibMouse::IsButtonReleased(int button) const {
  return ::IsMouseButtonReleased(button);
}
bool RaylibMouse::IsButtonUp(int button) const { return ::IsMouseButtonUp(button); }

// RaylibMouse position functions
int RaylibMouse::GetMouseX() const { return ::GetMouseX(); }
int RaylibMouse::GetMouseY() const { return ::GetMouseY(); }
MousePosition RaylibMouse::GetMousePosition() const {
  Vector2 pos = ::GetMousePosition();
  return {static_cast<int>(pos.x), static_cast<int>(pos.y)};
}
MousePosition RaylibMouse::GetMouseDelta() const {
  Vector2 delta = ::GetMouseDelta();
  return {static_cast<int>(delta.x), static_cast<int>(delta.y)};
}
void RaylibMouse::SetMousePosition(int x, int y) { ::SetMousePosition(x, y); }
void RaylibMouse::SetMouseOffset(int offsetX, int offsetY) {
  ::SetMouseOffset(offsetX, offsetY);
}
void RaylibMouse::SetMouseScale(float scaleX, float scaleY) {
  ::SetMouseScale(scaleX, scaleY);
}

// RaylibMouse wheel functions
float RaylibMouse::GetMouseWheelMove() const { return ::GetMouseWheelMove(); }
MousePosition RaylibMouse::GetMouseWheelMoveV() const {
  Vector2 move = ::GetMouseWheelMoveV();
  return {static_cast<int>(move.x), static_cast<int>(move.y)};
}

// RaylibMouse cursor functions
void RaylibMouse::SetMouseCursor(int cursor) { ::SetMouseCursor(cursor); }

// Start the RaylibMouse thread
void RaylibMouse::Start() {
  if (!running) {
    running = true;
    mouseThread = std::thread(&RaylibMouse::Run, this);  // Launch the thread
  }
}

// Stop the RaylibMouse thread
void RaylibMouse::Stop() {
  if (running) {
    running = false;
    if (mouseThread.joinable()) {
      mouseThread.join();  // Wait for the thread to finish
    }
  }
}

// The thread's main loop
void RaylibMouse::Run() {
  while (running) {
    // Example: log RaylibMouse position every frame
    MousePosition pos = GetMousePosition();
    //std::cout << "RaylibMouse Position: (" << pos.x << ", " << pos.y << ")"
    //          << std::endl;

    // Sleep to avoid overwhelming the CPU
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}

}  // namespace input