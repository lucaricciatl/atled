#include "Plane.hpp"

namespace graphics {

// Default constructor
Plane::Plane()
    : mCenterPos({0.0f, 0.0f, 0.0f}),
      mSize({10.0f, 10.0f}) {}

// Parameterized constructor
Plane::Plane(const raylib::Vector3& centerPos, const raylib::Vector2& size, const raylib::Color& color)
    : mCenterPos(centerPos), mSize(size){}

// Override draw method
void Plane::Draw() {
    auto gPos = ComputeGlobalPosition(mCenterPos);
    raylib::DrawPlane(gPos, mSize, mColor);
    raylib::DrawGrid(mSize.x, 1);
}

// Setter for center position
void Plane::SetCenterPos(const raylib::Vector3& centerPos) {
    mCenterPos = centerPos;
}

// Setter for size
void Plane::SetSize(const raylib::Vector2& size) {
    mSize = size;
}

// Getter for center position
raylib::Vector3 Plane::GetCenterPos() const {
    return mCenterPos;
}

// Getter for size
raylib::Vector2 Plane::GetSize() const {
    return mSize;
}

}  // namespace graphics
