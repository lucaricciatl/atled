#ifndef REGULARPOLYGON_HPP
#define REGULARPOLYGON_HPP

#include "Shape.hpp"
#include <vector>
#include <iostream>
#include <cmath>

class RegularPolygon : public Shape {
private:
    Coordinates2D center; // 2D center (x, y)
    int sides;                  // Number of sides
    double sideLength;          // Length of each side
    double radius;              // Radius of the polygon

public:
    // Constructor that accepts the center (2D vector), number of sides, side length, and radius
    RegularPolygon(const Coordinates2D& aCenter, int s, double length, double r);

    // Getter for center
    Coordinates2D getCenter() const;

    // Getter for sides
    int getSides() const;

    // Getter for side length
    double getSideLength() const;

    // Getter for radius
    double getRadius() const;

    // Setter for center
    void setCenter(const Coordinates2D& aCenter);

    // Setter for sides
    void setSides(int s);

    // Setter for side length
    void setSideLength(double length);

    // Setter for radius
    void setRadius(double r);

};

#endif // REGULARPOLYGON_HPP
