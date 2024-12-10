#include "Color.hpp"
#include <unordered_map>

namespace graphics {

Color::Color() : red(0.0f), green(0.0f), blue(0.0f), alpha(1.0f) {}

Color::Color(float r, float g, float b, float a)
    : red(clamp(r, 0.0f, 1.0f)), green(clamp(g, 0.0f, 1.0f)), blue(clamp(b, 0.0f, 1.0f)), alpha(clamp(a, 0.0f, 1.0f)) {

}

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


// Global static map for color palette
static std::unordered_map<std::string, Color> colorMap;

// Function to initialize the color palette
void initializeColorPalette() {
    if (!colorMap.empty()) return; // Avoid reinitialization

    colorMap = {
        {"White", Color(1.0f, 1.0f, 1.0f, 1.0f)},
        {"Black", Color(0.0f, 0.0f, 0.0f, 1.0f)},
        {"Soft Pink", Color(1.0f, 0.7f, 0.73f, 0.8f)},
        {"Peach", Color(1.0f, 0.87f, 0.73f, 0.8f)},
        {"Light Yellow", Color(1.0f, 1.0f, 0.73f, 0.8f)},
        {"Mint Green", Color(0.73f, 1.0f, 0.79f, 0.8f)},
        {"Sky Blue", Color(0.73f, 0.88f, 1.0f, 0.8f)},
        {"Lavender", Color(0.73f, 0.73f, 1.0f, 0.8f)},
        {"Lilac", Color(0.87f, 0.73f, 1.0f, 0.8f)},
        {"Blush Pink", Color(1.0f, 0.73f, 0.96f, 0.8f)},
        {"Rose Pink", Color(1.0f, 0.73f, 0.83f, 0.8f)},
        {"Coral", Color(1.0f, 0.8f, 0.6f, 0.8f)},
        {"Soft Blue", Color(0.6f, 0.8f, 1.0f, 0.8f)},
        {"Aqua", Color(0.6f, 1.0f, 0.8f, 0.8f)},
        {"Soft Purple", Color(0.8f, 0.6f, 1.0f, 0.8f)},
        {"Lime Green", Color(0.8f, 1.0f, 0.6f, 0.8f)},
        {"Bubblegum Pink", Color(1.0f, 0.6f, 0.8f, 0.8f)},
        {"Golden Peach", Color(1.0f, 0.8f, 0.6f, 0.8f)},
        {"Cream Rose", Color(0.94f, 0.78f, 0.82f, 0.8f)},
        {"Soft Mint", Color(0.78f, 0.94f, 0.82f, 0.8f)},
        {"Pastel Green", Color(0.82f, 0.94f, 0.78f, 0.8f)},
        {"Pale Violet", Color(0.86f, 0.82f, 0.94f, 0.8f)},
    };
    }

// Non-member function to get a color by name
const Color& getColor(const std::string& name) {
    // Ensure the palette is initialized
    initializeColorPalette();

    auto it = colorMap.find(name);
    if (it != colorMap.end()) {
        return it->second;
    }
}


// Check if a color exists
bool hasColor(const std::string& name) {
    initializeColorPalette();
    return colorMap.find(name) != colorMap.end();
}


}