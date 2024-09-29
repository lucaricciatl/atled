#ifndef CAMERA2D_HPP
#define CAMERA2D_HPP

#include "CameraBase.hpp"


// Concrete class for Camera2D
class rCamera2D : public CameraBase {
public:

    rCamera2D(Vector2 offset, Vector2 target, float rotation, float zoom);
    rCamera2D();

    void printCameraInfo() const override;

    // Setters for Camera2D properties
    void setOffset(const Vector2& offset);
    void setTarget(const Vector2& target);
    void setRotation(float rotation);
    void setZoom(float zoom);

    // Getters for Camera2D properties
    Vector2 getOffset() const;
    Vector2 getTarget() const;
    float getRotation() const;
    float getZoom() const;

    Camera2D mCamera2D;
};

#endif // CAMERA2D_HPP
