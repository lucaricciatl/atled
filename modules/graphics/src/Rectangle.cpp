#include "Rectangle.hpp"
#include <iostream>
#include <cassert> 


namespace graphics {

Rectangle::Rectangle(const Coordinates2D& aUpperLeft,
                     const Coordinates2D& aBottomRight) {
  mUpperLeft = aUpperLeft;
  mBottomRight = aBottomRight;
}

void Rectangle::SetUpperLeft(const Coordinates2D& aUpperLeft) {
  mUpperLeft = aUpperLeft;
}

void Rectangle::SetBottomRight(const Coordinates2D& aBottomRight) {
  mBottomRight = aBottomRight;
}
void Rectangle::SetColor(const ::Color& color) { mColor = color; }
void Rectangle::SetRotation(double rotation) { mRotation = rotation; }
Coordinates2D Rectangle::GetUpperLeft() const { return mUpperLeft; }

Coordinates2D Rectangle::GetBottomRight() const { return mBottomRight; }
::Color Rectangle::GetColor() const { return mColor; }
double Rectangle::GetRotation() const { return mRotation; }
void Rectangle::Draw() {
  float width = mBottomRight.x - mUpperLeft.x;
  float height = mBottomRight.y - mUpperLeft.y;

  // Ensure the width and height are positive
  if (width < 0 || height < 0) {
    // Handle invalid rectangle dimensions (maybe a warning or adjusting to 0)
    return;
  }

  RectangleStruct rect = {mUpperLeft.x, mUpperLeft.y, width, height};

  Vector2 origin = {(rect.width / 2), (rect.height / 2)};

  DrawRectanglePro(rect, origin, mRotation, mColor);
}

}  // namespace graphics