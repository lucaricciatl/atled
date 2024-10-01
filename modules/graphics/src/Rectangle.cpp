#include "Rectangle.hpp"
#include <iostream>
#include <cassert> 

// Constructor implementation
Rectangle::Rectangle(const Coordinates2D& aUpperRight,
                     const Coordinates2D& aLowerLeft) {
    mUpperRight = aUpperRight;
    mLowerLeft = aLowerLeft;
}

// Setter for upper-right corner with validation
void Rectangle::setUpperRight(const Coordinates2D& aUpperRight) {
    mUpperRight = aUpperRight;
}

// Setter for lower-left corner with validation
void Rectangle::setLowerLeft(const Coordinates2D& aLowerLeft) {
    mLowerLeft = aLowerLeft;
}

// Getter for upper-right corner
Coordinates2D Rectangle::getUpperRight() const {
    return mUpperRight;
}

// Getter for lower-left corner
Coordinates2D Rectangle::getLowerLeft() const {
    return mLowerLeft;
}
