
#include "CameraManager.hpp"
#include "gfx.hpp"
#include <vector>

namespace graphics {

// Constructor implementation
CameraManager::CameraManager() {

}


// Begin 3D mode
void CameraManager::Begin3D() { gfx::BeginMode3D(camera); }

// End 3D mode
void CameraManager::End3D() { gfx::EndMode3D(); }

}  // namespace graphics