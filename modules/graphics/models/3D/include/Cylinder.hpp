#ifndef CYLINDER_HPP
#define CYLINDER_HPP

#include "Model3D.hpp"
#include "raylib.h"  // For Vector3 and Color types

namespace graphics {

class Cylinder :public Model, public Model3D {
public:
    // Constructors
    Cylinder();
    Cylinder(const Vector3& startPos, const Vector3& endPos, float startRadius, float endRadius, int sides);

    // Override draw function
    void Draw() override;

    // Setters
    void SetStartPos(const Vector3& startPos);
    void SetEndPos(const Vector3& endPos);
    void SetStartRadius(float startRadius);
    void SetEndRadius(float endRadius);
    void SetSides(int sides);

    // Getters
    Vector3 GetStartPos() const;
    Vector3 GetEndPos() const;
    float GetStartRadius() const;
    float GetEndRadius() const;
    int GetSides() const;

private:
    Vector3 mStartPos;    // Start position of the cylinder base
    Vector3 mEndPos;      // End position of the cylinder top
    float mStartRadius;   // Radius of the cylinder base
    float mEndRadius;     // Radius of the cylinder top
    int mSides;           // Number of sides for the cylinder
};

}  // namespace graphics

#endif  // CYLINDER_HPP
