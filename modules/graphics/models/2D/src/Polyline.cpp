#include "Polyline.hpp"

namespace graphics {

Polyline::Polyline(const std::vector<Coordinates2D>& points, double thickness, const Color& color)
    : mPoints(points), mThickness(thickness), mColor(color) {}

void Polyline::SetPoints(const std::vector<Coordinates2D>& points) {
  mPoints = points;
}

const std::vector<Coordinates2D>& Polyline::GetPoints() const {
  return mPoints;
}

void Polyline::SetThickness(double thickness) {
  mThickness = thickness;
}

double Polyline::GetThickness() const {
  return mThickness;
}

void Polyline::Draw() {
  // Draw each segment between consecutive points
  for (size_t i = 0; i < mPoints.size() - 1; ++i) {
    Vector2 startPos = { static_cast<float>(mPoints[i].x), static_cast<float>(mPoints[i].y) };
    Vector2 endPos = { static_cast<float>(mPoints[i + 1].x), static_cast<float>(mPoints[i + 1].y) };
    DrawLineEx(startPos, endPos, static_cast<float>(mThickness), mColor);
  }
}

}  // namespace graphics