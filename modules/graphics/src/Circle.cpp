#include "Circle.hpp"

#include <cassert>
#include <iostream>
#include <stdexcept>  // For std::invalid_argument


namespace graphics {


// Getter for radius
double Circle::getRadius() const { return mRadius; }

// Getter for center
Coordinates2D Circle::getCenter() const { return mCenter; }


// Setter for center with assert
void Circle::setCenter(const Coordinates2D& aCenter) {
  mCenter = aCenter;
}

void Circle::setColor(Color aColor) { mColor = aColor; }

// Setter for center with assert
void Circle::SetRadius(const float& aRadius) { mRadius = aRadius; }

void Circle::Draw(){
  DrawCircleV(::Vector2(mCenter.x, mCenter.y),mRadius,mColor);
}
}