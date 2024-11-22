#include "Cylinder.hpp"

namespace graphics {

// Default constructor
Cylinder::Cylinder()
    : mStartPos({0.0f, 0.0f, 0.0f}),
      mEndPos({0.0f, 1.0f, 0.0f}),
      mStartRadius(0.5f),
      mEndRadius(0.5f),
      mSides(16) {}

// Parameterized constructor
Cylinder::Cylinder(const Vector3& startPos, const Vector3& endPos, float startRadius, float endRadius, int sides)
    : mStartPos(startPos), mEndPos(endPos), mStartRadius(startRadius), mEndRadius(endRadius), mSides(sides) {}

// Override draw method
void Cylinder::Draw() {
    raylib::DrawCylinderWiresEx(mStartPos, mEndPos, mStartRadius, mEndRadius, mSides, mColor);
}

// Setter for start position
void Cylinder::SetStartPos(const Vector3& startPos) {
    mStartPos = startPos;
}

// Setter for end position
void Cylinder::SetEndPos(const Vector3& endPos) {
    mEndPos = endPos;
}

// Setter for start radius
void Cylinder::SetStartRadius(float startRadius) {
    mStartRadius = startRadius;
}

// Setter for end radius
void Cylinder::SetEndRadius(float endRadius) {
    mEndRadius = endRadius;
}

// Setter for sides
void Cylinder::SetSides(int sides) {
    mSides = sides;
}

// Getter for start position
Vector3 Cylinder::GetStartPos() const {
    return mStartPos;
}

// Getter for end position
Vector3 Cylinder::GetEndPos() const {
    return mEndPos;
}

// Getter for start radius
float Cylinder::GetStartRadius() const {
    return mStartRadius;
}

// Getter for end radius
float Cylinder::GetEndRadius() const {
    return mEndRadius;
}

// Getter for sides
int Cylinder::GetSides() const {
    return mSides;
}

}  // namespace graphics
