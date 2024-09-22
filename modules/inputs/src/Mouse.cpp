#include "Mouse.hpp"
#include "raylib.h"
#include <iostream>
namespace input {

Mouse::Mouse() : running(false) {}

Mouse::~Mouse() {
  Stop();  // Ensure the thread is stopped when the object is destroyed
}

// Cursor control functions
void Mouse::ShowCursor() { raylib::ShowCursor(); }
void Mouse::HideCursor() { raylib::HideCursor(); }
bool Mouse::IsCursorHidden() const { return raylib::IsCursorHidden(); }
void Mouse::EnableCursor() { raylib::EnableCursor(); }
void Mouse::DisableCursor() { raylib::DisableCursor(); }
bool Mouse::IsCursorOnScreen() const { return raylib::IsCursorOnScreen(); }

// Mouse button functions
bool Mouse::IsButtonPressed(int button) const {
  return raylib::IsMouseButtonPressed(button);
}
bool Mouse::IsButtonDown(int button) const {
  return raylib::IsMouseButtonDown(button);
}
bool Mouse::IsButtonReleased(int button) const {
  return raylib::IsMouseButtonReleased(button);
}
bool Mouse::IsButtonUp(int button) const { return raylib::IsMouseButtonUp(button); }

// Mouse position functions
int Mouse::GetMouseX() const { return raylib::GetMouseX(); }
int Mouse::GetMouseY() const { return raylib::GetMouseY(); }
MousePosition Mouse::GetMousePosition() const {
  raylib::Vector2 pos = raylib::GetMousePosition();
  return {static_cast<int>(pos.x), static_cast<int>(pos.y)};
}
MousePosition Mouse::GetMouseDelta() const {
  raylib::Vector2 delta = raylib::GetMouseDelta();
  return {static_cast<int>(delta.x), static_cast<int>(delta.y)};
}
void Mouse::SetMousePosition(int x, int y) { raylib::SetMousePosition(x, y); }
void Mouse::SetMouseOffset(int offsetX, int offsetY) {
  raylib::SetMouseOffset(offsetX, offsetY);
}
void Mouse::SetMouseScale(float scaleX, float scaleY) {
  raylib::SetMouseScale(scaleX, scaleY);
}

// Mouse wheel functions
float Mouse::GetMouseWheelMove() const { return raylib::GetMouseWheelMove(); }
MousePosition Mouse::GetMouseWheelMoveV() const {
  raylib::Vector2 move = raylib::GetMouseWheelMoveV();
  return {static_cast<int>(move.x), static_cast<int>(move.y)};
}

// Mouse cursor functions
void Mouse::SetMouseCursor(int cursor) { raylib::SetMouseCursor(cursor); }

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