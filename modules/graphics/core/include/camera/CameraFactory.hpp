#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <iostream>
#include <memory>  // For std::unique_ptr
#include "raylib.h"  // Assuming you're using Raylib for Vector2, Vector3
#include "CameraBase.hpp"

// Forward declarations for Camera2D and Camera3D
class rCamera2D;
class rCamera3D;

// Enumeration for camera type
enum class CameraType {
    CAMERA_2D,
    CAMERA_3D
};

// Factory class for creating Camera objects
class CameraFactory {
public:
    static std::shared_ptr<CameraBase> createCamera(CameraType type);
};

#endif // CAMERA_HPP