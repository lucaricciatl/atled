#ifndef CAMERA2D_HPP
#define CAMERA2D_HPP

#include "CameraBase.hpp"

// Concrete class for Camera2D
class rCamera2D : public CameraBase {
public:
    rCamera2D();  // Constructor

    // Setters for Camera2D properties
    void setOffset(const Vector2& offset) override;
    void setTarget(const Vector2& target) override;  // Proper override for setTarget
    void setRotation(float rotation) override;
    void setZoom(float zoom) override;

    // Getters for Camera2D properties
    Vector2 getOffset() const override;
    Vector2 getTarget() const override;
    float getRotation() const override;
    float getZoom() const override;

    void BeginCamera() override;

private:
    ::Camera2D mCamera2D;  // Raylib's Camera2D
};

#endif  // CAMERA2D_HPP


