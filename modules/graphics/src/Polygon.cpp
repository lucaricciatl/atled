#include "Polygon.hpp"
#include <cassert>  // For assert
#include <cmath>    // For sqrt

// Constructor implementation
Polygon::Polygon(const std::vector<std::vector<double>>& aPoints) {
    assert(aPoints.size() >= 3 && "A polygon must have at least 3 points.");
    for (const auto& point : aPoints) {
        assert(point.size() == 2 && "Each point must be a 2D vector (x, y).");
    }
    points = aPoints;
}

// Getter for the list of points
std::vector<std::vector<double>> Polygon::getPoints() const {
    return points;
}

// Setter for the list of points with validation
void Polygon::setPoints(const std::vector<std::vector<double>>& aPoints) {
    assert(aPoints.size() >= 3 && "A polygon must have at least 3 points.");
    for (const auto& point : aPoints) {
        assert(point.size() == 2 && "Each point must be a 2D vector (x, y).");
    }
    points = aPoints;
}
