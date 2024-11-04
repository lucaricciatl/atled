#ifndef CAMERA3D_HPP
#define CAMERA3D_HPP

#include "CameraBase.hpp"

// Concrete class for Camera3D
class RaylibCamera3D{
public:

    RaylibCamera3D(Vector3 position, Vector3 target, Vector3 up, float fovy, int projection);
    RaylibCamera3D();

    // Setters for Camera3D properties
    void setPosition(const Vector3& position);
    void setTarget(const Vector3& target);
    void setUp(const Vector3& up);
    void setFovy(float fovy);

    // Getters for Camera3D properties
    Vector3 getPosition() const;
    Vector3 getTarget() const;
    Vector3 getUp() const;
    float getFovy() const;

    Camera3D mCamera3D;
};

#endif // CAMERA3D_HPP
