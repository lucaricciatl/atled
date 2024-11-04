#ifndef CAMERA2D_HPP
#define CAMERA2D_HPP

#include "CameraBase.hpp"
#include "raylib.h"  // Assuming you are using Raylib's Camera2D

// Concrete class for Camera2D that inherits from CameraBase
class RaylibCamera2D : public CameraBase {
public:
    // Constructors
    RaylibCamera2D();  // Default constructor
    RaylibCamera2D(Vector2 offset, Vector2 target, float rotation, float zoom);  // Parameterized constructor

    // Setters for Camera2D properties
    void SetOffsetX(const float& offset) override;
    void SetOffsetY(const float& offset) override;
    void SetTargetX(const float& target) override;
    void SetTargetY(const float& target) override;
    void SetRotation(const float& rotation) override;
    void SetZoom(const float& zoom) override;

    // Getters for Camera2D properties
    float GetOffsetX() const override;
    float GetOffsetY() const override;
    float GetTargetX() const override;
    float GetTargetY() const override;
    float GetRotation() const override;
    float GetZoom() const override;

    // Other methods for Camera2D
    void BeginCamera() override;

    // Methods to change offsets and zoom
    void IncreaseOffsetX(const float& deltaX) override;
    void IncreaseOffsetY(const float& deltaY) override;
    void IncreaseOffset(const float& deltaX, const float& deltaY) override;
    void IncreaseZoom(const float& deltaZoom) override;

private:
    ::Camera2D mCamera2D;  // Using Raylib's Camera2D struct
};

#endif  // CAMERA2D_HPP
