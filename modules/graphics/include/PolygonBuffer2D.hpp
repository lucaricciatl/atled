#ifndef POLYGONBUFFER2D_HPP
#define POLYGONBUFFER2D_HPP

#include <vector>
#include "Polygon2D.hpp"
#include "PointBuffer2D.hpp"

namespace graphics {

class PolygonBuffer2D {
public:
    // Add a point to the buffer
    void AddPoint(float aX, float aY);

    // Retrieve a point at a specific index
    ColoredPoint2D GetPoint(size_t aIndex) const;

    // Remove a point at a specific index
    void RemovePoint(size_t aIndex);

    // Clear the buffer and shrink memory usage
    void ClearBuffer();

    // Get the size of the buffer
    size_t GetSize() const noexcept;

    // Check if the buffer is empty
    bool IsEmpty() const noexcept;

    // Get a constant reference to the buffer
    const std::vector<ColoredPoint2D>& GetBuffer() const noexcept;

    // Set the buffer with a new set of points using move semantics
    void SetBuffer(std::vector<ColoredPoint2D> aBuffer);

    // Load the buffer points into the Polygon2D object for drawing
    void LoadBuffer();

    // Append multiple points to the buffer, using reserve for optimization
    void AppendToBuffer(const std::vector<ColoredPoint2D>& aPoints);

    // Append a single point to the buffer using emplace_back
    void AppendToBuffer(ColoredPoint2D aPoint);

    // Draw the buffer by drawing the Polygon2D
    void DrawBuffer();

private:
    std::vector<ColoredPoint2D> mBuffer;  // Buffer to store points
    Polygon2D mPolygon;                   // Polygon object for drawing
};

}  // namespace graphics

#endif  // POLYGONBUFFER2D_HPP
