#ifndef POLYGON2D_HPP
#define POLYGON2D_HPP

#include <vector>
#include "PointBuffer2D.hpp"


namespace graphics {

class Polygon2DImpl {
 public:
    // Add a single point to the polygon
    void AddPoint(ColoredPoint2D aPoint);

    // Add multiple points to the polygon
    void AddPoints(const std::vector<ColoredPoint2D>& aPoints);

    // Draw the polygon
    void Draw(bool filled) const;

    // Clear all points in the polygon
    void Clear();

    // Get the number of points in the polygon
    size_t GetPointCount() const;

    // Get a point at a specific index
    ColoredPoint2D GetPoint(size_t aIndex) const;

private:
    std::vector<ColoredPoint2D> mPoints;  // Store the points of the polygon
};

}  // namespace graphics

#endif  // POLYGON2D_HPP