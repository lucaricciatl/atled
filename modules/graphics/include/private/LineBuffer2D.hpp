#pragma once
#include <vector>
#include <utility>  // for std::move

#include "Color.hpp"
#include "PointBuffer2D.hpp"
#include "Polyline2D.hpp"

namespace graphics {

class LineBuffer2D {
 public:
// Constructor
LineBuffer2D() : mLine() {
    // Additional initialization can be done here if necessary
}

// Destructor
~LineBuffer2D() = default;

  // Buffer manipulation
  void AddPoint(float aX, float aY);
  ColoredPoint2D GetPoint(size_t aIndex) const;
  void RemovePoint(size_t aIndex);
  void ClearBuffer();

  // Buffer information
  size_t GetSize() const noexcept;
  bool IsEmpty() const noexcept;
  const std::vector<ColoredPoint2D>& GetBuffer() const noexcept;

  // Setters and Loaders
  void SetBuffer(std::vector<ColoredPoint2D> aBuffer);
  void LoadBuffer();

  // Append Points to Buffer
  void AppendToBuffer(const std::vector<ColoredPoint2D>& aPoints);
  void AppendToBuffer(ColoredPoint2D aPoint);

  // Draw the buffer
  void DrawBuffer();

 private:
  std::vector<ColoredPoint2D> mBuffer;  // Stores the points in the line buffer
  Polyline2D mLine;              // Line used to draw the buffer
};

}  // namespace graphics
