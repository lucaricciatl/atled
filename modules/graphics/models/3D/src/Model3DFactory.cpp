#include "Model3DFactory.hpp"

namespace graphics {

std::shared_ptr<Model> Model3DFactory::CreateModel3D(const Model3DType aType) {
    switch (aType) {
        case Model3DType::cube:
            return CreateCube();
        case Model3DType::sphere:
            return CreateSphere();
        case Model3DType::pyramid:
            return CreatePyramid();
        default:
            return nullptr;
    }
}

std::shared_ptr<Sphere> Model3DFactory::CreateSphere() {
    return std::make_shared<Sphere>();  // Default constructor for Sphere
}

std::shared_ptr<Cube> Model3DFactory::CreateCube() {
    return std::make_shared<Cube>();  // Default constructor for Cube
}

std::shared_ptr<Pyramid> Model3DFactory::CreatePyramid() {
    return std::make_shared<Pyramid>();  // Default constructor for Pyramid
}

}  // namespace graphics