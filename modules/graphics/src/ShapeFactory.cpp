#include "ShapeFactory.hpp"

// Factory method to create a Circle
std::unique_ptr<Shape> ShapeFactory::createCircle(const std::vector<double>& center, double radius) {
    return std::make_unique<Circle>(center, radius);
}

// Factory method to create a Rectangle
std::unique_ptr<Shape> ShapeFactory::createRectangle(const std::vector<double>& upperRight, const std::vector<double>& lowerLeft) {
    return std::make_unique<Rectangle>(upperRight, lowerLeft);
}

// Factory method to create a RegularPolygon
std::unique_ptr<Shape> ShapeFactory::createRegularPolygon(const std::vector<double>& center, int sides, double sideLength, double radius) {
    return std::make_unique<RegularPolygon>(center, sides, sideLength, radius);
}
