#include "Cube.hpp"

namespace graphics {

Cube::Cube(float width, float height, float length)
    : mDimensions{width, height, length}, mCenterPos{0.0f, 0.0f, 0.0f}, mColor{255, 255, 255, 255} {}

void Cube::Draw() {
    // Use raylib's DrawCube function to render the cube
    ::DrawCube(mCenterPos, mDimensions.x, mDimensions.y, mDimensions.z, mColor);
}

// Setters for dimensions
void Cube::SetWidth(float width) {
    mDimensions.x = width;
}

void Cube::SetHeight(float height) {
    mDimensions.y = height;
}

void Cube::SetLength(float length) {
    mDimensions.z = length;
}

// Getters for dimensions
float Cube::GetWidth() const {
    return mDimensions.x;
}

float Cube::GetHeight() const {
    return mDimensions.y;
}

float Cube::GetLength() const {
    return mDimensions.z;
}

// Setter for center position
void Cube::SetCenterPos(const Vector3& centerPos) {
    mCenterPos = centerPos;
}

// Getter for center position
Vector3 Cube::GetCenterPos() const {
    return mCenterPos;
}

// Setter for color
void Cube::SetColor(const Color& color) {
    mColor = color;
}

// Getter for color
Color Cube::GetColor() const {
    return mColor;
}

}  // namespace graphics
