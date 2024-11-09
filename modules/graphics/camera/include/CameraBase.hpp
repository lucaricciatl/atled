#ifndef CAMERABASE_HPP
#define CAMERABASE_HPP

#include <iostream>
#include <memory>  // For std::unique_ptr



// Abstract base class for cameras
class CameraBase {
 public:
  virtual ~CameraBase() {}  

  // Setter
  virtual void SetOffsetX(const float& offset) = 0;
  virtual void SetTargetX(const float& target) = 0;
  virtual void SetOffsetY(const float& offset) = 0;
  virtual void SetTargetY(const float& target) = 0;
  virtual void SetRotation(const float& rotation) = 0;
  virtual void SetZoom(const float& zoom) = 0;

  // Getters for Camera2D properties
  virtual float GetOffsetX() const = 0;
  virtual float GetOffsetY() const = 0;
  virtual float GetTargetX() const = 0;
  virtual float GetTargetY() const = 0;
  virtual float GetRotation() const = 0;
  virtual float GetZoom() const = 0;

  // Methods to change offsets
  virtual void IncreaseOffsetX(const float& deltaX) = 0;
  virtual void IncreaseOffsetY(const float& deltaY) = 0;
  virtual void IncreaseOffset(const float& deltaX, const float& deltaY) = 0;
  // Function to increase zoom
  virtual void IncreaseZoom(const float& deltaZoom) = 0;

  virtual void BeginCamera() = 0;
};

#endif  // CAMERABASE_HPP