#include "Shape.hpp"
#include <PolygonBuffer2D.hpp>
#include <cmath>      // For sin and cos functions
#include <numbers>    // For std::numbers::pi (C++20)

namespace graphics {

// Set the color for the shape
  void Shape::SetColor(Color aColor) {
    mColor = aColor;
  }

  // Translate only in X direction by aX
  void Shape::TranslateX(float aX) {
    Translate(aX, 0.0f);
  }

  // Translate only in Y direction by aY
  void Shape::TranslateY(float aY) {
    Translate(0.0f, aY);
  }

// Rotate the shape by a given angle (in degrees)
void Shape::Rotate(const float aAngle) {
    // Convert the angle to radians
    float radians = aAngle * std::numbers::pi / 180.0f;
    
    // Cosine and sine of the angle
    float cosAngle = std::cos(radians);
    float sinAngle = std::sin(radians);

    // Rotate each point around the origin (0,0)
    for (auto& point : mBuffer.GetBuffer()) {
        float newX = point.x * cosAngle - point.y * sinAngle;
        float newY = point.x * sinAngle + point.y * cosAngle;
        point.x = newX;
        point.y = newY;
    }

    // Optionally reload the buffer into the drawing object
    mBuffer.LoadBuffer();
}
// Translate the shape by dx and dy
void Shape::Translate(float dx, float dy) {
    // Iterate over each point in the buffer and apply the translation
    for (auto& point : mBuffer.GetBuffer()) {
        point.x += dx;
        point.y += dy;
    }

    // Optionally reload the buffer into the drawing object
    mBuffer.LoadBuffer();
}
}