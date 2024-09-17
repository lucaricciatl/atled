#include "LineBuffer2D.hpp"

namespace graphics {


// Add a point to the buffer
void LineBuffer2D::AddPoint(float aX, float aY) {
    mBuffer.emplace_back(aX, aY);  // Using emplace_back for in-place construction
}

// Retrieve a point at a specific index
ColoredPoint2D LineBuffer2D::GetPoint(size_t aIndex) const {
    if (aIndex < mBuffer.size()) {
        return mBuffer[aIndex];
    }
    // If index is out of bounds, return a default constructed ColoredPoint2D
    return ColoredPoint2D();
}

// Remove a point at a specific index
void LineBuffer2D::RemovePoint(size_t aIndex) {
    if (aIndex < mBuffer.size()) {
        mBuffer.erase(mBuffer.begin() + aIndex);
    }
}

// Clear the buffer and shrink memory usage
void LineBuffer2D::ClearBuffer() {
    mBuffer.clear();
    mBuffer.shrink_to_fit();  // Optimize memory usage by shrinking to fit
}

// Get the size of the buffer
size_t LineBuffer2D::GetSize() const noexcept {
    return mBuffer.size();
}

// Check if the buffer is empty
bool LineBuffer2D::IsEmpty() const noexcept {
    return mBuffer.empty();
}

// Get a constant reference to the buffer
const std::vector<ColoredPoint2D>& LineBuffer2D::GetBuffer() const noexcept {
    return mBuffer;
}

// Set the buffer with a new set of points using move semantics
void LineBuffer2D::SetBuffer(std::vector<ColoredPoint2D> aBuffer) {
    mBuffer = std::move(aBuffer);  // Efficient move to avoid copying
}

// Load the buffer points into the Polyline2D object for drawing
void LineBuffer2D::LoadBuffer() {
    mLine.Clear();  // Clear the polyline before loading new points
    for (const auto& point : mBuffer) {
        mLine.AddPoint(point);  // Assuming Polyline2D has AddPoint() method
    }
}

// Append multiple points to the buffer, using reserve for optimization
void LineBuffer2D::AppendToBuffer(const std::vector<ColoredPoint2D>& aPoints) {
    mBuffer.reserve(mBuffer.size() + aPoints.size());  // Reserve space to avoid reallocations
    mBuffer.insert(mBuffer.end(), aPoints.begin(), aPoints.end());
}

// Append a single point to the buffer using emplace_back
void LineBuffer2D::AppendToBuffer(ColoredPoint2D aPoint) {
    mBuffer.emplace_back(std::move(aPoint));  // Move to avoid copying
}

// Draw the buffer by drawing the Polyline2D
void LineBuffer2D::DrawBuffer() {
    mLine.Clear();  // Clear any previous points in mLine
    mLine.AddPoints(mBuffer);  // Assuming Polyline2D has AddPoints() for bulk insertion
    mLine.Draw();  // Assuming Polyline2D has a Draw() method to render the line
    mLine.Clear();  // Clear after drawing to reset the line
}

}  // namespace graphics
