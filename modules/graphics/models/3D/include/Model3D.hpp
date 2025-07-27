#ifndef SHAPE3D_HPP
#define SHAPE3D_HPP

#include <Color.hpp>
#include <Palette.hpp>
#include <iostream>

#include "Model.hpp"
#include "raylib.hpp"

namespace graphics {

class Model3D : public Model {
   public:
    explicit Model3D() : ShapeIsEnabled(true) {};
    virtual ~Model3D() = default;
    virtual void Draw() = 0;

    void EnableWireframe();
    void DisableWireframe();
    void SetShader();
    void SetMaterial();
    // Enable wireframe rendering
    void EnableShape();
    void DisableShape();

    void SetWireframeColor(graphics::Color aColor);
    graphics::Color GetWireframeColor() const;
    // Setter for color
    void SetColor(const graphics::Color& color);
    void SetOrientation(const math::Quaternion& aOrientation) { mOrientation = aOrientation; }

    // Getter for color
    graphics::Color GetColor() const;

   protected:
    raylib::Vector3 ComputeGlobalPosition(math::Vector3 aPosition) {
        auto framepos = frame->GetPosition();
        raylib::Vector3 globalPosition = {(float)framepos->GetX() + aPosition.GetX(),
                                          (float)framepos->GetY() + aPosition.GetY(),
                                          (float)framepos->GetZ() + aPosition.GetZ()};
        return globalPosition;
    };

    math::Quaternion mOrientation;
    bool WireframeIsEnabled;  // 1 for the wirefram
    bool ShapeIsEnabled;      // 1 for the wirefram
    graphics::Color mWireframeColor;
    graphics::Color mColor;
    raylib::Model mModel;
};

}  // namespace graphics
#endif  // SHAPE_HPP
