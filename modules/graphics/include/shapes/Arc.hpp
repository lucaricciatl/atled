#ifndef ARC_HPP
#define ARC_HPP

#include "Shape.hpp"
#include <vector>
#include <iostream>
#include <cmath>

class Arc : public Shape {
private:
    std::vector<double> center; // 2D center (x, y)
    double radius;              // Radius of the arc
    double angle;               // Angle of the arc in degrees

public:
    // Constructor that accepts center (2D vector), radius, and angle
    Arc(const std::vector<double>& aCenter, double aRadius, double aAngle);

    // Getter for center
    std::vector<double> getCenter() const;

    // Getter for radius
    double getRadius() const;

    // Getter for angle
    double getAngle() const;

    // Setter for center
    void setCenter(const std::vector<double>& aCenter);

    // Setter for radius
    void setRadius(double aRadius);

    // Setter for angle
    void setAngle(double aAngle);

    // Function to calculate the length of the arc
    double getLength() const;
};

#endif // ARC_HPP
