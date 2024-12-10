#include <unordered_map>
#include <Color.hpp>
#include <string>

namespace graphics{
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