#include "CameraFactory.hpp"
#include "RaylibCamera2D.hpp"
#include "RaylibCamera3D.hpp"


namespace graphics {
    // Implement the factory method to create cameras based on the type
    std::shared_ptr<ICamera> CameraFactory::createCamera2D(CameraType2D type) {
        switch (type) {
        case CameraType2D::Raylib:
            return std::make_shared<RaylibCamera2D>();
        default:
            return nullptr;
        }
    }

    // Implement the factory method to create cameras based on the type
    std::shared_ptr<ICamera> CameraFactory::createCamera3D(CameraType3D type) {
        switch (type) {
        case CameraType3D::Raylib:
            return std::make_shared<RaylibCamera3D>();
        default:
            return nullptr;
        }
    }
}