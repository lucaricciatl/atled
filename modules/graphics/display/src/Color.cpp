#include "Color.hpp"

namespace graphics {

Color::Color() : red(0.0f), green(0.0f), blue(0.0f), alpha(1.0f) {}

Color::Color(float r, float g, float b, float a)
    : red(clamp(r, 0.0f, 1.0f)), green(clamp(g, 0.0f, 1.0f)), blue(clamp(b, 0.0f, 1.0f)), alpha(clamp(a, 0.0f, 1.0f)) {}

float Color::getRed() const {
    return red;
}

float Color::getGreen() const {
    return green;
}

float Color::getBlue() const {
    return blue;
}

float Color::getAlpha() const {
    return alpha;
}

void Color::setRed(float r) {
    red = clamp(r, 0.0f, 1.0f);
}

void Color::setGreen(float g) {
    green = clamp(g, 0.0f, 1.0f);
}

void Color::setBlue(float b) {
    blue = clamp(b, 0.0f, 1.0f);
}

void Color::setAlpha(float a) {
    alpha = clamp(a, 0.0f, 1.0f);
}

std::string Color::toHex() const {
    auto toHexComponent = [](float component) {
        int value = static_cast<int>(component * 255);
        std::ostringstream oss;
        oss << std::hex << std::setw(2) << std::setfill('0') << value;
        return oss.str();
    };
    return "#" + toHexComponent(red) + toHexComponent(green) + toHexComponent(blue);
}

void Color::fromHex(const std::string& hex) {
    if (hex.size() == 7 && hex[0] == '#') {
        red = std::stoi(hex.substr(1, 2), nullptr, 16) / 255.0f;
        green = std::stoi(hex.substr(3, 2), nullptr, 16) / 255.0f;
        blue = std::stoi(hex.substr(5, 2), nullptr, 16) / 255.0f;
        alpha = 1.0f;
    }
}

bool Color::operator==(const Color& other) const {
    return red == other.red && green == other.green && blue == other.blue && alpha == other.alpha;
}

bool Color::operator!=(const Color& other) const {
    return !(*this == other);
}

float Color::clamp(float value, float min, float max) const {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

// Get RGB values as 0-255
void Color::getRGB255(int& r, int& g, int& b, int& a) const {
    r = static_cast<int>(red * 255);
    g = static_cast<int>(green * 255);
    b = static_cast<int>(blue * 255);
    a = static_cast<int>(alpha * 255);
}

}