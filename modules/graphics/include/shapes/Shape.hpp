#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>
#include <PolygonBuffer2D.hpp>
#include "PointBuffer2D.hpp"

namespace graphics {

class Shape {
 public:
  virtual ~Shape() = default;

  void Translate(float dx, float dy);
  void TranslateX(float aX);
  void TranslateY(float aY);
  void Rotate(const float aAngle);
  virtual void Draw();

   protected:
  PolygonBuffer2D mBuffer;


};
}  // namespace graphics
#endif  // SHAPE_HPP

