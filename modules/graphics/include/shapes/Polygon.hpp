#ifndef POLYGON_HPP
#define POLYGON_HPP

#include "Shape.hpp"
#include <vector>
#include <iostream>
#include "glwp.hpp"

namespace graphics {

class Polygon : public Shape {
private:

public:
    // Constructor that accepts a list of points
 Polygon();
    Polygon(std::vector<Coordinates2D> aPoints, Color aColor);
    Polygon(std::vector<ColoredPoint2D> aPoints);

    void SetPoints(std::vector<Coordinates2D> aPoints,Color aColor);
    void SetPoints(std::vector<ColoredPoint2D> aPoints);

};

}

#endif // POLYGON_HPP
