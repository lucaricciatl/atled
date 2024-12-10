#ifndef PLANE_HPP
#define PLANE_HPP

#include "Model3D.hpp"
#include "raylib.hpp"  // For Vector3, Vector2, and Color types
#include "Color.hpp"

namespace graphics {
using namespace math;

class Plane : public Model3D {
public:
    // Constructors
    Plane();
    Plane(const math::Vector3& centerPos, const raylib::Vector2& size, const Color& aColor);

    // Override draw function
    void Draw() override;

    // Setters
    void SetCenterPos(const math::Vector3& centerPos);
    void SetSize(const raylib::Vector2& size);

    // Getters
    math::Vector3 GetCenterPos() const;
    raylib::Vector2 GetSize() const;

private:
    void UpdateMesh();

    math::Vector3 mCenterPos; // Center position of the plane
    raylib::Vector2 mSize;      // Size of the plane

    raylib::Model mModel;
    Color mColor;
};

}  // namespace graphics

#endif  // PLANE_HPP
