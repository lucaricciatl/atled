#ifndef PLANE_HPP
#define PLANE_HPP

#include "Model3D.hpp"
#include "raylib.h"  // For Vector3, Vector2, and Color types

namespace graphics {

class Plane : public Model,public Model3D {
public:
    // Constructors
    Plane();
    Plane(const Vector3& centerPos, const Vector2& size, const Color& color);

    // Override draw function
    void Draw() override;

    // Setters
    void SetCenterPos(const Vector3& centerPos);
    void SetSize(const Vector2& size);

    // Getters
    Vector3 GetCenterPos() const;
    Vector2 GetSize() const;

private:
    Vector3 mCenterPos; // Center position of the plane
    Vector2 mSize;      // Size of the plane
};

}  // namespace graphics

#endif  // PLANE_HPP
