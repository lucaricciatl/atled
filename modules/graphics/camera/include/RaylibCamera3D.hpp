#ifndef RAYLIB_CAMERA3D_HPP
#define RAYLIB_CAMERA3D_HPP

#include "ICamera.hpp"
#include "raylib.h"

namespace graphics {

class RaylibCamera3D : public ICamera {
public:
    RaylibCamera3D(Vector3 position = {0.0f, 0.0f, 10.0f}, Vector3 target = {0.0f, 0.0f, 0.0f},
                   Vector3 up = {0.0f, 1.0f, 0.0f}, float fovy = 45.0f, int projection = CAMERA_PERSPECTIVE);

    void BeginCamera() override;
    void UpdateCamera() override;  
    void EndCamera() override;

    void SetPosition(Vector3 position) override;
    Vector3 GetPosition() const override;

    void SetTarget(Vector3 target) override;
    Vector3 GetTarget() const override;

    void SetUp(Vector3 up) override;
    Vector3 GetUp() const override;

    void SetZoom(float zoom) override;
    float GetZoom() const override;

    void SetRotation(float rotation) override;
    float GetRotation() const override;

    void SetFovy(float aFovy) override;
    void SetCameraProjection(CameraProjection aProjection) override;


private:
    Camera3D mCamera;
};

}  // namespace graphics

#endif  // RAYLIB_CAMERA3D_HPP
