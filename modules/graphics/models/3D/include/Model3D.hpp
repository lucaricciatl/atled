#ifndef SHAPE3D_HPP
#define SHAPE3D_HPP

#include <iostream>
#include "Model.hpp"
#include "raylib.hpp"

namespace graphics {

class Model3D : public Model{
 public:
  virtual ~Model3D() = default;
  virtual void Draw() = 0 ;


  void EnableWireframe();
  void DisableWireframe();

  // Enable wireframe rendering
  void EnableShape();
  void DisableShape();
  void SetWireframeColor(raylib::Color aColor);
  raylib::Color GetWireframeColor() const;
  // Setter for color
  void SetColor(const raylib::Color& color);

  // Getter for color
  raylib::Color GetColor() const;


protected:
  bool WireframeIsEnabled;    // 1 for the wirefram
  bool ShapeIsEnabled;        // 1 for the wirefram
  raylib::Color mWireframeColor;      // Color of thr wireframe
  raylib::Color mColor;
};



}  // namespace graphics
#endif  // SHAPE_HPP

