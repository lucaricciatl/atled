#include "Polygon.hpp"
#include <cassert>  // For assert
#include <cmath>    // For sqrt
#include <algorithm>

namespace graphics {

namespace{
// Function to efficiently convert Coordinates2D to ColoredPoint2D
std::vector<ColoredPoint2D> TransformToColoredPoints(
    const std::vector<Coordinates2D>& coordinates, const glwp::Color& color) {
    std::vector<ColoredPoint2D> coloredPoints;
    
    // Reserve memory to avoid reallocations
    coloredPoints.reserve(coordinates.size());
    
    // Use std::transform to apply the transformation efficiently
    std::transform(coordinates.begin(), coordinates.end(), std::back_inserter(coloredPoints),
                   [&color](const Coordinates2D& coord) {
                       return ColoredPoint2D(coord, color);  // Convert to ColoredPoint2D
                   });

    return coloredPoints;
}

}
// Constructor that accepts a list of points and a color
Polygon::Polygon(std::vector<Coordinates2D> aPoints, glwp::Color aColor) {
    mBuffer.SetBuffer(TransformToColoredPoints(aPoints,aColor));
    mBuffer.LoadBuffer();
}

Polygon::Polygon(std::vector<ColoredPoint2D> aPoints){
    mBuffer.SetBuffer(aPoints);
    mBuffer.LoadBuffer();
};

// Setter for the list of points with validation
void Polygon::SetPoints(std::vector<Coordinates2D> aPoints,
                        glwp::Color aColor) {
    assert(aPoints.size() >= 3 && "A polygon must have at least 3 points.");
    mBuffer.SetBuffer(TransformToColoredPoints(aPoints,aColor));
    mBuffer.LoadBuffer();
}
void Polygon::SetPoints(std::vector<ColoredPoint2D> aPoints) {
  mBuffer.SetBuffer(aPoints);
  mBuffer.LoadBuffer();
};

}