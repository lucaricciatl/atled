#include "Camera2D.hpp"

// Default constructor
rCamera2D::rCamera2D() {
    mCamera2D.offset = {0.0f, 0.0f};
    mCamera2D.target = {0.0f, 0.0f};
    mCamera2D.rotation = 0.0f;
    mCamera2D.zoom = 1.0f;
}

// Parameterized constructor
rCamera2D::rCamera2D(Vector2 offset, Vector2 target, float rotation, float zoom) {
    mCamera2D.offset = offset;
    mCamera2D.target = target;
    mCamera2D.rotation = rotation;
    mCamera2D.zoom = zoom;
}

// Setters
void rCamera2D::SetOffsetX(const float& offset) {
    mCamera2D.offset.x = offset;
}

void rCamera2D::SetOffsetY(const float& offset) {
    mCamera2D.offset.y = offset;
}

void rCamera2D::SetTargetX(const float& target) {
    mCamera2D.target.x = target;
}

void rCamera2D::SetTargetY(const float& target) {
    mCamera2D.target.y = target;
}

void rCamera2D::SetRotation(const float& rotation) {
    mCamera2D.rotation = rotation;
}

void rCamera2D::SetZoom(const float& zoom) {
    mCamera2D.zoom = zoom;
}

// Getters
float rCamera2D::GetOffsetX() const {
    return mCamera2D.offset.x;
}

float rCamera2D::GetOffsetY() const {
    return mCamera2D.offset.y;
}

float rCamera2D::GetTargetX() const {
    return mCamera2D.target.x;
}

float rCamera2D::GetTargetY() const {
    return mCamera2D.target.y;
}

float rCamera2D::GetRotation() const {
    return mCamera2D.rotation;
}

float rCamera2D::GetZoom() const {
    return mCamera2D.zoom;
}

// Methods to increase offsets and zoom
void rCamera2D::IncreaseOffsetX(const float& deltaX) {
    mCamera2D.offset.x += deltaX;
}

void rCamera2D::IncreaseOffsetY(const float& deltaY) {
    mCamera2D.offset.y += deltaY;
}

void rCamera2D::IncreaseOffset(const float& deltaX, const float& deltaY) {
    IncreaseOffsetX(deltaX);
    IncreaseOffsetY(deltaY);
}

void rCamera2D::IncreaseZoom(const float& deltaZoom) {
    mCamera2D.zoom += deltaZoom;
}

// Begin camera mode
void rCamera2D::BeginCamera() {
    BeginMode2D(mCamera2D);  // Assuming Raylib's BeginMode2D function is used here
}
