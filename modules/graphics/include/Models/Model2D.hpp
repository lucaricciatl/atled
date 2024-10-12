#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>
#include <PolygonBuffer2D.hpp>
#include "PointBuffer2D.hpp"

namespace graphics {

class Model2D {
 public:
  virtual ~Model2D() = default;
  virtual void Draw() = 0 ;
  protected:
  PolygonBuffer2D mBuffer;


};
}  // namespace graphics
#endif  // SHAPE_HPP

