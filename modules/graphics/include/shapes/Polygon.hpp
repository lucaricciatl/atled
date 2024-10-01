#ifndef POLYGON_HPP
#define POLYGON_HPP

#include "Shape.hpp"
#include <vector>
#include <iostream>


namespace graphics {

class Polygon : public Shape {
private:
    std::vector<Coordinates2D> points; // List of points (each point is a 2D vector)

public:
    // Constructor that accepts a list of points
    Polygon(const std::vector<Coordinates2D>& aPoints);

    // Getter for the list of points
    std::vector<Coordinates2D> getPoints() const;

    void SetPoints(const std::vector<Coordinates2D>& aPoints);
};

}

#endif // POLYGON_HPP
