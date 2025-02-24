#include "Model2DFactory.hpp"

#include <memory>

#include "Line.hpp"  // Include the Line header file
#include "PolyLine.hpp"
#include "Model2D.hpp"

namespace graphics {


// Factory method to create a Circle
std::shared_ptr<Circle> CreateCircle(const std::vector<double>& center,
                                     double radius) {
  return std::make_shared<Circle>();
}

std::shared_ptr<Circle> Model2DFactory::CreateCircle() {
  return std::make_shared<Circle>();
}

// Factory method to create an Arc
std::shared_ptr<Arc> Model2DFactory::CreateArc(
    const std::vector<double>& center, double radius, double startAngle,
    double endAngle, double thickness) {
  return std::make_shared<Arc>(Coordinates2D(center[0], center[1]), radius,
                               startAngle, endAngle, thickness,
                               Color{255, 0, 0, 255});
}

std::shared_ptr<Arc> Model2DFactory::CreateArc() {
  return std::make_shared<Arc>();
}

// Factory method to create a Rectangle
std::shared_ptr<Rectangle> Model2DFactory::CreateRectangle(
    const std::vector<double>& upperRight,
    const std::vector<double>& lowerLeft) {
  return std::make_shared<Rectangle>();
}

std::shared_ptr<Rectangle> Model2DFactory::CreateRectangle() {
  return std::make_shared<Rectangle>();
}

// Factory method to create a Line with parameters
std::shared_ptr<Line> Model2DFactory::CreateLine(Coordinates2D aStart,
                                                 Coordinates2D aEnd,
                                                 double thickness,
                                                 const Color& aColor) {
  return std::make_shared<Line>(aStart, aEnd, thickness, aColor);
}

// Factory method to create a Line with default constructor
std::shared_ptr<Line> Model2DFactory::CreateLine() {
  return std::make_shared<Line>();
}

// Factory method to create a Polyline with parameters
std::shared_ptr<Polyline> Model2DFactory::CreatePolyline(
    const std::vector<Coordinates2D>& points, double thickness,
    const Color& color) {
  return std::make_shared<Polyline>(points, thickness, color);
}

// Factory method to create a default Polyline
std::shared_ptr<Polyline> Model2DFactory::CreatePolyline() {
  return std::make_shared<Polyline>();
}

std::shared_ptr<Triangle> Model2DFactory::CreateTriangle(const Coordinates2D& point1, const Coordinates2D& point2, const Coordinates2D& point3, const Color& color) {
    return std::make_shared<Triangle>(point1, point2, point3, color);
}

// Factory method to create a default Triangle
std::shared_ptr<Triangle> Model2DFactory::CreateTriangle() {
    return std::make_shared<Triangle>();
}

// Factory method to create a Polygon with parameters
std::shared_ptr<Polygon> Model2DFactory::CreatePolygon(const std::vector<Coordinates2D>& points, const Color& color) {
    return std::make_shared<Polygon>(points, color);
}

// Factory method to create a default Polygon
std::shared_ptr<Polygon> Model2DFactory::CreatePolygon() {
    return std::make_shared<Polygon>();
}

}  // namespace graphics