#include "CameraManager.hpp"
#include <chrono>
#include <thread>

namespace graphics {

CameraManager::CameraManager() : mRunning(false), mActiveCamera(nullptr) {}

CameraManager::~CameraManager() {
    Stop();
}

void CameraManager::AddCamera(std::shared_ptr<CameraBase> camera) {
    mCameras.push_back(camera);
    if (!mActiveCamera) {
        mActiveCamera = camera;
    }
}

void CameraManager::SetActiveCamera(size_t index) {
    if (index < mCameras.size()) {
        mActiveCamera = mCameras[index];
    }
}

std::shared_ptr<CameraBase> CameraManager::GetActiveCamera() const {
    return mActiveCamera;
}

void CameraManager::Start() {
    mRunning = true;
    mThread = std::make_unique<std::thread>(&CameraManager::RenderLoop, this);
}

void CameraManager::Stop() {
    mRunning = false;
    if (mThread && mThread->joinable()) {
        mThread->join();
    }
}

void CameraManager::UpdateCameras() {
    for (auto& camera : mCameras) {
        if (camera) {
            camera->BeginCamera();
        }
    }
}

void CameraManager::RenderActiveCamera() {
    if (mActiveCamera) {
        mActiveCamera->BeginCamera();
    }
}

void CameraManager::RenderLoop() {
    while (mRunning) {
        RenderActiveCamera();
        std::this_thread::sleep_for(std::chrono::milliseconds(16));  // Approx. 60 FPS
    }
}

void CameraManager::SetCameraOffsetX(float offset) {
    if (mActiveCamera) mActiveCamera->SetOffsetX(offset);
}

void CameraManager::SetCameraOffsetY(float offset) {
    if (mActiveCamera) mActiveCamera->SetOffsetY(offset);
}

void CameraManager::SetCameraTargetX(float target) {
    if (mActiveCamera) mActiveCamera->SetTargetX(target);
}

void CameraManager::SetCameraTargetY(float target) {
    if (mActiveCamera) mActiveCamera->SetTargetY(target);
}

void CameraManager::SetCameraRotation(float rotation) {
    if (mActiveCamera) mActiveCamera->SetRotation(rotation);
}

void CameraManager::SetCameraZoom(float zoom) {
    if (mActiveCamera) mActiveCamera->SetZoom(zoom);
}

float CameraManager::GetCameraOffsetX() const {
    return mActiveCamera ? mActiveCamera->GetOffsetX() : 0.0f;
}

float CameraManager::GetCameraOffsetY() const {
    return mActiveCamera ? mActiveCamera->GetOffsetY() : 0.0f;
}

float CameraManager::GetCameraTargetX() const {
    return mActiveCamera ? mActiveCamera->GetTargetX() : 0.0f;
}

float CameraManager::GetCameraTargetY() const {
    return mActiveCamera ? mActiveCamera->GetTargetY() : 0.0f;
}

float CameraManager::GetCameraRotation() const {
    return mActiveCamera ? mActiveCamera->GetRotation() : 0.0f;
}

float CameraManager::GetCameraZoom() const {
    return mActiveCamera ? mActiveCamera->GetZoom() : 1.0f;
}

}  // namespace graphics
