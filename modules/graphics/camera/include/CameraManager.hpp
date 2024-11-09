#pragma once

#include <atomic>
#include <memory>
#include <thread>
#include <vector>

#include "GraphicsContext.hpp"
#include "IDisplay.hpp"
#include "CameraBase.hpp"

namespace graphics {

class CameraManager {
public:
    CameraManager();
    ~CameraManager();

    // Add a camera to the manager
    void AddCamera(std::shared_ptr<CameraBase> camera);

    // Set the active camera by index
    void SetActiveCamera(size_t index);

    // Get the active camera
    std::shared_ptr<CameraBase> GetActiveCamera() const;

    // Start rendering loop
    void Start();

    // Stop rendering loop
    void Stop();

    // Update all cameras
    void UpdateCameras();

    // Render with the active camera
    void RenderActiveCamera();

    // Camera manipulation functions
    void SetCameraOffsetX(float offset);
    void SetCameraOffsetY(float offset);
    void SetCameraTargetX(float target);
    void SetCameraTargetY(float target);
    void SetCameraRotation(float rotation);
    void SetCameraZoom(float zoom);

    float GetCameraOffsetX() const;
    float GetCameraOffsetY() const;
    float GetCameraTargetX() const;
    float GetCameraTargetY() const;
    float GetCameraRotation() const;
    float GetCameraZoom() const;

private:
    std::vector<std::shared_ptr<CameraBase>> mCameras;
    std::shared_ptr<CameraBase> mActiveCamera;
    std::atomic<bool> mRunning;
    std::unique_ptr<std::thread> mThread;

    // Internal method for render loop
    void RenderLoop();
};

}  // namespace graphics
