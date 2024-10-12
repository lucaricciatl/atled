#ifndef MODELFACTORY_HPP
#define MODELFACTORY_HPP

#include <memory>

#include "Arc.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "RegularPolygon.hpp"
#include "Model2D.hpp"

namespace graphics {

enum class Model2DType {
  circle,
  arc,
  rectangle,
  regularPolygon,
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

  //// Factory method to create a RegularPolygon
  // static std::shared_ptr<Shape> createRegularPolygon(const
  // std::vector<double>& center, int sides, double sideLength, double radius);
};
}  // namespace graphics
#endif  // MODELACTORY_HPP
