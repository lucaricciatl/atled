#ifndef ICAMERA_HPP
#define ICAMERA_HPP

#include "raylib.h"

namespace graphics {

class ICamera {
public:
    virtual ~ICamera() = default;

    // Camera lifecycle methods
    virtual void BeginCamera() = 0;
    virtual void UpdateCamera() = 0;  // Use Raylib's UpdateCamera

    virtual void EndCamera() = 0;

    // Setters
    virtual void SetPosition(Vector3 position) = 0;
    virtual void SetTarget(Vector3 target) = 0;
    virtual void SetUp(Vector3 up) = 0;  // For 3D cameras
    virtual void SetZoom(float zoom) = 0;
    virtual void SetRotation(float rotation) = 0;

    // Getters
    virtual Vector3 GetPosition() const = 0;
    virtual Vector3 GetTarget() const = 0;
    virtual Vector3 GetUp() const = 0;  // For 3D cameras
    virtual float GetZoom() const = 0;
    virtual float GetRotation() const = 0;
};

}  // namespace graphics

#endif  // ICAMERA_HPP
