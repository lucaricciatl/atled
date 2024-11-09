#include "Triangle.hpp"

namespace graphics {

Triangle::Triangle(const Coordinates2D& point1, const Coordinates2D& point2, const Coordinates2D& point3, const Color& color)
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

Color Triangle::GetColor() const {
  return mColor;
}

void Triangle::Draw() {
  Vector2 v1 = { static_cast<float>(mPoints[0].x), static_cast<float>(mPoints[0].y) };
  Vector2 v2 = { static_cast<float>(mPoints[1].x), static_cast<float>(mPoints[1].y) };
  Vector2 v3 = { static_cast<float>(mPoints[2].x), static_cast<float>(mPoints[2].y) };

  DrawTriangle(v1, v2, v3, mColor);
}

}  // namespace graphics
