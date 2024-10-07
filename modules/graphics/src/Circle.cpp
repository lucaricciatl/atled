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

void Circle::SetColor(Color aColor) { mColor = aColor; }

void Circle::SetRadius(const float& aRadius) { mRadius = aRadius; }

void Circle::Draw(){
  DrawCircleV(::Vector2(mCenter.x, mCenter.y),mRadius,mColor);
}
}