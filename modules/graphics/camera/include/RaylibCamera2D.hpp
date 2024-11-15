#ifndef RAYLIB_CAMERA2D_HPP
#define RAYLIB_CAMERA2D_HPP

#include "ICamera.hpp"
#include "raylib.h"

namespace graphics {

class RaylibCamera2D : public ICamera {
public:
    RaylibCamera2D(Vector2 offset = {0, 0}, Vector2 target = {0, 0}, float rotation = 0.0f, float zoom = 1.0f);

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

private:
    Camera2D mCamera;
};

}  // namespace graphics

#endif  // RAYLIB_CAMERA2D_HPP
