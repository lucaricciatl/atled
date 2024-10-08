#ifndef ARC_HPP
#define ARC_HPP

#include <cassert>
#include <cmath>
#include <vector>

#include "Polygon.hpp"

namespace graphics {

class Arc : public Shape {
 public:
  Arc(Coordinates2D aCenter, double aRadius, double aStartAngle,
      double aEndAngle, double thickness, const Color& aColor);
  Arc()  = default;
  void SetCenter(const Coordinates2D& aCenter);
  void SetRadius(double aRadius);
  Coordinates2D GetCenter() const;
  double GetRadius() const;
  void SetStartAngle(double aStartAngle);
  void SetEndAngle(double aEndAngle);
  void SetThickness(double thickness);
  void SetColor(Color& aColor);
  void Draw() override;


 private:
  int ComputePointsNumber();
  Coordinates2D center;
  ::Color mColor;
  double radius;
  double mStartAngle;
  double mEndAngle;
  double mThickess;

};
}  // namespace graphics

#endif  // ARC_HPP
