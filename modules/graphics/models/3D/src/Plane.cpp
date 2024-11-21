#include "Plane.hpp"

namespace graphics {

// Default constructor
Plane::Plane()
    : mCenterPos({0.0f, 0.0f, 0.0f}),
      mSize({10.0f, 10.0f}) {}

// Parameterized constructor
Plane::Plane(const Vector3& centerPos, const Vector2& size, const Color& color)
    : mCenterPos(centerPos), mSize(size){}

// Override draw method
void Plane::Draw() {
    ::DrawPlane(mCenterPos, mSize, mColor);
     DrawGrid(mSize.x, 1);
}

// Setter for center position
void Plane::SetCenterPos(const Vector3& centerPos) {
    mCenterPos = centerPos;
}

// Setter for size
void Plane::SetSize(const Vector2& size) {
    mSize = size;
}

// Getter for center position
Vector3 Plane::GetCenterPos() const {
    return mCenterPos;
}

// Getter for size
Vector2 Plane::GetSize() const {
    return mSize;
}

}  // namespace graphics
