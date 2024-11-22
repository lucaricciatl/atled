#include "Line.hpp"

namespace graphics {

Line::Line(Coordinates2D aStart, Coordinates2D aEnd, double thickness,
           const Color& aColor)
    : start(aStart), end(aEnd), mThickness(thickness) {}

void Line::SetStartPoint(const Coordinates2D& aStart) { start = aStart; }

void Line::SetEndPoint(const Coordinates2D& aEnd) { end = aEnd; }

Coordinates2D Line::GetStartPoint() const { return start; }

Coordinates2D Line::GetEndPoint() const { return end; }

void Line::SetThickness(double thickness) { mThickness = thickness; }


void Line::Draw() {
  Vector2 startPos = {static_cast<float>(start.x), static_cast<float>(start.y)};
  Vector2 endPos = {static_cast<float>(end.x), static_cast<float>(end.y)};
   raylib::DrawLineEx(startPos, endPos, static_cast<float>(mThickness), mColor);
}

}  // namespace graphics