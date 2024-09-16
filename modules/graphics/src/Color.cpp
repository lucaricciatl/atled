#include "Color.hpp"

namespace graphics {

//// Constructor
//Color::Color(unsigned char red, unsigned char green, unsigned char blue,
//             unsigned char alpha)
//    : r(red), g(green), b(blue), a(alpha) {}
//
//// Setters
//void Color::setRed(unsigned char red) { r = red; }
//void Color::setGreen(unsigned char green) { g = green; }
//void Color::setBlue(unsigned char blue) { b = blue; }
//void Color::setAlpha(unsigned char alpha) { a = alpha; }
//
//// Getters
//unsigned char Color::getRed() const { return r; }
//unsigned char Color::getGreen() const { return g; }
//unsigned char Color::getBlue() const { return b; }
//unsigned char Color::getAlpha() const { return a; }
//
//// Utility function: blend with another color
//Color Color::blend(const Color& other, float alpha) const {
//  unsigned char newR =
//      static_cast<unsigned char>(r * (1 - alpha) + other.r * alpha);
//  unsigned char newG =
//      static_cast<unsigned char>(g * (1 - alpha) + other.g * alpha);
//  unsigned char newB =
//      static_cast<unsigned char>(b * (1 - alpha) + other.b * alpha);
//  unsigned char newA =
//      static_cast<unsigned char>(a * (1 - alpha) + other.a * alpha);
//  return Color(newR, newG, newB, newA);
//}

}  // namespace graphics