#pragma once

#include "gfx.hpp"
#include <vector>
#include "camera.hpp"


namespace graphics {
  using namespace camera;

  class CameraManager {
   public:
    // Constructor to initialize the camera
    CameraManager();

    // Begin 3D modek
    void Begin3D();

    // End 3D mode
    void End3D();


   private:
    Camera camera;  // The gfx camera object
  };

}