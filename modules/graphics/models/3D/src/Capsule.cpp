#include "Capsule.hpp"

namespace graphics {

// Default constructor
Capsule::Capsule()
    : mStartPos({0.0f, 0.0f, 0.0f}),
      mEndPos({0.0f, 1.0f, 0.0f}),
      mRadius(0.5f),
      mSlices(16),
      mRings(8) {}

// Parameterized constructor
Capsule::Capsule(const Vector3& startPos, const Vector3& endPos, float radius, int slices, int rings)
    : mStartPos(startPos), mEndPos(endPos), mRadius(radius), mSlices(slices), mRings(rings) {}

// Override draw method
void Capsule::Draw() {
    raylib::DrawCapsule(mStartPos, mEndPos, mRadius, mSlices, mRings, mColor);
}

// Setter for start position
void Capsule::SetStartPos(const Vector3& startPos) {
    mStartPos = startPos;
}

// Setter for end position
void Capsule::SetEndPos(const Vector3& endPos) {
    mEndPos = endPos;
}

// Setter for radius
void Capsule::SetRadius(float radius) {
    mRadius = radius;
}

// Setter for slices
void Capsule::SetSlices(int slices) {
    mSlices = slices;
}

// Setter for rings
void Capsule::SetRings(int rings) {
    mRings = rings;
}

// Getter for start position
Vector3 Capsule::GetStartPos() const {
    return mStartPos;
}

// Getter for end position
Vector3 Capsule::GetEndPos() const {
    return mEndPos;
}

// Getter for radius
float Capsule::GetRadius() const {
    return mRadius;
}

// Getter for slices
int Capsule::GetSlices() const {
    return mSlices;
}

// Getter for rings
int Capsule::GetRings() const {
    return mRings;
}


}  // namespace graphics
