#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "Model3D.hpp"
#include "raylib.h"  // Assuming raylib is used for the Vector3 and Color types

namespace graphics {

class Sphere : public Model,public Model3D {
public:
    // Constructor with default radius
    Sphere(float radius = 1.0f) : mRadius(radius), mCenterPos{ 0.0f, 0.0f, 0.0f }, mColor{ 255, 255, 255, 255 } {};

    // Override draw function
    void Draw() override;

    // Setter for radius
    void SetRadius(float radius) { mRadius = radius; }
    // Getter for radius
    float GetRadius() const { return mRadius; }

    // Setter for center position
    void SetCenterPos(const Vector3& centerPos) { mCenterPos = centerPos; }
    // Getter for center position
    Vector3 GetCenterPos() const { return mCenterPos; }

    // Setter for color
    void SetColor(const Color& color) { mColor = color; }
    // Getter for color
    Color GetColor() const { return mColor; }

private:
    float mRadius;      // Radius of the sphere
    Vector3 mCenterPos; // Center position of the sphere
    Color mColor;       // Color of the sphere
};

}  // namespace graphics

#endif  // SPHERE_HPP
