#include "Camera2D.hpp"

// Constructor for mCamera2D
rCamera2D::rCamera2D(Vector2 offset, Vector2 target, float rotation, float zoom) {
    mCamera2D.offset = offset;
    mCamera2D.target = target;
    mCamera2D.rotation = rotation;
    mCamera2D.zoom = zoom;
}

// Constructor for mCamera2D
rCamera2D::rCamera2D() {
}

// Implement printCameraInfo for mCamera2D
void rCamera2D::printCameraInfo() const {
    std::cout << "mCamera2D Info - Offset: ("
              << mCamera2D.offset.x << ", "
              << mCamera2D.offset.y << "), Target: ("
              << mCamera2D.target.x << ", "
              << mCamera2D.target.y << ")\n";
}

// Setters for mCamera2D
void rCamera2D::setOffset(const Vector2& offset) {
    mCamera2D.offset = offset;
}

void rCamera2D::setTarget(const Vector2& target) {
    mCamera2D.target = target;
}

void rCamera2D::setRotation(float rotation) {
    mCamera2D.rotation = rotation;
}

void rCamera2D::setZoom(float zoom) {
    mCamera2D.zoom = zoom;
}

// Getters for mCamera2D
Vector2 rCamera2D::getOffset() const {
    return mCamera2D.offset;
}

Vector2 rCamera2D::getTarget() const {
    return mCamera2D.target;
}

float rCamera2D::getRotation() const {
    return mCamera2D.rotation;
}

float rCamera2D::getZoom() const {
    return mCamera2D.zoom;
}
