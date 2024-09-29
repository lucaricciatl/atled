#include "Camera2D.hpp"

// Constructor for rCamera2D
rCamera2D::rCamera2D() {
    // You can initialize any values for mCamera2D here if needed.
}

// Setters for mCamera2D
void rCamera2D::setOffset(const Vector2& offset) {
    mCamera2D.offset = offset;
}

void rCamera2D::setTarget(const Vector2& target) {  // Correct the name to setTarget
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

void rCamera2D::BeginCamera() {
    BeginMode2D(mCamera2D);
}
