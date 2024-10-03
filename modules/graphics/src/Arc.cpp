#include "Arc.hpp"
#include <cassert>  // For assert
#include <cmath>    // For M_PI
#include <numbers>  // C++20 feature


namespace graphics {

// Constructor
Arc::Arc(const Coordinates2D& aCenter, double aRadius, double aStartAngle,
         double aEndAngle, const Color& aColor)
    : Shape(),
      center(aCenter),
      radius(aRadius),
      mStartAngle(aStartAngle),
      mEndAngle(aEndAngle) ,mColor(aColor) {
    assert(radius > 0 && "Radius must be greater than 0.");
    updateArc();  // Generate points for the arc and set them in the base Polygon class
}

// Setters
void Arc::setCenter(const Coordinates2D& aCenter) {
    center = aCenter;
    updateArc();
}

void Arc::setRadius(double aRadius) {
    assert(aRadius > 0 && "Radius must be greater than 0.");
    radius = aRadius;
    updateArc();
}

// Getters
Coordinates2D Arc::getCenter() const {
    return center;
}

double Arc::getRadius() const {
    return radius;
}

// Method to update the arc by generating points and setting them in the Polygon base class
void Arc::updateArc() {
    const int pointCount = static_cast<int>(std::ceil((mEndAngle-mStartAngle) / 30.0));  // Example: generate a point every 5 degrees
    auto arcPoints = generateArcPoints(pointCount);
    mBuffer.SetBuffer(arcPoints);  // Set the generated points in the Polygon class, example color red
    mBuffer.LoadBuffer();

}


std::vector<ColoredPoint2D> Arc::generateArcPoints(int aPointCount) const {
  std::vector<ColoredPoint2D> points;
  points.reserve(aPointCount);

  double angleIncrement = (mEndAngle - mStartAngle) /
                          (aPointCount - 1);  // Dividi l'arco in punti uguali

  for (int i = 0; i < aPointCount;
       ++i) {  // Usa < invece di <= per evitare un punto in più
    double theta =
        mStartAngle + i * angleIncrement;  // Calcola l'angolo corrente
    double radian =
        theta * (std::numbers::pi / 180.0);  // Converti da gradi a radianti
    double x = center.x + radius * std::cos(radian);  // Calcola la coordinata x
    double y = center.y + radius * std::sin(radian);  // Calcola la coordinata y
    points.push_back(
        ColoredPoint2D(x, y, mColor));  // Aggiungi il punto alla lista
  }

  return points;
}
}