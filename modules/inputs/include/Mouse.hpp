#ifndef MOUSE_H
#define MOUSE_H

#include "raylib.h"
#include <atomic>
#include <thread>

namespace input {
struct MousePosition {
  int x;
  int y;
};

class Mouse {
 public:
  Mouse();
  ~Mouse();

  // Cursor control functions
  void ShowCursor();
  void HideCursor();
  bool IsCursorHidden() const;
  void EnableCursor();
  void DisableCursor();
  bool IsCursorOnScreen() const;

  // Mouse button functions
  bool IsButtonPressed(int button) const;
  bool IsButtonDown(int button) const;
  bool IsButtonReleased(int button) const;
  bool IsButtonUp(int button) const;

  // Mouse position functions
  int GetMouseX() const;
  int GetMouseY() const;
  MousePosition GetMousePosition() const;
  MousePosition GetMouseDelta() const;
  void SetMousePosition(int x, int y);
  void SetMouseOffset(int offsetX, int offsetY);
  void SetMouseScale(float scaleX, float scaleY);

  // Mouse wheel functions
  float GetMouseWheelMove() const;
  MousePosition GetMouseWheelMoveV() const;

  // Mouse cursor functions
  void SetMouseCursor(int cursor);

  // Thread control
  void Start();
  void Stop();

 private:
  std::thread mouseThread;
  std::atomic<bool> running;

  // Thread loop function
  void Run();
};

#endif  // MOUSE_H



}