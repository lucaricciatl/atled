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



class Model3DFactory {
public:

    // Specific factory methods for each 3D model type
    static std::shared_ptr<Cube> CreateCube(float sideLength);
    static std::shared_ptr<Cube> CreateCube();

    static std::shared_ptr<Sphere> CreateSphere(float radius);
    static std::shared_ptr<Sphere> CreateSphere();

    static std::shared_ptr<Line3D> CreateLine3D(Vector3 startPos, Vector3 endPos);
    static std::shared_ptr<Line3D> CreateLine3D();

    static std::shared_ptr<Cylinder> CreateCylinder();

    static std::shared_ptr<Plane> CreatePlane();


};

}  // namespace graphics

#endif  // MODEL3DFACTORY_HPP