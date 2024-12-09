#include "RaylibCamera3D.hpp"
#include "Vector3.hpp"

namespace graphics {

namespace{
typedef math::Vector3 Vector3;

namespace{
    raylib::Vector3 toRaylibVector3(math::Vector3 v){return {v.getX(),v.getY(),v.getZ()};}
    math::Vector3 toAtledVector3(raylib::Vector3 v){return Vector3(v.x,v.y,v.z);}
}

}

RaylibCamera3D::RaylibCamera3D(Vector3 position, Vector3 target, Vector3 up, float fovy, int projection)
    : mCamera{toRaylibVector3(position), toRaylibVector3(target), toRaylibVector3(up), fovy, projection} {}

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
    mCamera.position = toRaylibVector3(position);
    UpdateCamera();
}

Vector3 RaylibCamera3D::GetPosition() const {
    return toAtledVector3(mCamera.position);
}

void RaylibCamera3D::SetTarget(Vector3 target) {
    mCamera.target = toRaylibVector3(target);
    UpdateCamera();
}

Vector3 RaylibCamera3D::GetTarget() const {
    return toAtledVector3(mCamera.target);
}

void RaylibCamera3D::SetUp(Vector3 up) {
    mCamera.up = toRaylibVector3(up);
    UpdateCamera();
}

Vector3 RaylibCamera3D::GetUp() const {
    return toAtledVector3(mCamera.up);
}

void RaylibCamera3D::SetZoom(float) {}

float RaylibCamera3D::GetZoom() const {
    return 1.0f;  // Not applicable for Camera3D
}

void RaylibCamera3D::SetRotation(float) {}

float RaylibCamera3D::GetRotation() const {
    return 0.0f;  // Not applicable for Camera3D
}

void RaylibCamera3D::SetCameraProjection(raylib::CameraProjection aProjection) {
    mCamera.projection = aProjection;
};



}  // namespace graphics
