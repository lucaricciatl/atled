#ifndef SHAPE3D_HPP
#define SHAPE3D_HPP

#include <iostream>
#include "Model.hpp"

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
  void SetWireframeColor(Color aColor);
  Color GetWireframeColor() const;
  // Setter for color
  void SetColor(const Color& color);

  // Getter for color
  Color GetColor() const;


protected:
  bool WireframeIsEnabled;    // 1 for the wirefram
  bool ShapeIsEnabled;        // 1 for the wirefram
  Color mWireframeColor;      // Color of thr wireframe
  Color mColor;
};



}  // namespace graphics
#endif  // SHAPE_HPP

