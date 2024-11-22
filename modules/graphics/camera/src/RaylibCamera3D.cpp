#include "RaylibCamera3D.hpp"

namespace graphics {

RaylibCamera3D::RaylibCamera3D(Vector3 position, Vector3 target, Vector3 up, float fovy, int projection)
    : mCamera{position, target, up, fovy, projection} {}

void RaylibCamera3D::BeginCamera() {
    raylib::BeginMode3D(mCamera);
}

void RaylibCamera3D::UpdateCamera() {
    // Use Raylib's UpdateCamera to update the internal mCamera
    raylib::UpdateCamera(&mCamera, 0);
}

void RaylibCamera3D::EndCamera() {
    raylib::EndMode3D();
}

void RaylibCamera3D::SetFovy(float aFovy) {
    mCamera.fovy = aFovy;
}

void RaylibCamera3D::SetPosition(Vector3 position) {
    mCamera.position = position;
    UpdateCamera();
}

Vector3 RaylibCamera3D::GetPosition() const {
    return mCamera.position;
}

void RaylibCamera3D::SetTarget(Vector3 target) {
    mCamera.target = target;
    UpdateCamera();
}

Vector3 RaylibCamera3D::GetTarget() const {
    return mCamera.target;
}

void RaylibCamera3D::SetUp(Vector3 up) {
    mCamera.up = up;
    UpdateCamera();
}

Vector3 RaylibCamera3D::GetUp() const {
    return mCamera.up;
}

void RaylibCamera3D::SetZoom(float) {}

float RaylibCamera3D::GetZoom() const {
    return 1.0f;  // Not applicable for Camera3D
}

void RaylibCamera3D::SetRotation(float) {}

float RaylibCamera3D::GetRotation() const {
    return 0.0f;  // Not applicable for Camera3D
}

void RaylibCamera3D::SetCameraProjection(CameraProjection aProjection) {
    mCamera.projection = aProjection;
};



}  // namespace graphics
