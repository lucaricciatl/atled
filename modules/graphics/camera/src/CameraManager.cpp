#include "CameraManager.hpp"
#include <chrono>
#include <thread>
#include <iostream>
#include "Vector3.hpp"
namespace graphics {

CameraManager::CameraManager() : mRunning(false), mActiveCamera(nullptr) {}

CameraManager::~CameraManager() {
    Stop();
}

void CameraManager::AddCamera(std::shared_ptr<ICamera> camera) {
    mCameras.emplace_back(camera);
    if (!mActiveCamera) {
        mActiveCamera = camera;
    }
}

void CameraManager::SetActiveCamera(size_t index) {
    if (index < mCameras.size()) {
        mActiveCamera = mCameras[index];
    }
}

std::shared_ptr<ICamera> CameraManager::GetActiveCamera() const {
    return mActiveCamera;
}

void CameraManager::Start() {
    mRunning = true;

}

void CameraManager::Stop() {
    mRunning = false;
}

void CameraManager::UpdateCameras() {
    for (auto& camera : mCameras) {
        if (camera) {
            camera->BeginCamera();
        }
    }
}

void CameraManager::SetCameraPosition(const math::Vector3& aPosition) {
    mActiveCamera->SetPosition(aPosition);
}

void CameraManager::SetCameraTarget(const math::Vector3& aTarget) {
    mActiveCamera->SetTarget(aTarget);
}


math::Vector3 CameraManager::GetCameraPosition() const {
    return mActiveCamera->GetPosition();
}

math::Vector3 CameraManager::GetCameraTarget() const {
    return mActiveCamera->GetTarget();
}
void CameraManager::BeginActiveCamera() {
    mActiveCamera->BeginCamera();     
}

void CameraManager::EndActiveCamera() {
    mActiveCamera->EndCamera();
}

void CameraManager::SetCameraRotation(float rotation) {
    if (mActiveCamera) mActiveCamera->SetRotation(rotation);
}

void CameraManager::SetCameraZoom(float zoom) {
    if (mActiveCamera) mActiveCamera->SetZoom(zoom);
}

float CameraManager::GetCameraRotation() const {
    return mActiveCamera ? mActiveCamera->GetRotation() : 0.0f;
}

float CameraManager::GetCameraZoom() const {
    return mActiveCamera ? mActiveCamera->GetZoom() : 1.0f;
}

void CameraManager::SetCameraTargetY(float target) {
    if (mActiveCamera) {
        mActiveCamera->SetTarget(math::Vector3( mActiveCamera->GetTarget().getX(), target, mActiveCamera->GetTarget().getZ() ));
    }
}

void CameraManager::SetCameraOffsetX(float offset) {
    if (mActiveCamera) {
        mActiveCamera->SetPosition(math::Vector3{ offset, mActiveCamera->GetPosition().getY(), mActiveCamera->GetPosition().getZ() });
    }
}

void CameraManager::SetCameraOffsetY(float offset) {
    if (mActiveCamera) {
        mActiveCamera->SetPosition(math::Vector3{ mActiveCamera->GetPosition().getX(), offset, mActiveCamera->GetPosition().getZ() });
    }
}

float CameraManager::GetCameraTargetY() const {
    if (mActiveCamera) {
        return mActiveCamera->GetTarget().getY();
    }
    return 0.0f;
}

float CameraManager::GetCameraOffsetX() const {
    if (mActiveCamera) {
        return mActiveCamera->GetPosition().getX();
    }
    return 0.0f;
}

void CameraManager::SetFovy(float aFovy) {
    mActiveCamera->SetFovy(aFovy);
}

float CameraManager::GetCameraOffsetY() const {
    if (mActiveCamera) {
        return mActiveCamera->GetPosition().getY();
    }
    return 0.0f;
}

void CameraManager::SetCameraTargetX(float target) {
    if (mActiveCamera) {
        auto currentTarget = mActiveCamera->GetTarget();
        mActiveCamera->SetTarget(math::Vector3{ target, currentTarget.getY(), currentTarget.getZ() });
    }
}

float CameraManager::GetCameraTargetX() const {
    if (mActiveCamera) {
        return mActiveCamera->GetTarget().getX();  // Access the active camera's target X
    }
    return 0.0f;  // Return a default value if no active camera is set
}

void CameraManager::SetCameraProjection(raylib::CameraProjection aProjection) {
    if (mActiveCamera) {
        mActiveCamera->SetCameraProjection(aProjection);
    }
}
}  // namespace graphics
