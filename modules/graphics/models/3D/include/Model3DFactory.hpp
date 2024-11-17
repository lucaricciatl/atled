#ifndef MODEL3DFACTORY_HPP
#define MODEL3DFACTORY_HPP

#include "Cube.hpp"
#include "Sphere.hpp"
#include "Pyramid.hpp"

namespace graphics {

// Enum for types of 3D models
enum class Model3DType {
    cube,
    sphere,
    pyramid,
    // Add other 3D types as needed
};

class Model3DFactory {
 public:
    // Factory method to create a 3D model based on the specified type
    static std::shared_ptr<Model3D> CreateModel3D(const Model3DType aType);

    // Specific factory methods for each 3D model type
    static  std::shared_ptr<Cube> CreateCube(float sideLength);
    static std::shared_ptr<Cube> CreateCube();

    static std::shared_ptr<Sphere> CreateSphere(float radius);
    static std::shared_ptr<Sphere> CreateSphere();

    static std::shared_ptr<Pyramid> CreatePyramid(float baseWidth, float height);
    static std::shared_ptr<Pyramid> CreatePyramid();
};

}  // namespace graphics

#endif  // MODEL3DFACTORY_HPP