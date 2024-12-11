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
    Vector2 startPos = ComputeGlobalPosition(mPoints[0]);
    Vector2 endPos = ComputeGlobalPosition(mPoints[1]);
     raylib::DrawLineEx(startPos, endPos, static_cast<float>(mThickness), graphics::toRaylibColor(mColor));
  }
}

}  // namespace graphics