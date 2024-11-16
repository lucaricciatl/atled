#ifndef SHAPE3D_HPP
#define SHAPE3D_HPP

#include <iostream>
#include "Model.hpp"
namespace graphics {

class Model3D : Model{
 public:
  virtual ~Model3D() = default;
  virtual void Draw() = 0 ;

};



}  // namespace graphics
#endif  // SHAPE_HPP

