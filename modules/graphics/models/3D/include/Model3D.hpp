#ifndef SHAPE3D_HPP
#define SHAPE3D_HPP

#include <iostream>
#include "Model.hpp"
#include "raylib.hpp"

namespace graphics
{

  class Model3D : public Model
  {
  public:
    virtual ~Model3D() = default;
    virtual void Draw() = 0;

    void EnableWireframe();
    void DisableWireframe();

    // Enable wireframe rendering
    void EnableShape();
    void DisableShape();
    void SetWireframeColor(Color aColor);
    Color GetWireframeColor() const;
    // Setter for color
    void SetColor(const Color &color);

    // Getter for color
    Color GetColor() const;

  protected:
    math::Vector3 ComputeGlobalPosition(math::Vector3 aPosition)
    {
      auto framepos =  frame->GetPosition();
      auto globalPosition = math::Vector3(
          (float)framepos->getX() + aPosition.getX(),
          (float)framepos->getY() + aPosition.getY(),
          (float)framepos->getZ() + aPosition.getZ());
      return globalPosition;
    };

    bool WireframeIsEnabled;                           // 1 for the wirefram
    bool ShapeIsEnabled;                               // 1 for the wirefram
    Color mWireframeColor = Color(128, 128, 128, 128); // Color of thr wireframe
    Color mColor = Color(64, 64, 64, 64);
  };

} // namespace graphics
#endif // SHAPE_HPP
