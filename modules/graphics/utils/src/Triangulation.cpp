#include "Triangulation.hpp"
#include <numeric> // For std::iota


namespace graphics {

Triangulation::Triangulation(const std::vector<Coordinates2D>& points, const Color& color)
    : mPoints(points), mColor(color) {
  PerformTriangulation();
}

std::vector<Triangle> Triangulation::GetTriangles() {
  return mTriangles;
}

void Triangulation::PerformTriangulation() {
  if (mPoints.size() < 3) return;  // Need at least 3 points to form a triangle
  
  std::vector<size_t> indices(mPoints.size());
  std::iota(indices.begin(), indices.end(), 0); // Fill indices with 0, 1, 2, ..., n-1

  while (indices.size() > 2) {
    size_t earIndex = -1;
    for (size_t i = 0; i < indices.size(); ++i) {
      if (IsEar(i)) {
        earIndex = i;
        break;
      }
    }

    if (earIndex == -1) break;  // No valid ear found, exit loop

    size_t prev = (earIndex == 0) ? indices.size() - 1 : earIndex - 1;
    size_t next = (earIndex == indices.size() - 1) ? 0 : earIndex + 1;

    mTriangles.emplace_back(
      mPoints[indices[prev]],
      mPoints[indices[earIndex]],
      mPoints[indices[next]],
      mColor
    );

    indices.erase(indices.begin() + earIndex); // Remove the ear vertex from the list
  }
}

bool Triangulation::IsEar(size_t i) const {
  size_t prev = (i == 0) ? mPoints.size() - 1 : i - 1;
  size_t next = (i == mPoints.size() - 1) ? 0 : i + 1;

  const Coordinates2D& a = mPoints[prev];
  const Coordinates2D& b = mPoints[i];
  const Coordinates2D& c = mPoints[next];

  // Check if the triangle is convex
  if ((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) >= 0) {
    return false;
  }

  // Check if no other points are inside this triangle
  for (size_t j = 0; j < mPoints.size(); ++j) {
    if (j != prev && j != i && j != next && IsPointInTriangle(mPoints[j], a, b, c)) {
      return false;
    }
  }

  return true;
}

bool Triangulation::IsPointInTriangle(const Coordinates2D& point, const Coordinates2D& a, const Coordinates2D& b, const Coordinates2D& c) const {
  auto sign = [](const Coordinates2D& p1, const Coordinates2D& p2, const Coordinates2D& p3) {
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
  };

  bool b1 = sign(point, a, b) < 0.0f;
  bool b2 = sign(point, b, c) < 0.0f;
  bool b3 = sign(point, c, a) < 0.0f;

  return ((b1 == b2) && (b2 == b3));
}

}  // namespace graphics
