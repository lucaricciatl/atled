#ifndef ARC_HPP
#define ARC_HPP

#include <cassert>
#include <cmath>
#include <vector>

#include "Polygon.hpp"

namespace graphics {

class Arc : public Shape {
 public:
  // Constructor to initialize Arc with center, radius, angle, and color
  Arc(Coordinates2D aCenter, double aRadius, double aStartAngle,
      double aEndAngle, double thickness, const Color& aColor);

  Arc()  = default;
  // Setter for center
  void setCenter(const Coordinates2D& aCenter);

  // Setter for radius
  void setRadius(double aRadius);

  // Getter for center
  Coordinates2D getCenter() const;

  // Getter for radius
  double getRadius() const;

  void setStartAngle(double aStartAngle);

  // Set end angle of the arc
  void setEndAngle(double aEndAngle);
  // Set thickness of the arc
  void SetThickness(double thickness);
  // Setters

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
