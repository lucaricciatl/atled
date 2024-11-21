#ifndef MOUSEINTERFACE_HPP
#define MOUSEINTERFACE_HPP

namespace input {

enum class MouseType{ 
	Invalid,
	Raylib
};

struct MousePosition {
  int x;
  int y;
};

class IMouse {
public:
  // Cursor control functions
  virtual void ShowCursor() = 0;
  virtual void HideCursor() = 0;
  virtual bool IsCursorHidden() const = 0;
  virtual void EnableCursor() = 0;
  virtual void DisableCursor() = 0;
  virtual bool IsCursorOnScreen() const = 0;

  // Mouse button functions
  virtual bool IsButtonPressed(int button) const = 0;
  virtual bool IsButtonDown(int button) const = 0;
  virtual bool IsButtonReleased(int button) const = 0;
  virtual bool IsButtonUp(int button) const = 0;

  // Mouse position functions
  virtual int GetMouseX() const = 0;
  virtual int GetMouseY() const = 0;
  virtual MousePosition GetMousePosition() const = 0;
  virtual MousePosition GetMouseDelta() const = 0;
  virtual void SetMousePosition(int x, int y) = 0;
  virtual void SetMouseOffset(int offsetX, int offsetY) = 0;
  virtual void SetMouseScale(float scaleX, float scaleY) = 0;

  // Mouse wheel functions
  virtual float GetMouseWheelMove() const = 0;
  virtual MousePosition GetMouseWheelMoveV() const = 0;

  // Mouse cursor functions
  virtual void SetMouseCursor(int cursor) = 0;

  // Thread control
  virtual void Start() = 0;
  virtual void Stop() = 0;
};

} // namespace input

#endif // MOUSEINTERFACE_HPP
