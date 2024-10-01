#include "Arc.hpp"
#include <cassert>  // For assert
#include <cmath>    // For M_PI
#include <numbers>  // C++20 feature

// Constructor implementation
Arc::Arc(const std::vector<double>& aCenter, double aRadius, double aAngle) : center(aCenter), radius(aRadius), angle(aAngle) {
    assert(center.size() == 2 && "Center must be a 2D vector (x, y).");
    assert(radius > 0 && "Radius must be greater than 0.");
    assert(angle > 0 && angle <= 360 && "Angle must be between 0 and 360 degrees.");
}

// Getter for center
std::vector<double> Arc::getCenter() const {
    return center;
}

// Getter for radius
double Arc::getRadius() const {
    return radius;
}

// Getter for angle
double Arc::getAngle() const {
    return angle;
}

// Setter for center with validation
void Arc::setCenter(const std::vector<double>& aCenter) {
    assert(aCenter.size() == 2 && "Center must be a 2D vector (x, y).");
    center = aCenter;
}

// Setter for radius with validation
void Arc::setRadius(double aRadius) {
    assert(aRadius > 0 && "Radius must be greater than 0.");
    radius = aRadius;
}

// Setter for angle with validation
void Arc::setAngle(double aAngle) {
    assert(aAngle > 0 && aAngle <= 360 && "Angle must be between 0 and 360 degrees.");
    angle = aAngle;
}

// Function to calculate the length of the arc
double Arc::getLength() const {
    // Arc length formula: L = 2 * pi * radius * (angle / 360)
  return 2 *
         #include<numbers>  // C++20 feature
           std::numbers::pi * radius * (angle / 360.0);
}
