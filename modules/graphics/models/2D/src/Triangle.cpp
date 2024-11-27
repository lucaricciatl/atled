#include "Triangle.hpp"

namespace graphics {

Triangle::Triangle(const Coordinates2D& point1, const Coordinates2D& point2, const Coordinates2D& point3, const raylib::Color& color)
    : mPoints{point1, point2, point3}, mColor(color) {}

void Triangle::SetPoints(const Coordinates2D& point1, const Coordinates2D& point2, const Coordinates2D& point3) {
  mPoints = {point1, point2, point3};
}

std::array<Coordinates2D, 3> Triangle::GetPoints() const {
  return mPoints;
}

void Triangle::SetColor(const Color& color) {
  mColor = color;
}

 raylib::Color Triangle::GetColor() const {
  return mColor;
}

void Triangle::Draw() {
  Vector2 v1 = ComputeGlobalPosition(mPoints[0]) ;
  Vector2 v2 = ComputeGlobalPosition(mPoints[1]) ;
  Vector2 v3 = ComputeGlobalPosition(mPoints[2]) ;

  raylib::DrawTriangle(v1, v2, v3, mColor);
}


Triangulation::Triangulation(const std::vector<Coordinates2D>& points, const Color& color)
    : mPoints(points), mColor(color) {
    if (points.size() < 3) {
        throw std::invalid_argument("A polygon must have at least 3 points for triangulation.");
    }
    PerformTriangulation();
}

std::vector<Triangle> Triangulation::GetTriangles() {
    return mTriangles;
}

void Triangulation::PerformTriangulation() {
    // Copy points to work on a mutable list
    std::vector<Coordinates2D> polygon = mPoints;

    while (polygon.size() > 3) {
        bool earFound = false;

        for (size_t i = 0; i < polygon.size(); ++i) {
            if (IsEar(i)) {
                // Add the ear triangle to the result
                size_t prev = (i == 0) ? polygon.size() - 1 : i - 1;
                size_t next = (i == polygon.size() - 1) ? 0 : i + 1;

                Triangle triangle = {polygon[prev], polygon[i], polygon[next], mColor};
                mTriangles.push_back(triangle);

                // Remove the ear point
                polygon.erase(polygon.begin() + i);
                earFound = true;
                break;
            }
        }

        if (!earFound) {
            throw std::runtime_error("Failed to triangulate the polygon (likely non-simple polygon).");
        }
    }

    // Add the final triangle
    if (polygon.size() == 3) {
        mTriangles.push_back({polygon[0], polygon[1], polygon[2], mColor});
    }
}

bool Triangulation::IsPointInTriangle(const Coordinates2D& point, const Coordinates2D& a, const Coordinates2D& b, const Coordinates2D& c) const {
    auto sign = [](const Coordinates2D& p1, const Coordinates2D& p2, const Coordinates2D& p3) {
        return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
    };

    double d1 = sign(point, a, b);
    double d2 = sign(point, b, c);
    double d3 = sign(point, c, a);

    bool hasNegative = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool hasPositive = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(hasNegative && hasPositive);
}

bool Triangulation::IsEar(size_t i) const {
    size_t prev = (i == 0) ? mPoints.size() - 1 : i - 1;
    size_t next = (i == mPoints.size() - 1) ? 0 : i + 1;

    const Coordinates2D& a = mPoints[prev];
    const Coordinates2D& b = mPoints[i];
    const Coordinates2D& c = mPoints[next];

    // Check if the triangle is convex
    double crossProduct = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (crossProduct <= 0) {
        return false; // Not convex
    }

    // Check if any other point lies inside the triangle
    for (size_t j = 0; j < mPoints.size(); ++j) {
        if (j == prev || j == i || j == next) {
            continue; // Skip the triangle vertices
        }

        if (IsPointInTriangle(mPoints[j], a, b, c)) {
            return false; // Another point is inside the triangle
        }
    }

    return true;
}
}  // namespace graphics
