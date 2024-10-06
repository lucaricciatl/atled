#include "Arc.hpp"

#include <cassert>  // For assert
#include <cmath>    // For M_PI
#include <numbers>  // C++20 feature

namespace graphics {

// Constructor
Arc::Arc(Coordinates2D aCenter, double aRadius, double aStartAngle,
         double aEndAngle,double thickness, const Color& aColor)
    : Shape(),
      center(aCenter),
      radius(aRadius),
      mStartAngle(aStartAngle),
      mEndAngle(aEndAngle),
      mColor(aColor) ,
      mThickess(thickness){
  assert(radius > 0 && "Radius must be greater than 0.");
}

// Set end angle of the arc
void Arc::setEndAngle(double aEndAngle) { mEndAngle = aEndAngle; }

// Set thickness of the arc
void Arc::SetThickness(double thickness) { mThickess = thickness; }

// Setters
void Arc::setCenter(const Coordinates2D& aCenter) { center = aCenter; }
void Arc::setStartAngle(double aStartAngle) { mStartAngle = aStartAngle; };

void Arc::setRadius(double aRadius) {
  assert(aRadius > 0 && "Radius must be greater than 0.");
  radius = aRadius;
}

void Arc::SetColor(Color& aColor){ mColor = aColor; }

// Getters
Coordinates2D Arc::getCenter() const { return center; }

double Arc::getRadius() const { return radius; }

int Arc::ComputePointsNumber() { 
   constexpr int pointsPerRadiant = 50;
    return   ( (mEndAngle-mStartAngle)* (radius + mThickess) /pointsPerRadiant);
}

void Arc::Draw() {
  DrawRing(::Vector2(center.x, center.y), radius - mThickess,
           radius + mThickess, mStartAngle, mEndAngle, ComputePointsNumber(),
           mColor);
}
}  // namespace graphics
