#include "RaylibCamera2D.hpp"

namespace graphics {

RaylibCamera2D::RaylibCamera2D(raylib::Vector2 offset, raylib::Vector2 target, float rotation, float zoom)
    : mCamera{offset, target, rotation, zoom} {}

void RaylibCamera2D::BeginCamera() {
    raylib::BeginMode2D(mCamera);
}

void RaylibCamera2D::EndCamera() {
    raylib::EndMode2D();
}

void RaylibCamera2D::SetPosition(raylib::Vector3 position) {
    mCamera.offset = {position.x, position.y};
}

void RaylibCamera2D::UpdateCamera() {
}

void RaylibCamera2D::SetFovy(float aFovy)
{
    
}

raylib::Vector3 RaylibCamera2D::GetPosition() const {
    return {mCamera.offset.x, mCamera.offset.y, 0.0f};
}

void RaylibCamera2D::SetTarget(raylib::Vector3 target) {
    mCamera.target = {target.x, target.y};
}

raylib::Vector3 RaylibCamera2D::GetTarget() const {
    return {mCamera.target.x, mCamera.target.y, 0.0f};
}

void RaylibCamera2D::SetUp(raylib::Vector3) {}

raylib::Vector3 RaylibCamera2D::GetUp() const {
    return {0.0f, 0.0f, 0.0f};
}

void RaylibCamera2D::SetZoom(float zoom) {
    mCamera.zoom = zoom;
}

float RaylibCamera2D::GetZoom() const {
    return mCamera.zoom;
}

void RaylibCamera2D::SetRotation(float rotation) {
    mCamera.rotation = rotation;
}

float RaylibCamera2D::GetRotation() const {
    return mCamera.rotation;
}

void RaylibCamera2D::SetCameraProjection(raylib::CameraProjection aProjection) {};
}  // namespace graphics
