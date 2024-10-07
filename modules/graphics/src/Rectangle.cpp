#include "Rectangle.hpp"
#include <iostream>
#include <cassert> 


namespace graphics {

Rectangle::Rectangle(const Coordinates2D& aUpperRight,
                     const Coordinates2D& aLowerLeft) {
  mUpperRight = aUpperRight;
  mLowerLeft = aLowerLeft;
}

void Rectangle::setUpperRight(const Coordinates2D& aUpperRight) {
  mUpperRight = aUpperRight;
}

void Rectangle::setLowerLeft(const Coordinates2D& aLowerLeft) {
  mLowerLeft = aLowerLeft;
}

Coordinates2D Rectangle::getUpperRight() const { return mUpperRight; }

Coordinates2D Rectangle::getLowerLeft() const { return mLowerLeft; }
}  // namespace graphics