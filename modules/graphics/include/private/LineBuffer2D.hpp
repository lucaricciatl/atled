#pragma once
#include <vector>

#include "Color.hpp"
#include "PointBuffer2D.hpp"
#include "Polyline2D.hpp"

namespace graphics {


class LineBuffer2D {
 public:
  // Constructor and Destructor
  LineBuffer2D();
  ~LineBuffer2D();

  // Buffer manipulation
  void AddPoint(float x, float y);
  ColoredPoint2D GetPoint(size_t aIndex) const;
  void RemovePoint(size_t aIndex);
  void ClearBuffer();

  // Buffer information
  size_t GetSize() const;
  bool IsEmpty() const;
  const std::vector<ColoredPoint2D>& GetBuffer() const;

  // Setters and Loaders
  void SetBuffer(std::vector<ColoredPoint2D> aBuffer);
  void LoadBuffer();

  // Append Points to Buffer
  void AppendToBuffer(const std::vector<ColoredPoint2D>& aPoints);
  void AppendToBuffer(const ColoredPoint2D& aPoint);

  // Draw the buffer
  void DrawBuffer();

 private:
  std::vector<ColoredPoint2D> mBuffer;  // Stores the points in the line buffer
  Polyline2D mLine;              // Line used to draw the buffer
};
}  // namespace graphics