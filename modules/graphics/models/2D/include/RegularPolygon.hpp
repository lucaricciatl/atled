#ifndef REGULARPOLYGON_HPP
#define REGULARPOLYGON_HPP

#include "Model2D.hpp"
#include <vector>
#include <iostream>
#include <cmath>

namespace graphics {

class RegularPolygon : public Model2D {
public:
    // Constructor
    RegularPolygon(const Coordinates2D& aCenter, int sides, double sideLength, double radius);

    // Getters
    Coordinates2D getCenter() const;
    int getSides() const;
    double getSideLength() const;
    double getRadius() const;

    // Setters
    void setCenter(const Coordinates2D& aCenter);
    void setSides(int sides);
    void setSideLength(double length);
    void setRadius(double radius);

    // Additional methods
    void Draw() override;

private:
    Coordinates2D center;
    int sides;
    double sideLength;
    double radius;
};


}
#endif // REGULARPOLYGON_HPP
