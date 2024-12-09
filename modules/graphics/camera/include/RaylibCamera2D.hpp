#ifndef RAYLIB_CAMERA2D_HPP
#define RAYLIB_CAMERA2D_HPP

#include "ICamera.hpp"
#include "raylib.hpp"
#include "Vector3.hpp"

namespace graphics {

class RaylibCamera2D : public ICamera {
public:
    RaylibCamera2D(raylib::Vector2 offset = {0, 0}, raylib::Vector2 target = {0, 0}, float rotation = 0.0f, float zoom = 1.0f);

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
    raylib::Camera2D mCamera;
};

}  // namespace graphics

#endif  // RAYLIB_CAMERA2D_HPP
