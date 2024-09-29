#include "Camera3D.hpp"

// Constructor for Camera3D
rCamera3D::rCamera3D(Vector3 position, Vector3 target, Vector3 up, float fovy, int projection) {
    mCamera3D.position = position;
    mCamera3D.target = target;
    mCamera3D.up = up;
    mCamera3D.fovy = fovy;
    mCamera3D.projection = projection;
}

rCamera3D::rCamera3D() {
}

// Setters for Camera3D
void rCamera3D::setPosition(const Vector3& position) {
    mCamera3D.position = position;
}

void rCamera3D::setTarget(const Vector3& target) {
    mCamera3D.target = target;
}

void rCamera3D::setUp(const Vector3& up) {
    mCamera3D.up = up;
}

void rCamera3D::setFovy(float fovy) {
    mCamera3D.fovy = fovy;
}

// Getters for Camera3D
Vector3 rCamera3D::getPosition() const {
    return mCamera3D.position;
}

Vector3 rCamera3D::getTarget() const {
    return mCamera3D.target;
}

Vector3 rCamera3D::getUp() const {
    return mCamera3D.up;
}

float rCamera3D::getFovy() const {
    return mCamera3D.fovy;
}
