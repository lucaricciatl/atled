#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>
#include <PolygonBuffer2D.hpp>
#include "PointBuffer2D.hpp"

namespace graphics {

class Shape {
 public:
  virtual ~Shape() = default;
  virtual void Draw() = 0 ;
  protected:
  PolygonBuffer2D mBuffer;


};
}  // namespace graphics
#endif  // SHAPE_HPP

