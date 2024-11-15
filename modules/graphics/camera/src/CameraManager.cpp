#include "CameraManager.hpp"
#include <chrono>
#include <thread>

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
        mActiveCamera->SetTarget(Vector3{ mActiveCamera->GetTarget().x, target, mActiveCamera->GetTarget().z });
    }
}

void CameraManager::SetCameraOffsetX(float offset) {
    if (mActiveCamera) {
        mActiveCamera->SetPosition(Vector3{ offset, mActiveCamera->GetPosition().y, mActiveCamera->GetPosition().z });
    }
}

void CameraManager::SetCameraOffsetY(float offset) {
    if (mActiveCamera) {
        mActiveCamera->SetPosition(Vector3{ mActiveCamera->GetPosition().x, offset, mActiveCamera->GetPosition().z });
    }
}

float CameraManager::GetCameraTargetY() const {
    if (mActiveCamera) {
        return mActiveCamera->GetTarget().y;
    }
    return 0.0f;
}

float CameraManager::GetCameraOffsetX() const {
    if (mActiveCamera) {
        return mActiveCamera->GetPosition().x;
    }
    return 0.0f;
}

float CameraManager::GetCameraOffsetY() const {
    if (mActiveCamera) {
        return mActiveCamera->GetPosition().y;
    }
    return 0.0f;
}

void CameraManager::SetCameraTargetX(float target) {
    if (mActiveCamera) {
        auto currentTarget = mActiveCamera->GetTarget();
        mActiveCamera->SetTarget(Vector3{ target, currentTarget.y, currentTarget.z });
    }
}

float CameraManager::GetCameraTargetX() const {
    if (mActiveCamera) {
        return mActiveCamera->GetTarget().x;  // Access the active camera's target X
    }
    return 0.0f;  // Return a default value if no active camera is set
}

}  // namespace graphics
