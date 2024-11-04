#include "CameraFactory.hpp"
#include "RaylibCamera2D.hpp"
#include "RaylibCamera3D.hpp"

// Implement the factory method to create cameras based on the type
std::shared_ptr<CameraBase> CameraFactory::createCamera(CameraType type) {
    switch (type) {
        case CameraType::CAMERA_2D:
            return std::make_shared<RaylibCamera2D>();
        default:
            return nullptr;
    }
}
