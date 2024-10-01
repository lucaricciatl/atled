#include "Rectangle.hpp"
#include <iostream>
#include <cassert> 

// Constructor implementation
Rectangle::Rectangle(const std::vector<double>& aUpperRight, const std::vector<double>& aLowerLeft) {
    assert(aUpperRight.size() == 2 && "Upper right corner must be a vector of exactly 2 elements.");
    assert(aLowerLeft.size() == 2 && "Lower left corner must be a vector of exactly 2 elements.");
    assert(aUpperRight[0] > aLowerLeft[0] && aUpperRight[1] > aLowerLeft[1] &&
           "Upper right corner must be greater than lower left corner.");

    mUpperRight = aUpperRight;
    mLowerLeft = aLowerLeft;
}

// Setter for upper-right corner with validation
void Rectangle::setUpperRight(const std::vector<double>& aUpperRight) {
    assert(aUpperRight.size() == 2 && "Upper right corner must be a vector of exactly 2 elements.");
    assert(aUpperRight[0] > mLowerLeft[0] && aUpperRight[1] > mLowerLeft[1] &&
           "Upper right corner must be greater than the current lower left corner.");
    
    mUpperRight = aUpperRight;
}

// Setter for lower-left corner with validation
void Rectangle::setLowerLeft(const std::vector<double>& aLowerLeft) {
    assert(aLowerLeft.size() == 2 && "Lower left corner must be a vector of exactly 2 elements.");
    assert(mUpperRight[0] > aLowerLeft[0] && mUpperRight[1] > aLowerLeft[1] &&
           "Lower left corner must be smaller than the current upper right corner.");
    
    mLowerLeft = aLowerLeft;
}

// Getter for upper-right corner
std::vector<double> Rectangle::getUpperRight() const {
    return mUpperRight;
}

// Getter for lower-left corner
std::vector<double> Rectangle::getLowerLeft() const {
    return mLowerLeft;
}
