// Buffer2D.hpp

#ifndef BUFFER2D_HPP
#define BUFFER2D_HPP

#include "raylib.h"
#include <vector>

namespace graphics {
// Forward declaration of ColoredPoint2D
struct ColoredPoint2D;
// Base class for all buffer types
// Base class for all buffer types
class Buffer2D {
 public:
  Buffer2D() = default;
  virtual ~Buffer2D() = default;

  // Virtual method to draw the buffer (to be implemented by derived classes)
  virtual void DrawBuffer() = 0;  // Add this as a pure virtual method

  // SetBuffer using the forward-declared ColoredPoint2D
  virtual void SetBuffer(std::vector<ColoredPoint2D> points) = 0;
};



} // namespace graphics

#endif // BUFFER2D_HPP
