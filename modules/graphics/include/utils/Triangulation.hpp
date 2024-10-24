#ifndef TRIANGULATION_HPP
#define TRIANGULATION_HPP

#include <vector>
#include "Triangle.hpp"

namespace graphics {

class Triangulation {
 public:
  // Constructor with points of the polygon (in clockwise or counterclockwise order)
  Triangulation(const std::vector<Coordinates2D>& points, const Color& color);

  // Get the resulting triangles after triangulation
std::vector<Triangle> GetTriangles();

 private:
  // Helper function to perform the triangulation
  void PerformTriangulation();

  // Check if a point is inside a triangle
  bool IsPointInTriangle(const Coordinates2D& point, const Coordinates2D& a, const Coordinates2D& b, const Coordinates2D& c) const;

  // Check if a triangle is an "ear" (convex and no other points inside)
  bool IsEar(size_t i) const;

  std::vector<Coordinates2D> mPoints;
  std::vector<Triangle> mTriangles;
  Color mColor;
};

}  // namespace graphics

#endif  // TRIANGULATION_HPP
