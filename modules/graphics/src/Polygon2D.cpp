#include "Polygon2D.hpp"
#include "raylib.h"  // Assuming you are using raylib for rendering
#include "rlgl.h" // Make sure to include this header

namespace graphics {

void Polygon2D::AddPoint(ColoredPoint2D aPoint) {
    mPoints.push_back(aPoint);
}

void Polygon2D::AddPoints(const std::vector<ColoredPoint2D>& aPoints) {
    mPoints.insert(mPoints.end(), aPoints.begin(), aPoints.end());
}

void Polygon2D::Draw(bool filled = true) const {
  // Ensure we have at least three points to form a polygon
  if (mPoints.size() < 3) {
    return;
  }

  // Create an array of Vector2 for the polygon vertices
  std::vector<raylib::Vector2> vertices;
  vertices.reserve(mPoints.size());

  // Assuming all points have the same color
  raylib::Color fillColor = mPoints[0].color;

  // Populate the vertices vector
  for (const auto& point : mPoints) {
    vertices.push_back(
        {static_cast<float>(point.x), static_cast<float>(point.y)});
  }

  // Set up the color
  raylib::rlColor4ub(fillColor.r, fillColor.g, fillColor.b, fillColor.a);

  if (filled) {
    // Begin drawing triangles
    raylib::rlBegin(RL_TRIANGLES);

    // Triangulate the polygon by creating a fan from the first vertex
    for (size_t i = 1; i < vertices.size() - 1; ++i) {
      raylib::rlVertex2f(vertices[0].x, vertices[0].y);
      raylib::rlVertex2f(vertices[i].x, vertices[i].y);
      raylib::rlVertex2f(vertices[i + 1].x, vertices[i + 1].y);
    }
  } else {
    // Begin drawing lines
    raylib::rlBegin(RL_LINES);

    // Draw lines between each pair of vertices
    for (size_t i = 0; i < vertices.size(); ++i) {
      const raylib::Vector2& start = vertices[i];
      const raylib::Vector2& end = vertices[(i + 1) % vertices.size()];  // Wrap around
      raylib::rlVertex2f(start.x, start.y);
      raylib::rlVertex2f(end.x, end.y);
    }
  }

  raylib::rlEnd();
}



void Polygon2D::Clear() {
    mPoints.clear();
}

size_t Polygon2D::GetPointCount() const {
    return mPoints.size();
}

ColoredPoint2D Polygon2D::GetPoint(size_t aIndex) const {
    if (aIndex < mPoints.size()) {
        return mPoints[aIndex];
    }
    // Handle invalid index by returning a default point
    return ColoredPoint2D();
}

}  // namespace graphics
