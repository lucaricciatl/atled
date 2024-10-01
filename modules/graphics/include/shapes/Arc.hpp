#ifndef ARC_HPP
#define ARC_HPP

#include "Shape.hpp"
#include <vector>
#include <iostream>
#include <cmath>


namespace graphics {

class Arc : public Shape {
private:
    Coordinates2D center; // 2D center (x, y)
    double radius;              // Radius of the arc
    double angle;               // Angle of the arc in degrees clockwise

public:
    // Constructor that accepts center (2D vector), radius, and angle
    Arc(const Coordinates2D& aCenter, double aRadius, double aAngle);

    // Getter for center
    Coordinates2D getCenter() const;

    // Getter for radius
    double getRadius() const;

    // Getter for angle
    double getAngle() const;

    // Setter for center
    void setCenter(const Coordinates2D& aCenter);

    // Setter for radius
    void setRadius(double aRadius);

    // Setter for angle
    void setAngle(double aAngle);

    // Function to calculate the length of the arc
    double getLength() const;
};

}

#endif // ARC_HPP
