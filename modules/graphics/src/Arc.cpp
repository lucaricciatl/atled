#include "Arc.hpp"
#include <cassert>  // For assert
#include <cmath>    // For M_PI
#include <numbers>  // C++20 feature

// Constructor implementation
Arc::Arc(const Coordinates2D& aCenter, double aRadius, double aAngle) : center(aCenter), radius(aRadius), angle(aAngle) {
    assert(radius > 0 && "Radius must be greater than 0.");
    assert(angle > 0 && angle <= 360 && "Angle must be between 0 and 360 degrees.");
}

// Getter for center
Coordinates2D Arc::getCenter() const {
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
void Arc::setCenter(const Coordinates2D& aCenter) {
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