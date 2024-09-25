
#include "CameraManager.hpp"
#include "gfx.hpp"
#include <vector>

namespace graphics {

// Constructor implementation
CameraManager::CameraManager(const std::vector<float>& position,
                             const std::vector<float>& target,
                             const std::vector<float>& up, float fovy) {
  // Ensure that each vector has exactly 3 elements before accessing
  if (position.size() >= 3 && target.size() >= 3 && up.size() >= 3) {
    camera.position = {position[0], position[1],
                       position[2]};  // Camera position
    camera.target = {target[0], target[1],
                     target[2]};  // Camera looking at point
    camera.up = {up[0], up[1],
                 up[2]};  // Camera up vector (rotation towards target)
  } else {
    // Handle error or set default values
    camera.position = {0.0f, 10.0f, 10.0f};
    camera.target = {0.0f, 0.0f, 0.0f};
    camera.up = {0.0f, 1.0f, 0.0f};
  }
  camera.fovy = fovy;  // Camera field-of-view Y
  Begin3D();
}

// Update camera position and target based on user input
void CameraManager::Update(float moveSpeed, float turnSpeed) {
  // Move the camera with WASD keys
  if (IsKeyDown(KEY_W)) camera.position.z -= moveSpeed;
  if (IsKeyDown(KEY_S)) camera.position.z += moveSpeed;
  if (IsKeyDown(KEY_A)) camera.position.x -= moveSpeed;
  if (IsKeyDown(KEY_D)) camera.position.x += moveSpeed;
  if (IsKeyDown(KEY_E)) camera.position.y += moveSpeed;
  if (IsKeyDown(KEY_Q)) camera.position.y -= moveSpeed;

  // Rotate the camera target with arrow keys
  if (IsKeyDown(KEY_LEFT)) camera.target.x -= turnSpeed;
  if (IsKeyDown(KEY_RIGHT)) camera.target.x += turnSpeed;
  if (IsKeyDown(KEY_UP)) camera.target.z -= turnSpeed;
  if (IsKeyDown(KEY_DOWN)) camera.target.z += turnSpeed;

  // Update the camera
  UpdateCamera(&camera, 0);
}

// Begin 3D mode
void CameraManager::Begin3D() { gfx::BeginMode3D(camera); }

// End 3D mode
void CameraManager::End3D() { gfx::EndMode3D(); }

}  // namespace graphics