#include "Circle.hpp"

#include <cassert>
#include <iostream>
#include <stdexcept>  // For std::invalid_argument

// Constructor implementation
Circle::Circle(const std::vector<double>& aCenter, const float& aRadius)
    : mRadius(aRadius) {
  assert(aCenter.size() == 2 && "Vector must have exactly 2 elements");
  assert(aRadius >= 0 && "Readius must be positive");
  mCenter = aCenter;  // Store the center if it's valid
}

// Getter for radius
float Circle::getRadius() const { return mRadius; }

// Getter for center
std::vector<double> Circle::getCenter() const { return mCenter; }

// Setter for radius with assert
void Circle::setRadius(const float& aRadius) {
  assert(aRadius > 0 && "Radius must be positive.");
  mRadius = aRadius;
}

// Setter for center with assert
void Circle::setCenter(const std::vector<double>& aCenter) {
  assert(aCenter.size() == 2 &&
         "Center must be a vector of exactly 2 elements.");
  mCenter = aCenter;
}