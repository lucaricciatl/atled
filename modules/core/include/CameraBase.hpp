#ifndef CAMERABASE_HPP
#define CAMERABASE_HPP

#include <iostream>
#include <memory>  // For std::unique_ptr
#include "raylib.h"  // Assuming you're using Raylib for Vector2, Vector3

// Abstract base class for cameras
class CameraBase {
public:
    virtual void printCameraInfo() const = 0;  // Abstract method to print camera information
    virtual ~CameraBase() {}                   // Virtual destructor for polymorphism
};

#endif