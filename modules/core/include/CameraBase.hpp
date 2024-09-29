#ifndef CAMERABASE_HPP
#define CAMERABASE_HPP

#include <iostream>
#include <memory>  // For std::unique_ptr

#include "raylib.h"  // Assuming you're using Raylib for Vector2, Vector3

// Abstract base class for cameras
class CameraBase {
 public:
  virtual ~CameraBase() {}  // Virtual destructor for polymorphism

  // Declare pure virtual functions that must be overridden in derived classes
  virtual void setOffset(const Vector2& offset) = 0;
  virtual void setTarget(const Vector2& target) = 0;
  virtual void setRotation(float rotation) = 0;
  virtual void setZoom(float zoom) = 0;

  // Getters for Camera2D properties
  virtual Vector2 getOffset() const = 0;
  virtual Vector2 getTarget() const = 0;
  virtual float getRotation() const = 0;
  virtual float getZoom() const = 0;

  virtual void BeginCamera() = 0;
};

#endif  // CAMERABASE_HPP