#ifndef POLYGON_HPP
#define POLYGON_HPP

#include "Shape.hpp"
#include <vector>
#include <iostream>


namespace graphics {

class Polygon : public Shape {
private:

public:
    // Constructor that accepts a list of points
    Polygon(std::vector<Coordinates2D> aPoints, Color aColor);

    void SetPoints(std::vector<Coordinates2D> aPoints,Color aColor);

    void Draw();
};

}

#endif // POLYGON_HPP
