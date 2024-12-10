#include "Line.hpp"
#include "raylib.hpp"

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
   auto gStart = ComputeGlobalPosition(start);
   auto gEnd = ComputeGlobalPosition(end);
   //raylib::DrawLineEx(gStart, gEnd, static_cast<float>(mThickness), mColor);
}

}  // namespace graphics