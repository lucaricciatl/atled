#ifndef MODELFACTORY_HPP
#define MODELFACTORY_HPP

#include <memory>

#include "Arc.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Line.hpp"
#include "PolyLine.hpp"
#include "Triangle.hpp"
#include "RegularPolygon.hpp"
#include "Model2D.hpp"

namespace graphics {

enum class Model2DType {
  circle,
  arc,
  rectangle,
  regularPolygon,
  line,
  polyline,
  triangle,
  polygon,
};

class Model2DFactory {
 public:
  static std::shared_ptr<Model2D> CreateModel2D(const Model2DType aType);

  static std::shared_ptr<Circle> CreateCircle(const std::vector<double>& center,
                                              double radius);
  static std::shared_ptr<Circle> CreateCircle();

  static std::shared_ptr<Arc> CreateArc(const std::vector<double>& center,
                                        double radius, double startAngle,
                                        double endAngle, double thickness);
  static std::shared_ptr<Arc> CreateArc();

  static std::shared_ptr<Rectangle> CreateRectangle(
      const std::vector<double>& upperRight,
      const std::vector<double>& lowerLeft);
  static std::shared_ptr<Rectangle> CreateRectangle();

  static std::shared_ptr<Line> CreateLine(Coordinates2D aStart, Coordinates2D aEnd, double thickness, const Color& aColor);
  static std::shared_ptr<Line> CreateLine();

  static std::shared_ptr<Polyline> CreatePolyline();  
  static std::shared_ptr<Polyline> CreatePolyline(
      const std::vector<Coordinates2D>& points, double thickness,
      const Color& color);
  static std::shared_ptr<Triangle> CreateTriangle();  
  static std::shared_ptr<Triangle> CreateTriangle(const Coordinates2D& point1, const Coordinates2D& point2, const Coordinates2D& point3, const Color& color);
 static std::shared_ptr<Polygon> CreatePolygon(); 
  static std::shared_ptr<Polygon> CreatePolygon(const std::vector<Coordinates2D>& points, const Color& color);

};
}  // namespace graphics
#endif  // MODELACTORY_HPP
