#include "Line3D.hpp"

namespace graphics {

// Default constructor
Line3D::Line3D()
    : mStartPos({0.0f, 0.0f, 0.0f}),
      mEndPos({1.0f, 1.0f, 1.0f}) {}

// Parameterized constructor
Line3D::Line3D(const raylib::Vector3& start, const raylib::Vector3& end, const raylib::Color& color)
    : mStartPos(start), mEndPos(end) {}

// Override the draw function
void Line3D::Draw() {
        
    raylib::DrawLine3D(ComputeGlobalPosition(mStartPos)
        , ComputeGlobalPosition(mEndPos), mColor);
}

// Setters
void Line3D::SetStartPos(const raylib::Vector3& start) {
    mStartPos = start;
}

void Line3D::SetEndPos(const raylib::Vector3& end) {
    mEndPos = end;
}


// Getters
raylib::Vector3 Line3D::GetStartPos() const {
    return mStartPos;
}

raylib::Vector3 Line3D::GetEndPos() const {
    return mEndPos;
}


}  // namespace graphics
