#include "RaylibCamera2D.hpp"

// Default constructor
RaylibCamera2D::RaylibCamera2D() {
    mCamera2D.offset = {0.0f, 0.0f};
    mCamera2D.target = {0.0f, 0.0f};
    mCamera2D.rotation = 0.0f;
    mCamera2D.zoom = 1.0f;
}

// Parameterized constructor
RaylibCamera2D::RaylibCamera2D(Vector2 offset, Vector2 target, float rotation, float zoom) {
    mCamera2D.offset = offset;
    mCamera2D.target = target;
    mCamera2D.rotation = rotation;
    mCamera2D.zoom = zoom;
}

// Setters
void RaylibCamera2D::SetOffsetX(const float& offset) {
    mCamera2D.offset.x = offset;
}

void RaylibCamera2D::SetOffsetY(const float& offset) {
    mCamera2D.offset.y = offset;
}

void RaylibCamera2D::SetTargetX(const float& target) {
    mCamera2D.target.x = target;
}

void RaylibCamera2D::SetTargetY(const float& target) {
    mCamera2D.target.y = target;
}

void RaylibCamera2D::SetRotation(const float& rotation) {
    mCamera2D.rotation = rotation;
}

void RaylibCamera2D::SetZoom(const float& zoom) {
    mCamera2D.zoom = zoom;
}

// Getters
float RaylibCamera2D::GetOffsetX() const {
    return mCamera2D.offset.x;
}

float RaylibCamera2D::GetOffsetY() const {
    return mCamera2D.offset.y;
}

float RaylibCamera2D::GetTargetX() const {
    return mCamera2D.target.x;
}

float RaylibCamera2D::GetTargetY() const {
    return mCamera2D.target.y;
}

float RaylibCamera2D::GetRotation() const {
    return mCamera2D.rotation;
}

float RaylibCamera2D::GetZoom() const {
    return mCamera2D.zoom;
}

// Methods to increase offsets and zoom
void RaylibCamera2D::IncreaseOffsetX(const float& deltaX) {
    mCamera2D.offset.x += deltaX;
}

void RaylibCamera2D::IncreaseOffsetY(const float& deltaY) {
    mCamera2D.offset.y += deltaY;
}

void RaylibCamera2D::IncreaseOffset(const float& deltaX, const float& deltaY) {
    IncreaseOffsetX(deltaX);
    IncreaseOffsetY(deltaY);
}

void RaylibCamera2D::IncreaseZoom(const float& deltaZoom) {
    SetZoom(mCamera2D.zoom + deltaZoom);
}

// Begin camera mode
void RaylibCamera2D::BeginCamera() {
    BeginMode2D(mCamera2D);  // Assuming Raylib's BeginMode2D function is used here
}
