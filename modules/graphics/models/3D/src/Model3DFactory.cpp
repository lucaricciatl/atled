#include "Model3DFactory.hpp"
#include "Cube.hpp"
#include "Sphere.hpp"
#include "Line3D.hpp"
#include "Cylinder.hpp"
#include "Plane.hpp"

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

std::shared_ptr<Sphere> Model3DFactory::CreateSphere(float radius, const math::Vector3& centerPos, int rings, int slices, graphics::Color mColor) {
    auto sphere = std::make_shared<Sphere>(radius,centerPos, rings, slices, mColor);
    return sphere;
}

std::shared_ptr<Sphere> Model3DFactory::CreateSphere() {
    return std::make_shared<Sphere>();
}

std::shared_ptr<Line3D> Model3DFactory::CreateLine3D(math::Vector3 startPos, math::Vector3 endPos) {
    auto line = std::make_shared<Line3D>();
    line->SetStartPos(startPos);
    line->SetEndPos(endPos);
    return line;
}

std::shared_ptr<Line3D> Model3DFactory::CreateLine3D() {
    return std::make_shared<Line3D>();
}

std::shared_ptr<Cylinder> Model3DFactory::CreateCylinder() {
    return std::make_shared<Cylinder>();
}

std::shared_ptr<Plane> Model3DFactory::CreatePlane() {
    return std::make_shared<Plane>();;
}

std::shared_ptr<Plane> Model3DFactory::CreatePlane(const math::Vector3& centerPos, const raylib::Vector2& size, const Color& color) {
    return std::make_shared<Plane>(centerPos, size, color);
}

}  // namespace graphics
