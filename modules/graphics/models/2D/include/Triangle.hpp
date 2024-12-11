#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <array>
#include "Model2D.hpp"
#include <vector>
#include "raylib.hpp"

namespace graphics
{

  class Triangle : public Model2D
  {

  public:
    // Constructor with parameters
    Triangle(const Coordinates2D &point1, const Coordinates2D &point2, const Coordinates2D &point3, const Color &color);
    // Default constructor
    Triangle() = default;

    // Setters and Getters
    void SetPoints(const Coordinates2D &point1, const Coordinates2D &point2, const Coordinates2D &point3);
    std::array<Coordinates2D, 3> GetPoints() const;

    void SetColor(const Color &color);
    graphics::Color GetColor() const;

    // Overridden Draw method
    void Draw() override;

  private:
    std::array<Coordinates2D, 3> mPoints;
    graphics::Color mColor;
  };

  class Triangulation
  {
  public:
    // Constructor with points of the polygon (in clockwise or counterclockwise order)
    Triangulation(const std::vector<Coordinates2D> &points, const Color &color);

    // Get the resulting triangles after triangulation
    std::vector<Triangle> GetTriangles();

  private:
    // Helper function to perform the triangulation
    void PerformTriangulation();

    // Check if a point is inside a triangle
    bool IsPointInTriangle(const Coordinates2D &point, const Coordinates2D &a, const Coordinates2D &b, const Coordinates2D &c) const;

    // Check if a triangle is an "ear" (convex and no other points inside)
    bool IsEar(size_t i) const;

    std::vector<Coordinates2D> mPoints;
    std::vector<Triangle> mTriangles;
    Color mColor;
  };

} // namespace graphics

#endif // TRIANGLE_HPP
