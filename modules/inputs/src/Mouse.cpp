#include "Mouse.hpp"
#include "raylib.h"
#include "types.hpp"
#include <iostream>
namespace input {

Mouse::Mouse() : running(false) {}

Mouse::~Mouse() {
  Stop();  // Ensure the thread is stopped when the object is destroyed
}

// Cursor control functions
void Mouse::ShowCursor() { ::ShowCursor(); }
void Mouse::HideCursor() { ::HideCursor(); }
bool Mouse::IsCursorHidden() const { return ::IsCursorHidden(); }
void Mouse::EnableCursor() { ::EnableCursor(); }
void Mouse::DisableCursor() { ::DisableCursor(); }
bool Mouse::IsCursorOnScreen() const { return ::IsCursorOnScreen(); }

// Mouse button functions
bool Mouse::IsButtonPressed(int button) const {
  return ::IsMouseButtonPressed(button);
}
bool Mouse::IsButtonDown(int button) const {
  return ::IsMouseButtonDown(button);
}
bool Mouse::IsButtonReleased(int button) const {
  return ::IsMouseButtonReleased(button);
}
bool Mouse::IsButtonUp(int button) const { return ::IsMouseButtonUp(button); }

// Mouse position functions
int Mouse::GetMouseX() const { return ::GetMouseX(); }
int Mouse::GetMouseY() const { return ::GetMouseY(); }
MousePosition Mouse::GetMousePosition() const {
  Vector2 pos = ::GetMousePosition();
  return {static_cast<int>(pos.x), static_cast<int>(pos.y)};
}
MousePosition Mouse::GetMouseDelta() const {
  Vector2 delta = ::GetMouseDelta();
  return {static_cast<int>(delta.x), static_cast<int>(delta.y)};
}
void Mouse::SetMousePosition(int x, int y) { ::SetMousePosition(x, y); }
void Mouse::SetMouseOffset(int offsetX, int offsetY) {
  ::SetMouseOffset(offsetX, offsetY);
}
void Mouse::SetMouseScale(float scaleX, float scaleY) {
  ::SetMouseScale(scaleX, scaleY);
}

// Mouse wheel functions
float Mouse::GetMouseWheelMove() const { return ::GetMouseWheelMove(); }
MousePosition Mouse::GetMouseWheelMoveV() const {
  Vector2 move = ::GetMouseWheelMoveV();
  return {static_cast<int>(move.x), static_cast<int>(move.y)};
}

// Mouse cursor functions
void Mouse::SetMouseCursor(int cursor) { ::SetMouseCursor(cursor); }

// Start the mouse thread
void Mouse::Start() {
  if (!running) {
    running = true;
    mouseThread = std::thread(&Mouse::Run, this);  // Launch the thread
  }
}

// Stop the mouse thread
void Mouse::Stop() {
  if (running) {
    running = false;
    if (mouseThread.joinable()) {
      mouseThread.join();  // Wait for the thread to finish
    }
  }
}

// The thread's main loop
void Mouse::Run() {
  while (running) {
    // Example: log mouse position every frame
    MousePosition pos = GetMousePosition();
    //std::cout << "Mouse Position: (" << pos.x << ", " << pos.y << ")"
    //          << std::endl;

    // Sleep to avoid overwhelming the CPU
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}

}  // namespace input