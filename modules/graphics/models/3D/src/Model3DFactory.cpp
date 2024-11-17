#include "Model3DFactory.hpp"

namespace graphics {

    std::shared_ptr<Model3D> Model3DFactory::CreateModel3D(const Model3DType aType) {
        switch (aType) {
        case Model3DType::cube:
            return std::static_pointer_cast<Model3D>(std::make_shared<Cube>());
        case Model3DType::sphere:
            return std::static_pointer_cast<Model3D>(std::make_shared<Sphere>());
        case Model3DType::pyramid:
            return std::static_pointer_cast<Model3D>(std::make_shared<Pyramid>());
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

    std::shared_ptr<Pyramid> Model3DFactory::CreatePyramid() {
        return std::make_shared<Pyramid>();
    }

}  // namespace graphics