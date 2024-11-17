#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>
#include <PolygonBuffer2D.hpp>
#include "PointBuffer2D.hpp"
#include "Model.hpp"

namespace graphics {

class Model2D : public  Model{
 public:
  virtual ~Model2D() = default;
  virtual void Draw() = 0 ;


};
}  // namespace graphics
#endif  // SHAPE_HPP

