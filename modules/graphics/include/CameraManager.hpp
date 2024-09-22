#pragma once

#include "raylib.h"
#include <vector>

namespace graphics {
  using namespace raylib ;

  class CameraManager {
   public:
    // Constructor to initialize the camera
    CameraManager(const std::vector<float>& position = {0,10,10},
                  const std::vector<float>& target = {0,0,0},
                  const std::vector<float>& up = {0,0,1}, float fovy = 45.0f);

    // Update camera position and target based on user input
    void Update(float moveSpeed = 0.2f, float turnSpeed = 0.05f);

    // Begin 3D modek
    void Begin3D();

    // End 3D mode
    void End3D();

    // Draw a grid to help visualize the space
    void DrawGrid(int slices = 10, float spacing = 1.0f);

   private:
    raylib::Camera camera;  // The Raylib camera object
  };

}