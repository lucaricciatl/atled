#ifndef ARC_HPP
#define ARC_HPP

#include <cassert>
#include <cmath>
#include <vector>
#include "Model2D.hpp"
#include "Polygon.hpp"

namespace graphics {

class Arc : public Model2D {
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
  void Draw() override;


 private:
  int ComputePointsNumber();
  Coordinates2D center;
  double radius;
  double mStartAngle;
  double mEndAngle;
  double mThickess;

};
}  // namespace graphics

#endif  // ARC_HPP
