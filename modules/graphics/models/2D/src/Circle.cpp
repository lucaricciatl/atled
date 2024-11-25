#include "Circle.hpp"

#include <cassert>
#include <iostream>
#include <stdexcept>  // For std::invalid_argument


namespace graphics {

double Circle::GetRadius() const { return mRadius; }

Coordinates2D Circle::GetCenter() const { return mCenter; }

void Circle::SetCenter(const Coordinates2D& aCenter) {
  mCenter = aCenter;
}

void Circle::SetRadius(const float& aRadius) { mRadius = aRadius; }

void Circle::Draw(){
  Vector2 center = { mCenter.x, mCenter.y };
   raylib::DrawCircleV(center, mRadius, mColor);
}
}