#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>
#include "raylib.hpp"
#include "Point2D.hpp"
#include "Model.hpp"

namespace graphics {

class Model2D : public  Model{
 public:
  virtual ~Model2D() = default;
  virtual void Draw() = 0 ;

  raylib::Color GetColor() const;
  double GetRotation() const;
  void SetColor(const raylib::Color& color);
  void SetRotation(double rotation);

protected:
	raylib::Color mColor;
  double mRotation;
};
}  // namespace graphics
#endif  // SHAPE_HPP

