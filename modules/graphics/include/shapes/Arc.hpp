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
  Arc(const Coordinates2D& aCenter, double aRadius, double aStartAngle,
      double aEndAngle, const Color& aColor);
  // Setter for center
  void setCenter(const Coordinates2D& aCenter);

  // Setter for radius
  void setRadius(double aRadius);

  // Setter for angle
  void setAngle(double aAngle);

  // Getter for center
  Coordinates2D getCenter() const;

  // Getter for radius
  double getRadius() const;

  // Getter for angle
  double getAngle() const;

  // Redraw the arc (used when any of the properties change)
  void updateArc();

 private:
  Coordinates2D center;
  Color mColor;
  double radius;
  double mStartAngle;
  double mEndAngle;

  // Internal method to generate points for the arc
  std::vector<ColoredPoint2D> generateArcPoints(int aPointCount) const;
};
}  // namespace graphics

#endif  // ARC_HPP
