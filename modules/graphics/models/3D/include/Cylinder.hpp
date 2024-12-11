#ifndef CYLINDER_HPP
#define CYLINDER_HPP

#include "Model3D.hpp"
#include "raylib.hpp"  // For Vector3 and Color types

namespace graphics {
using namespace math;
class Cylinder : public Model3D {
public:
    // Constructors
    Cylinder();
    Cylinder(const math::Vector3 &aPos, float aRadius,float height, int sides,graphics::Color aColor);

    // Override draw function
    void Draw() override;

    // Setters
    void SetPos(const math::Vector3& startPos);
    void SetRadius(float radius);

    void SetSides(int sides);

    // Getters
    math::Vector3 GetPos() const;
    float GetRadius() const;

    int GetSides() const;


private:

    void UpdateMesh();
    graphics::Color mColor;
    float mHeight;
    math::Vector3 mPos;    // Start position of the cylinder base
    float mRadius;     // Radius of the cylinder top
    int mSides;           // Number of sides for the cylinder
    raylib::Model mModel;
};

}  // namespace graphics

#endif  // CYLINDER_HPP
