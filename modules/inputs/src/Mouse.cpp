#include "Mouse.hpp"
#include "input.hpp"
#include "types.hpp"
#include <iostream>
namespace input {

Mouse::Mouse() : running(false) {}

Mouse::~Mouse() {
  Stop();  // Ensure the thread is stopped when the object is destroyed
}

// Cursor control functions
void Mouse::ShowCursor() { input::ShowCursor(); }
void Mouse::HideCursor() { input::HideCursor(); }
bool Mouse::IsCursorHidden() const { return input::IsCursorHidden(); }
void Mouse::EnableCursor() { input::EnableCursor(); }
void Mouse::DisableCursor() { input::DisableCursor(); }
bool Mouse::IsCursorOnScreen() const { return input::IsCursorOnScreen(); }

// Mouse button functions
bool Mouse::IsButtonPressed(int button) const {
  return input::IsMouseButtonPressed(button);
}
bool Mouse::IsButtonDown(int button) const {
  return input::IsMouseButtonDown(button);
}
bool Mouse::IsButtonReleased(int button) const {
  return input::IsMouseButtonReleased(button);
}
bool Mouse::IsButtonUp(int button) const { return input::IsMouseButtonUp(button); }

// Mouse position functions
int Mouse::GetMouseX() const { return input::GetMouseX(); }
int Mouse::GetMouseY() const { return input::GetMouseY(); }
MousePosition Mouse::GetMousePosition() const {
  Vector2 pos = input::GetMousePosition();
  return {static_cast<int>(pos.x), static_cast<int>(pos.y)};
}
MousePosition Mouse::GetMouseDelta() const {
  Vector2 delta = input::GetMouseDelta();
  return {static_cast<int>(delta.x), static_cast<int>(delta.y)};
}
void Mouse::SetMousePosition(int x, int y) { input::SetMousePosition(x, y); }
void Mouse::SetMouseOffset(int offsetX, int offsetY) {
  input::SetMouseOffset(offsetX, offsetY);
}
void Mouse::SetMouseScale(float scaleX, float scaleY) {
  input::SetMouseScale(scaleX, scaleY);
}

// Mouse wheel functions
float Mouse::GetMouseWheelMove() const { return input::GetMouseWheelMove(); }
MousePosition Mouse::GetMouseWheelMoveV() const {
  Vector2 move = input::GetMouseWheelMoveV();
  return {static_cast<int>(move.x), static_cast<int>(move.y)};
}

// Mouse cursor functions
void Mouse::SetMouseCursor(int cursor) { input::SetMouseCursor(cursor); }

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