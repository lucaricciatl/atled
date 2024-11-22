#include "Line3D.hpp"

namespace graphics {

// Default constructor
Line3D::Line3D()
    : mStartPos({0.0f, 0.0f, 0.0f}),
      mEndPos({1.0f, 1.0f, 1.0f}) {}

// Parameterized constructor
Line3D::Line3D(const Vector3& start, const Vector3& end, const Color& color)
    : mStartPos(start), mEndPos(end) {}

// Override the draw function
void Line3D::Draw() {
    raylib::DrawLine3D(mStartPos, mEndPos, mColor);
}

// Setters
void Line3D::SetStartPos(const Vector3& start) {
    mStartPos = start;
}

void Line3D::SetEndPos(const Vector3& end) {
    mEndPos = end;
}


// Getters
Vector3 Line3D::GetStartPos() const {
    return mStartPos;
}

Vector3 Line3D::GetEndPos() const {
    return mEndPos;
}


}  // namespace graphics
