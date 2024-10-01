#include "Polygon.hpp"
#include <cassert>  // For assert
#include <cmath>    // For sqrt


namespace graphics {

// Constructor implementation
Polygon::Polygon(const std::vector<Coordinates2D>& aPoints) {
    assert(aPoints.size() >= 3 && "A polygon must have at least 3 points.");
    points = aPoints;
}

// Getter for the list of points
std::vector<Coordinates2D> Polygon::getPoints() const {
    return points;
}

// Setter for the list of points with validation
void Polygon::SetPoints(const std::vector<Coordinates2D>& aPoints) {
    assert(aPoints.size() >= 3 && "A polygon must have at least 3 points.");
    points = aPoints;
}

}