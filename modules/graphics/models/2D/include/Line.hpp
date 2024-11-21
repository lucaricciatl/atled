#ifndef LINE_HPP
#define LINE_HPP

#include <cassert>
#include <cmath>
#include <vector>
#include "Model.hpp"
#include "Polygon.hpp"

namespace graphics {

class Line : public Model,public Model2D {
 public:
  Line(Coordinates2D aStart, Coordinates2D aEnd, double thickness, const Color& aColor);
  Line() = default;
  
  void SetStartPoint(const Coordinates2D& aStart);
  void SetEndPoint(const Coordinates2D& aEnd);
  Coordinates2D GetStartPoint() const;
  Coordinates2D GetEndPoint() const;
  
  void SetThickness(double thickness);
  void Draw() override;

 private:
  Coordinates2D start;
  Coordinates2D end;
  double mThickness;
};

}  // namespace graphics

#endif  // LINE_HPP