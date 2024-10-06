#include "Shape.hpp"
#include <cmath>
#include <numbers>

namespace graphics {

// Translate only in X direction by aX
void Shape::TranslateX(float aX) {
    Translate(aX, 0.0f);
}

// Translate only in Y direction by aY
void Shape::TranslateY(float aY) {
    Translate(0.0f, aY);
}

// Rotate the shape by a given angle (in degrees)
void Shape::Rotate(float aAngle) {
    float radians = aAngle * std::numbers::pi_v<float> / 180.0f;
    
    const float cosAngle = std::cos(radians);
    const float sinAngle = std::sin(radians);

    // Rotate each point around the origin (0,0)
    for (auto& point : mBuffer.GetBuffer()) {
        const float newX = point.x * cosAngle - point.y * sinAngle;
        const float newY = point.x * sinAngle + point.y * cosAngle;
        point.x = newX;
        point.y = newY;
    }

    mBuffer.LoadBuffer();
}

// Translate the shape by dx and dy
void Shape::Translate(float aDx, float aDy) {
    for (auto& point : mBuffer.GetBuffer()) {
        point.x += aDx;
        point.y += aDy;
    }

    mBuffer.LoadBuffer();
}

void Shape::Draw() {
    mBuffer.DrawBuffer();
}

} // namespace graphics
