#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>
#include <PolygonBuffer2D.hpp>
#include "PointBuffer2D.hpp"

namespace graphics {

class Shape {
 public:
  virtual ~Shape() = default;

  void SetColor(Color aColor);
  void Translate(float dx, float dy);
  void TranslateX(float aX);
  void TranslateY(float aY);
  void Rotate(const float aAngle);

   protected:
  PolygonBuffer2D mBuffer;
  ::Color mColor;  // Color of the shape
};
}  // namespace graphics
#endif  // SHAPE_HPP

