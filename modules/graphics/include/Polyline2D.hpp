#pragma once 

#include <vector>
#include "raylib-cpp.hpp" // Include raylib header for Color and DrawLine functions
#include "PointBuffer2D.hpp"

namespace graphics {
class Polyline2D {
 public:
  void AddPoint(ColoredPoint2D point);
  void AddPoints(const std::vector<ColoredPoint2D>& aPoints);
  void Draw() const;
  void Clear();
  size_t GetPointCount() const;
  ColoredPoint2D GetPoint(size_t aIndex) const;

 private:
  std::vector<ColoredPoint2D> mPoints;
};
}  // namespace graphics