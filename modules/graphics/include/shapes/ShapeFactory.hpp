#ifndef SHAPEFACTORY_HPP
#define SHAPEFACTORY_HPP

#include <memory>
#include "Shape.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "RegularPolygon.hpp"
#include "Arc.hpp"

namespace graphics {

enum class shapeType{
    circle,
    arc,
    rectangle,
    regularPolygon,
    };

class ShapeFactory {
public:

    static std::shared_ptr<Shape> CreateShape(const shapeType aType);

    static std::shared_ptr<Circle> CreateCircle(const std::vector<double>& center, double radius);
    static std::shared_ptr<Circle> CreateCircle(); 
    
    static std::shared_ptr<Arc> CreateArc(const std::vector<double>& center,
                                          double radius, double startAngle,
                                          double endAngle, double thickness);
    static std::shared_ptr<Arc> CreateArc();
    //// Factory method to create a Rectangle
    //static std::shared_ptr<Shape> createRectangle(const std::vector<double>& upperRight, const std::vector<double>& lowerLeft);

    //// Factory method to create a RegularPolygon
    //static std::shared_ptr<Shape> createRegularPolygon(const std::vector<double>& center, int sides, double sideLength, double radius);


};
}
#endif // SHAPEFACTORY_HPP
