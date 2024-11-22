#ifndef MODEL3DFACTORY_HPP
#define MODEL3DFACTORY_HPP

#include "Cube.hpp"
#include "Sphere.hpp"
#include "Line3D.hpp"
#include "Capsule.hpp"
#include "Cylinder.hpp"
#include "Plane.hpp"

namespace graphics {
using namespace raylib;
// Enum for types of 3D models
enum class Model3DType {
    cube,
    sphere,
    line3D,capsule,cylinder,plane
    // Add other 3D types as needed
};


class Model3DFactory {
public:
    // Factory method to create a 3D model based on type
    static std::shared_ptr<Model3D> CreateModel3D(const Model3DType aType);

    // Specific factory methods for each 3D model type
    static std::shared_ptr<Cube> CreateCube(float sideLength);
    static std::shared_ptr<Cube> CreateCube();

    static std::shared_ptr<Sphere> CreateSphere(float radius);
    static std::shared_ptr<Sphere> CreateSphere();

    static std::shared_ptr<Line3D> CreateLine3D(Vector3 startPos, Vector3 endPos);
    static std::shared_ptr<Line3D> CreateLine3D();

    static std::shared_ptr<Cylinder> CreateCylinder(float startRadius, float endRadius, Vector3 startPos, Vector3 endPos);
    static std::shared_ptr<Cylinder> CreateCylinder();

    static std::shared_ptr<Plane> CreatePlane(Vector3 centerPos, Vector2 size);
    static std::shared_ptr<Plane> CreatePlane();

    static std::shared_ptr<Capsule> CreateCapsule(Vector3 startPos, Vector3 endPos, float radius);
    static std::shared_ptr<Capsule> CreateCapsule();
};

}  // namespace graphics

#endif  // MODEL3DFACTORY_HPP