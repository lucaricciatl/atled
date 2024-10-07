#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Shape.hpp"
#include <vector>


namespace graphics {

class Rectangle : public Shape {
private:
    Coordinates2D mUpperRight; 
    Coordinates2D mLowerLeft;  

public:
    Rectangle(const Coordinates2D& aUpperRight, const Coordinates2D& aLowerLeft);

    Coordinates2D getUpperRight() const;
    Coordinates2D getLowerLeft() const;

    void setUpperRight(const Coordinates2D& aUpperRight);
    void setLowerLeft(const Coordinates2D& aLowerLeft);
};

}

#endif // RECTANGLE_HPP
