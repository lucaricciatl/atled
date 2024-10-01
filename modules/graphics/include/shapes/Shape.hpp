#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>
#include <PolygonBuffer2D.hpp>


namespace graphics {

struct Coordinates2D {
  float x, y;
};

class Shape {
 public:
  virtual ~Shape() = default;

  void SetColor(float aColor);
  void Translate();
  void TranslateX(float aX);
  void TranslateY(float aY);
  void Rotate(const float aAngle);

 protected:
  PolygonBuffer2D aBuffer;
};
#endif  // SHAPE_HPP

}