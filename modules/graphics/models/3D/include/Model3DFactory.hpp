#ifndef MODEL3DFACTORY_HPP
#define MODEL3DFACTORY_HPP

#include "Cube.hpp"
#include "Sphere.hpp"
#include "Line3D.hpp"
#include "Cylinder.hpp"
#include "Plane.hpp"
#include "Vector3.hpp"
namespace graphics {



class Model3DFactory {
public:

    // Specific factory methods for each 3D model type
    static std::shared_ptr<Cube> CreateCube(float sideLength);
    static std::shared_ptr<Cube> CreateCube();

    static std::shared_ptr<Sphere> CreateSphere(float radius, const math::Vector3& centerPos, int rings, int slices, raylib::Color mColor);
    static std::shared_ptr<Sphere> CreateSphere();

    static std::shared_ptr<Line3D> CreateLine3D(math::Vector3 startPos, math::Vector3 endPos);
    static std::shared_ptr<Line3D> CreateLine3D();

    static std::shared_ptr<Cylinder> CreateCylinder();

    static std::shared_ptr<Plane> CreatePlane();
    static std::shared_ptr<Plane> CreatePlane(const math::Vector3& centerPos, const raylib::Vector2& size, const raylib::Color& color);


};

}  // namespace graphics

#endif  // MODEL3DFACTORY_HPP