#ifndef RAYLIBMOUSE_HPP
#define RAYLIBMOUSE_HPP

#include "IMouse.hpp"
#include "raylib.hpp"
#include <atomic>
#include <thread>

namespace input {

class RaylibMouse : public IMouse {
public:
  RaylibMouse();

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
  std::thread mouseThread;
  std::atomic<bool> running;

  // Thread loop function
  void Run();
};

} // namespace input

#endif // RAYLIBMOUSE_HPP
