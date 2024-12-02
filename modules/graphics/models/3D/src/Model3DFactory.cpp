#include "Model3DFactory.hpp"
#include "Cube.hpp"
#include "Sphere.hpp"
#include "Line3D.hpp"
#include "Cylinder.hpp"
#include "Plane.hpp"
#include "Capsule.hpp"

namespace graphics {

std::shared_ptr<Cube> Model3DFactory::CreateCube(float sideLength) {
    auto cube = std::make_shared<Cube>();
    cube->SetWidth(sideLength);
    cube->SetHeight(sideLength);
    cube->SetLength(sideLength);
    return cube;
}


std::shared_ptr<Cube> Model3DFactory::CreateCube() {
    return std::make_shared<Cube>();
}

std::shared_ptr<Sphere> Model3DFactory::CreateSphere(float radius) {
    auto sphere = std::make_shared<Sphere>();
    sphere->SetRadius(radius);
    return sphere;
}

std::shared_ptr<Sphere> Model3DFactory::CreateSphere() {
    return std::make_shared<Sphere>();
}

std::shared_ptr<Line3D> Model3DFactory::CreateLine3D(Vector3 startPos, Vector3 endPos) {
    auto line = std::make_shared<Line3D>();
    line->SetStartPos(startPos);
    line->SetEndPos(endPos);
    return line;
}

std::shared_ptr<Line3D> Model3DFactory::CreateLine3D() {
    return std::make_shared<Line3D>();
}

std::shared_ptr<Cylinder> Model3DFactory::CreateCylinder(float startRadius, float endRadius, Vector3 startPos, Vector3 endPos) {
    auto cylinder = std::make_shared<Cylinder>();
    cylinder->SetStartPos(startPos);
    cylinder->SetEndPos(endPos);
    cylinder->SetStartRadius(startRadius);
    cylinder->SetEndRadius(endRadius);
    return cylinder;
}

std::shared_ptr<Cylinder> Model3DFactory::CreateCylinder() {
    return std::make_shared<Cylinder>();
}

std::shared_ptr<Plane> Model3DFactory::CreatePlane(Vector3 centerPos, Vector2 size) {
    auto plane = std::make_shared<Plane>();
    plane->SetCenterPos(centerPos);
    plane->SetSize(size);
    return plane;
}

std::shared_ptr<Plane> Model3DFactory::CreatePlane() {
    return std::make_shared<Plane>();
}

std::shared_ptr<Capsule> Model3DFactory::CreateCapsule(Vector3 startPos, Vector3 endPos, float radius) {
    auto capsule = std::make_shared<Capsule>();
    capsule->SetStartPos(startPos);
    capsule->SetEndPos(endPos);
    capsule->SetRadius(radius);
    return capsule;
}

std::shared_ptr<Capsule> Model3DFactory::CreateCapsule() {
    return std::make_shared<Capsule>();
}




}  // namespace graphics
