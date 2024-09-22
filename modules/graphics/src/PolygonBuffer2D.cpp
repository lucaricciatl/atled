#include "PolygonBuffer2D.hpp"

namespace graphics {

// Add a point to the buffer
void PolygonBuffer2D::AddPoint(float aX, float aY) {
    mBuffer.emplace_back(aX, aY);  // Using emplace_back for in-place construction
}

// Retrieve a point at a specific index
ColoredPoint2D PolygonBuffer2D::GetPoint(size_t aIndex) const {
    if (aIndex < mBuffer.size()) {
        return mBuffer[aIndex];
    }
    // If index is out of bounds, return a default constructed ColoredPoint2D
    return ColoredPoint2D();
}

// Remove a point at a specific index
void PolygonBuffer2D::RemovePoint(size_t aIndex) {
    if (aIndex < mBuffer.size()) {
        mBuffer.erase(mBuffer.begin() + aIndex);
    }
}

// Clear the buffer and shrink memory usage
void PolygonBuffer2D::ClearBuffer() {
    mBuffer.clear();
    mBuffer.shrink_to_fit();  // Optimize memory usage by shrinking to fit
}

// Get the size of the buffer
size_t PolygonBuffer2D::GetSize() const noexcept {
    return mBuffer.size();
}

// Check if the buffer is empty
bool PolygonBuffer2D::IsEmpty() const noexcept {
    return mBuffer.empty();
}

// Get a constant reference to the buffer
const std::vector<ColoredPoint2D>& PolygonBuffer2D::GetBuffer() const noexcept {
    return mBuffer;
}

// Set the buffer with a new set of points using move semantics
void PolygonBuffer2D::SetBuffer(std::vector<ColoredPoint2D> aBuffer) {
    mBuffer = std::move(aBuffer);  // Efficient move to avoid copying
}

// Load the buffer points into the Polygon2D object for drawing
void PolygonBuffer2D::LoadBuffer() {
    mPolygon.Clear();  // Clear the polygon before loading new points
    for (const auto& point : mBuffer) {
        mPolygon.AddPoint(point);  // Assuming Polygon2D has AddPoint() method
    }
}

// Append multiple points to the buffer, using reserve for optimization
void PolygonBuffer2D::AppendToBuffer(const std::vector<ColoredPoint2D>& aPoints) {
    mBuffer.reserve(mBuffer.size() + aPoints.size());  // Reserve space to avoid reallocations
    mBuffer.insert(mBuffer.end(), aPoints.begin(), aPoints.end());
}

// Append a single point to the buffer using emplace_back
void PolygonBuffer2D::AppendToBuffer(ColoredPoint2D aPoint) {
    mBuffer.emplace_back(std::move(aPoint));  // Move to avoid copying
}

// Draw the buffer by drawing the Polygon2D
void PolygonBuffer2D::DrawBuffer() {
    mPolygon.Clear();             // Clear any previous points in mPolygon
    mPolygon.AddPoints(mBuffer);  // Assuming Polygon2D has AddPoints() for bulk insertion
    mPolygon.Draw(true);              // Assuming Polygon2D has a Draw() method to render the polygon
}

}  // namespace graphics
