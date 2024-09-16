#include "Polyline2D.hpp"
#include "PointBuffer2D.hpp"
#include "raylib.h"

namespace graphics {

void Polyline2D::AddPoint(ColoredPoint2D aPoint) { mPoints.push_back(aPoint); }

void Polyline2D::AddPoints(const std::vector<ColoredPoint2D>& aPoints) {
  mPoints.insert(mPoints.end(), aPoints.begin(), aPoints.end());
}
void Polyline2D::Draw() const {
  // Ensure we have at least two points to draw a polyline
  if (mPoints.size() < 2) {
    return;
  }

  // Iterate through the points and draw lines between consecutive points
  for (size_t i = 0; i < mPoints.size() - 1; ++i) {
    // Get the start and end points for the line
    int startPosX = mPoints[i].x;
    int startPosY = mPoints[i].y;
    int endPosX = mPoints[i + 1].x;
    int endPosY = mPoints[i + 1].y;

    // Call the DrawLine function with the start and end points
    // Assuming the color is predefined or set somewhere else
    DrawLine(startPosX, startPosY, endPosX, endPosY, mPoints[i].color);
  }
}

void Polyline2D::Clear() { mPoints.clear(); }
size_t Polyline2D::GetPointCount() const { return mPoints.size(); }

ColoredPoint2D Polyline2D::GetPoint(size_t aIndex) const {
  if (aIndex < mPoints.size()) {
    return mPoints[aIndex];
  }
  // Handle invalid index, possibly throw an exception or return a default
  // Point2D
  return ColoredPoint2D();
}
}  // namespace graphics
