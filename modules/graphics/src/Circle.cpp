#include "Circle.hpp"

#include <cassert>
#include <iostream>
#include <stdexcept>  // For std::invalid_argument

// Constructor implementation
Circle::Circle(const Coordinates2D& aCenter, const float& aRadius)
    : mRadius(aRadius) {
  assert(aRadius >= 0 && "Readius must be positive");
  mCenter = aCenter;  // Store the center if it's valid
}

// Getter for radius
float Circle::getRadius() const { return mRadius; }

// Getter for center
Coordinates2D Circle::getCenter() const { return mCenter; }

// Setter for radius with assert
void Circle::setRadius(const float& aRadius) {
  assert(aRadius > 0 && "Radius must be positive.");
  mRadius = aRadius;
}

// Setter for center with assert
void Circle::setCenter(const Coordinates2D& aCenter) {
  mCenter = aCenter;
}