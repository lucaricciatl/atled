#ifndef POLYGON_HPP
#define POLYGON_HPP

#include "Shape.hpp"
#include <vector>
#include <iostream>

class Polygon : public Shape {
private:
    std::vector<std::vector<double>> points; // List of points (each point is a 2D vector)

public:
    // Constructor that accepts a list of points
    Polygon(const std::vector<std::vector<double>>& aPoints);

    // Getter for the list of points
    std::vector<std::vector<double>> getPoints() const;
};

#endif // POLYGON_HPP
