#include "Model3DFactory.hpp"

namespace graphics {

    std::shared_ptr<Model3D> Model3DFactory::CreateModel3D(const Model3DType aType) {
        switch (aType) {
        case Model3DType::cube:
            return std::static_pointer_cast<Model3D>(std::make_shared<Cube>());
        case Model3DType::sphere:
            return std::static_pointer_cast<Model3D>(std::make_shared<Sphere>());
        case Model3DType::Line3D:
            return std::static_pointer_cast<Model3D>(std::make_shared<Line3D>());
        default:
            return nullptr;
        }
    }

    std::shared_ptr<Cube> Model3DFactory::CreateCube() {
        return std::make_shared<Cube>();
    }

    std::shared_ptr<Sphere> Model3DFactory::CreateSphere() {
        return std::make_shared<Sphere>();
    }

    std::shared_ptr<Line3D> Model3DFactory::CreateLine3D() {
        return std::make_shared<Line3D>();
    }

}  // namespace graphics