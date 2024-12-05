#ifndef PLANE_HPP
#define PLANE_HPP

#include "Model3D.hpp"
#include "raylib.hpp"  // For Vector3, Vector2, and Color types

namespace graphics {

class Plane : public Model3D {
public:
    // Constructors
    Plane();
    Plane(const raylib::Vector3& centerPos, const raylib::Vector2& size, const raylib::Color& aColor);

    // Override draw function
    void Draw() override;

    // Setters
    void SetCenterPos(const raylib::Vector3& centerPos);
    void SetSize(const raylib::Vector2& size);

    // Getters
    raylib::Vector3 GetCenterPos() const;
    raylib::Vector2 GetSize() const;

private:
    void UpdateMesh();

    raylib::Vector3 mCenterPos; // Center position of the plane
    raylib::Vector2 mSize;      // Size of the plane

    raylib::Model mModel;
    raylib::Color mColor;
};

}  // namespace graphics

#endif  // PLANE_HPP
