#include "Arc.hpp"
#include "glwp.hpp"
#include <cassert>  // For assert
#include <cmath>    // For M_PI
#include <numbers>  // C++20 feature

namespace graphics {

// Constructor
Arc::Arc(Coordinates2D aCenter, double aRadius, double aStartAngle,
         double aEndAngle, double thickness, const glwp::Color& aColor)
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
void Arc::SetEndAngle(double aEndAngle) { mEndAngle = aEndAngle; }

// Set thickness of the arc
void Arc::SetThickness(double thickness) { mThickess = thickness; }

// Setters
void Arc::SetCenter(const Coordinates2D& aCenter) { center = aCenter; }
void Arc::SetStartAngle(double aStartAngle) { mStartAngle = aStartAngle; };

void Arc::SetRadius(double aRadius) {
  assert(aRadius > 0 && "Radius must be greater than 0.");
  radius = aRadius;
}

void Arc::SetColor(glwp::Color& aColor){ mColor = aColor; }

// Getters
Coordinates2D Arc::GetCenter() const { return center; }

double Arc::GetRadius() const { return radius; }

int Arc::ComputePointsNumber() { 
   constexpr int pointsPerRadiant = 50;
    return   ( (mEndAngle-mStartAngle)* (radius + mThickess) /pointsPerRadiant);
}

void Arc::Draw() {
  DrawRing(glwp::Vector2(center.x, center.y), radius - mThickess,
           radius + mThickess, mStartAngle, mEndAngle, ComputePointsNumber(),
           mColor);
}
}  // namespace graphics
