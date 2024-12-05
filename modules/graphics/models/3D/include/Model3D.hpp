#ifndef SHAPE3D_HPP
#define SHAPE3D_HPP

#include <iostream>
#include "Model.hpp"
#include "raylib.hpp"

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
  void SetWireframeColor(raylib::Color aColor);
  raylib::Color GetWireframeColor() const;
  // Setter for color
  void SetColor(const raylib::Color& color);

  // Getter for color
  raylib::Color GetColor() const;


protected:

	raylib::Vector3 ComputeGlobalPosition(raylib::Vector3 aPosition) {
		auto framepos = frame->GetPosition();
		raylib::Vector3 globalPosition = {
			(float)framepos->getX() + aPosition.x,
			(float)framepos->getY() + aPosition.y,
			(float)framepos->getZ() + aPosition.z
		};
		return globalPosition;
	};

  bool WireframeIsEnabled;    // 1 for the wirefram
  bool ShapeIsEnabled;        // 1 for the wirefram
  raylib::Color mWireframeColor = raylib::Color(128, 128, 128, 128);      // Color of thr wireframe
  raylib::Color mColor = raylib::Color(64, 64, 64, 64);
};



}  // namespace graphics
#endif  // SHAPE_HPP

