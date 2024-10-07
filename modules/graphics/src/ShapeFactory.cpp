#include "ShapeFactory.hpp"


namespace graphics {
// Factory method to create a shape based on the shapeType
std::shared_ptr<Shape> ShapeFactory::CreateShape(const shapeType aType) {
    switch (aType) {
        case shapeType::arc:
            return createArc();  // Example parameters
        case shapeType::circle:
            return createCircle();
        default:
            return nullptr;
    }
}

//Factory method to create a Circle
std::shared_ptr<Circle> createCircle(const std::vector<double>& center,
                                     double radius){

    return std::make_shared<Circle>();
}

std::shared_ptr<Circle> ShapeFactory::createCircle() {
  return std::make_shared<Circle>();  // Example color
}
//
//// Factory method to create a Rectangle
//std::shared_ptr<Shape> ShapeFactory::createRectangle(const std::vector<double>& upperRight, const std::vector<double>& lowerLeft) {
//    return std::make_shared<Rectangle>(upperRight, lowerLeft);
//}
//
//// Factory method to create a RegularPolygon
//std::shared_ptr<Shape> ShapeFactory::createRegularPolygon(const std::vector<double>& center, int sides, double sideLength, double radius) {
//    return std::make_shared<RegularPolygon>(center, sides, sideLength, radius);
//}

// Factory method to create an Arc
std::shared_ptr<Arc> ShapeFactory::createArc(const std::vector<double>& center, double radius, double startAngle, double endAngle, double thickness) {
    return std::make_shared<Arc>(Coordinates2D(center[0], center[1]), radius, startAngle, endAngle, thickness, Color{255, 0, 0, 255});  // Example color
}

std::shared_ptr<Arc> ShapeFactory::createArc() {
  return std::make_shared<Arc>();  // Example color
}

}