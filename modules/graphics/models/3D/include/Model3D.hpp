#ifndef SHAPE3D_HPP
#define SHAPE3D_HPP

#include <iostream>
#include "Model.hpp"
#include "raylib.hpp"
#include <Color.hpp>
#include <Palette.hpp>

namespace graphics {

class Model3D : public Model{
 public:
  virtual ~Model3D() = default;
  virtual void Draw() = 0;

  void EnableWireframe();
  void DisableWireframe();

  // Enable wireframe rendering
  void EnableShape();
  void DisableShape();
  void SetWireframeColor(graphics::Color aColor);
  graphics::Color GetWireframeColor() const;
  // Setter for color
  void SetColor(const graphics::Color& color);

  // Getter for color
  graphics::Color GetColor() const;


protected:

	  raylib::Vector3 ComputeGlobalPosition(math::Vector3 aPosition) {
		auto framepos = frame->GetPosition();
		raylib::Vector3 globalPosition = {
			(float)framepos->getX() + aPosition.getX(),
			(float)framepos->getY() + aPosition.getY(),
			(float)framepos->getZ() + aPosition.getZ()
		};
		return globalPosition;
	};

  bool WireframeIsEnabled;    // 1 for the wirefram
  bool ShapeIsEnabled;        // 1 for the wirefram
  graphics::Color mWireframeColor;
  graphics::Color mColor;
};



}  // namespace graphics
#endif  // SHAPE_HPP

