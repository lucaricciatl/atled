#ifndef SHAPEFACTORY_HPP
#define SHAPEFACTORY_HPP

#include <memory>
#include "Shape.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "RegularPolygon.hpp"

class ShapeFactory {
public:
    // Factory method to create a Circle
    static std::unique_ptr<Shape> createCircle(const std::vector<double>& center, double radius);

    // Factory method to create a Rectangle
    static std::unique_ptr<Shape> createRectangle(const std::vector<double>& upperRight, const std::vector<double>& lowerLeft);

    // Factory method to create a RegularPolygon
    static std::unique_ptr<Shape> createRegularPolygon(const std::vector<double>& center, int sides, double sideLength, double radius);
};

#endif // SHAPEFACTORY_HPP
