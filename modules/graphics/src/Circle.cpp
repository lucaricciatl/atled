#include "Circle.hpp"

#include <cassert>
#include <iostream>
#include <stdexcept>  // For std::invalid_argument


namespace graphics {

// Constructor implementation
Circle::Circle(const Coordinates2D& aCenter, const float& aRadius)
    : mRadius(aRadius) {
  assert(aRadius >= 0 && "Readius must be positive");
  mCenter = aCenter;  // Store the center if it's valid
}

// Getter for radius
double Circle::getRadius() const { return mRadius; }

// Getter for center
Coordinates2D Circle::getCenter() const { return mCenter; }


// Setter for center with assert
void Circle::setCenter(const Coordinates2D& aCenter) {
  mCenter = aCenter;
}
}