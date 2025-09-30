#include "CameraManager.hpp"
#include <chrono>
#include <thread>
#include <iostream>
#include <cassert>
#include "Vector3.hpp"
namespace graphics {

CameraManager::CameraManager() : mRunning(false), mActiveCamera(nullptr) {}

CameraManager::~CameraManager() {
    Stop();
}

void CameraManager::AddCamera(std::shared_ptr<ICamera> aCamera) {
    mCameras.emplace_back(aCamera);
    if (!mActiveCamera) {
        mActiveCamera = aCamera;
    }
}

void CameraManager::SetActiveCamera(size_t aIndex) {
    if (aIndex < mCameras.size()) {
        mActiveCamera = mCameras[aIndex];
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
    if (mActiveCamera) {
        mActiveCamera->BeginCamera();     
    }
    else {
        assert(false && "No active camera set.");
    }
}

void CameraManager::EndActiveCamera() {
    if (mActiveCamera) {
        mActiveCamera->EndCamera();
    }
    else {
        assert(false && "No active camera set.");
    }
}

void CameraManager::SetCameraRotation(float aRotation) {
    if (mActiveCamera) mActiveCamera->SetRotation(aRotation);
}

void CameraManager::SetCameraZoom(float aZoom) {
    if (mActiveCamera) mActiveCamera->SetZoom(aZoom);
}

float CameraManager::GetCameraRotation() const {
    return mActiveCamera ? mActiveCamera->GetRotation() : 0.0f;
}

float CameraManager::GetCameraZoom() const {
    return mActiveCamera ? mActiveCamera->GetZoom() : 1.0f;
}

void CameraManager::SetCameraTargetY(float aTarget) {
    if (mActiveCamera) {
        mActiveCamera->SetTarget(
            math::Vector3(mActiveCamera->GetTarget().GetX(), aTarget, mActiveCamera->GetTarget().GetZ()));
    }
}

void CameraManager::SetCameraOffsetX(float aOffset) {
    if (mActiveCamera) {
        mActiveCamera->SetPosition(
            math::Vector3{aOffset, mActiveCamera->GetPosition().GetY(), mActiveCamera->GetPosition().GetZ()});
    }
}

void CameraManager::SetCameraOffsetY(float aOffset) {
    if (mActiveCamera) {
        mActiveCamera->SetPosition(
            math::Vector3{mActiveCamera->GetPosition().GetX(), aOffset, mActiveCamera->GetPosition().GetZ()});
    }
}

float CameraManager::GetCameraTargetY() const {
    if (mActiveCamera) {
        return mActiveCamera->GetTarget().GetY();
    }
    return 0.0f;
}

float CameraManager::GetCameraOffsetX() const {
    if (mActiveCamera) {
        return mActiveCamera->GetPosition().GetX();
    }
    return 0.0f;
}

void CameraManager::SetFovy(float aFovy) {
    mActiveCamera->SetFovy(aFovy);
}

float CameraManager::GetCameraOffsetY() const {
    if (mActiveCamera) {
        return mActiveCamera->GetPosition().GetY();
    }
    return 0.0f;
}

void CameraManager::SetCameraTargetX(float aTarget) {
    if (mActiveCamera) {
        auto currentTarget = mActiveCamera->GetTarget();
        mActiveCamera->SetTarget(math::Vector3{aTarget, currentTarget.GetY(), currentTarget.GetZ()});
    }
}

float CameraManager::GetCameraTargetX() const {
    if (mActiveCamera) {
        return mActiveCamera->GetTarget().GetX();  // Access the active camera's target X
    }
    return 0.0f;  // Return a default value if no active camera is set
}

void CameraManager::SetCameraProjection(raylib::CameraProjection aProjection) {
    if (mActiveCamera) {
        mActiveCamera->SetCameraProjection(aProjection);
    }
}
}  // namespace graphics
