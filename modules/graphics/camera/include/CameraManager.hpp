#pragma once

#include <atomic>
#include <memory>
#include <thread>
#include <vector>

#include "GraphicsContext.hpp"
#include "IDisplay.hpp"
#include "ICamera.hpp"
#include "Vector3.hpp"

namespace graphics {

    enum class WorldType
    {
        World2D,
        World3D,
    };

    enum class CameraType
    {
        Invalid,
        Raylib,
    };

class CameraManager {
public:
    CameraManager();
    ~CameraManager();

    // Add a camera to the manager
    void AddCamera(std::shared_ptr<ICamera> camera);

    // Set the active camera by index
    void SetActiveCamera(size_t index);

    // Get the active camera
    std::shared_ptr<ICamera> GetActiveCamera() const;

    // Start rendering loop
    void Start();

    // Stop rendering loop
    void Stop();

    // Update all cameras
    void UpdateCameras();

    // Render with the active camera
    void RenderActiveCamera();

    // Camera manipulation functions 2D
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

    // 3D
    void SetFovy(float aFovy);
    void SetCameraProjection(raylib::CameraProjection aProjection);
    void SetCameraPosition(const math::Vector3& aPosition);
    void SetCameraTarget(const math::Vector3& aTarget);
    math::Vector3 GetCameraPosition() const;
    math::Vector3 GetCameraTarget() const;
    void BeginActiveCamera();

    void EndActiveCamera();

private:
    std::vector<std::shared_ptr<ICamera>> mCameras;
    std::shared_ptr<ICamera> mActiveCamera;
    std::atomic<bool> mRunning;
    std::unique_ptr<std::thread> mThread;

    // Internal method for render loop

};

}  // namespace graphics
