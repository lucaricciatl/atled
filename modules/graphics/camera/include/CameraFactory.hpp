#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <iostream>
#include <memory>  // For std::unique_ptr
#include "raylib.h"  // Assuming you're using Raylib for Vector2, Vector3
#include "CameraBase.hpp"

// Enumeration for camera type
enum class CameraType3D {
    Raylib
};

// Enumeration for camera type
enum class CameraType2D {
    Raylib
};

// Factory class for creating Camera objects
class CameraFactory {
public:
    static std::shared_ptr<CameraBase> createCamera2D(CameraType2D type);
    static std::shared_ptr<CameraBase> createCamera3D(CameraType3D type);

};

#endif // CAMERA_HPP