#ifndef RAYLIB_CAMERA3D_HPP
#define RAYLIB_CAMERA3D_HPP

#include "ICamera.hpp"
#include "raylib.hpp"
#include "Vector3.hpp"

namespace graphics {

class RaylibCamera3D : public ICamera {
public:
    RaylibCamera3D(math::Vector3 position = {0.0f, 0.0f, 10.0f}, math::Vector3 target = {0.0f, 0.0f, 0.0f},
                   math::Vector3 up = {0.0f, 1.0f, 0.0f}, float fovy = 45.0f, int projection = raylib::CAMERA_PERSPECTIVE);

    void BeginCamera() override;
    void UpdateCamera() override;  
    void EndCamera() override;

    void SetPosition(math::Vector3 position) override;
    math::Vector3 GetPosition() const override;

    void SetTarget(math::Vector3 target) override;
    math::Vector3 GetTarget() const override;

    void SetUp(math::Vector3 up) override;
    math::Vector3 GetUp() const override;

    void SetZoom(float zoom) override;
    float GetZoom() const override;

    void SetRotation(float rotation) override;
    float GetRotation() const override;

    void SetFovy(float aFovy) override;
    void SetCameraProjection(raylib::CameraProjection aProjection) override;


private:
    raylib::Camera3D mCamera;
};

}  // namespace graphics

#endif  // RAYLIB_CAMERA3D_HPP
