#include "RaylibMouse.hpp"
#include "raylib.hpp"
#include <iostream>

namespace input
{

  using namespace raylib;

  RaylibMouse::RaylibMouse() : running(false) {}

  // Cursor control functions
  void RaylibMouse::ShowCursor() { raylib::ShowCursor(); }
  void RaylibMouse::HideCursor() { raylib::HideCursor(); }
  bool RaylibMouse::IsCursorHidden() const { return raylib::IsCursorHidden(); }
  void RaylibMouse::EnableCursor() { raylib::EnableCursor(); }
  void RaylibMouse::DisableCursor() { raylib::DisableCursor(); }
  bool RaylibMouse::IsCursorOnScreen() const { return raylib::IsCursorOnScreen(); }

  // RaylibMouse button functions
  bool RaylibMouse::IsButtonPressed(int button) const
  {
    return raylib::IsMouseButtonPressed(button);
  }
  bool RaylibMouse::IsButtonDown(int button) const
  {
    return raylib::IsMouseButtonDown(button);
  }
  bool RaylibMouse::IsButtonReleased(int button) const
  {
    return raylib::IsMouseButtonReleased(button);
  }
  bool RaylibMouse::IsButtonUp(int button) const { return raylib::IsMouseButtonUp(button); }

  // RaylibMouse position functions
  int RaylibMouse::GetMouseX() const { return raylib::GetMouseX(); }
  int RaylibMouse::GetMouseY() const { return raylib::GetMouseY(); }
  MousePosition RaylibMouse::GetMousePosition() const
  {
    raylib::Vector2 pos = raylib::GetMousePosition();
    return {static_cast<int>(pos.x), static_cast<int>(pos.y)};
  }
  MousePosition RaylibMouse::GetMouseDelta() const
  {
    raylib::Vector2 delta = raylib::GetMouseDelta();
    return {static_cast<int>(delta.x), static_cast<int>(delta.y)};
  }
  void RaylibMouse::SetMousePosition(int x, int y) { raylib::SetMousePosition(x, y); }
  void RaylibMouse::SetMouseOffset(int offsetX, int offsetY)
  {
    raylib::SetMouseOffset(offsetX, offsetY);
  }
  void RaylibMouse::SetMouseScale(float scaleX, float scaleY)
  {
    raylib::SetMouseScale(scaleX, scaleY);
  }

  // RaylibMouse wheel functions
  float RaylibMouse::GetMouseWheelMove() const { return raylib::GetMouseWheelMove(); }
  MousePosition RaylibMouse::GetMouseWheelMoveV() const
  {
    raylib::Vector2 move = raylib::GetMouseWheelMoveV();
    return {static_cast<int>(move.x), static_cast<int>(move.y)};
  }

  // RaylibMouse cursor functions
  void RaylibMouse::SetMouseCursor(int cursor) { raylib::SetMouseCursor(cursor); }

  // Start the RaylibMouse thread
  void RaylibMouse::Start()
  {
    if (!running)
    {
      running = true;
      mouseThread = std::thread(&RaylibMouse::Run, this); // Launch the thread
    }
  }

  // Stop the RaylibMouse thread
  void RaylibMouse::Stop()
  {
    if (running)
    {
      running = false;
      if (mouseThread.joinable())
      {
        mouseThread.join(); // Wait for the thread to finish
      }
    }
  }

  // The thread's main loop
  void RaylibMouse::Run()
  {
    while (running)
    {
      // Example: log RaylibMouse position every frame
      MousePosition pos = GetMousePosition();
      std::cout << "RaylibMouse Position: (" << pos.x << ", " << pos.y << ")"
                << std::endl;

      // Sleep to avoid overwhelming the CPU
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
  }

} // namespace input