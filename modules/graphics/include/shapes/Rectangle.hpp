#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Shape.hpp"
#include <vector>

class Rectangle : public Shape {
private:
    std::vector<double> mUpperRight; // Upper right corner (x, y)
    std::vector<double> mLowerLeft;  // Lower left corner (x, y)

public:
    // Constructor that accepts upper-right and lower-left corners as 2D vectors
    Rectangle(const std::vector<double>& aUpperRight, const std::vector<double>& aLowerLeft);

    // Getters for the upper-right and lower-left corners
    std::vector<double> getUpperRight() const;
    std::vector<double> getLowerLeft() const;

    // Setters for the upper-right and lower-left corners with validation
    void setUpperRight(const std::vector<double>& aUpperRight);
    void setLowerLeft(const std::vector<double>& aLowerLeft);
};

#endif // RECTANGLE_HPP
