#include "Model2DFactory.hpp"


namespace graphics {

std::shared_ptr<Model2D> Model2DFactory::CreateModel2D(const Model2DType aType) {
    switch (aType) {
        case Model2DType::arc:
            return CreateArc();  
        case Model2DType::circle:
            return CreateCircle();
        case Model2DType::rectangle:
          return CreateRectangle();
        default:
            return nullptr;
    }
}

std::shared_ptr<Circle> CreateCircle(const std::vector<double>& center,
                                     double radius){

    return std::make_shared<Circle>();
}

std::shared_ptr<Circle> Model2DFactory::CreateCircle() {
  return std::make_shared<Circle>(); 
}

std::shared_ptr<Rectangle> Model2DFactory::CreateRectangle(const std::vector<double>& upperRight, const std::vector<double>& lowerLeft) {
    return std::make_shared<Rectangle>();
}

std::shared_ptr<Rectangle> Model2DFactory::CreateRectangle() {
  return std::make_shared<Rectangle>();
}
//
//// Factory method to create a RegularPolygon
//std::shared_ptr<Model2D> Model2DFactory::createRegularPolygon(const std::vector<double>& center, int sides, double sideLength, double radius) {
//    return std::make_shared<RegularPolygon>(center, sides, sideLength, radius);
//}

// Factory method to create an Arc
std::shared_ptr<Arc> Model2DFactory::CreateArc(const std::vector<double>& center, double radius, double startAngle, double endAngle, double thickness) {
    return std::make_shared<Arc>(Coordinates2D(center[0], center[1]), radius, startAngle, endAngle, thickness, Color{255, 0, 0, 255});  
}

std::shared_ptr<Arc> Model2DFactory::CreateArc() {
  return std::make_shared<Arc>();  // Example color
}

}