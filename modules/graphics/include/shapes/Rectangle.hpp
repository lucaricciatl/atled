#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Shape.hpp"
#include <vector>


namespace graphics {

class Rectangle : public Shape {
private:
    Coordinates2D mUpperRight; // Upper right corner (x, y)
    Coordinates2D mLowerLeft;  // Lower left corner (x, y)

public:
    // Constructor that accepts upper-right and lower-left corners as 2D vectors
    Rectangle(const Coordinates2D& aUpperRight, const Coordinates2D& aLowerLeft);

    // Getters for the upper-right and lower-left corners
    Coordinates2D getUpperRight() const;
    Coordinates2D getLowerLeft() const;

    // Setters for the upper-right and lower-left corners with validation
    void setUpperRight(const Coordinates2D& aUpperRight);
    void setLowerLeft(const Coordinates2D& aLowerLeft);
};

}

#endif // RECTANGLE_HPP
