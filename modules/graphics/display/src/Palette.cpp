#include <unordered_map>
#include <string>
#include "Color.hpp"  // Use quotes for local header
#include <cassert>

namespace graphics {

    // Global static map for color palette
    static std::unordered_map<std::string, Color> colorMap;

    // Function to initialize the color palette
    void initializeColorPalette() {
        if (!colorMap.empty()) return; // Avoid reinitialization

        colorMap = {
            // Base Colors
            {"White", Color(1.0f, 1.0f, 1.0f, 1.0f)},
            {"Black", Color(0.0f, 0.0f, 0.0f, 1.0f)},

            // Soft and Pastel Colors
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

            // Vibrant Colors
            {"Bright Red", Color(1.0f, 0.0f, 0.0f, 1.0f)},
            {"Vivid Orange", Color(1.0f, 0.5f, 0.0f, 1.0f)},
            {"Sunflower Yellow", Color(1.0f, 0.9f, 0.0f, 1.0f)},
            {"Emerald Green", Color(0.0f, 0.8f, 0.3f, 1.0f)},
            {"Ocean Blue", Color(0.0f, 0.5f, 1.0f, 1.0f)},
            {"Royal Purple", Color(0.5f, 0.0f, 1.0f, 1.0f)},
            {"Hot Pink", Color(1.0f, 0.0f, 0.5f, 1.0f)},

            // Neutral Colors
            {"Light Gray", Color(0.8f, 0.8f, 0.8f, 1.0f)},
            {"Medium Gray", Color(0.5f, 0.5f, 0.5f, 1.0f)},
            {"Dark Gray", Color(0.2f, 0.2f, 0.2f, 1.0f)},
            {"Beige", Color(0.96f, 0.96f, 0.86f, 1.0f)},
            {"Sand", Color(0.87f, 0.79f, 0.69f, 1.0f)},
            {"Charcoal", Color(0.1f, 0.1f, 0.1f, 1.0f)},

            // Additional Muted Tones
            {"Moss Green", Color(0.6f, 0.8f, 0.6f, 1.0f)},
            {"Muted Blue", Color(0.6f, 0.7f, 0.8f, 1.0f)},
            {"Dusty Rose", Color(0.8f, 0.6f, 0.6f, 1.0f)},
            {"Slate Blue", Color(0.4f, 0.5f, 0.6f, 1.0f)},
            {"Earth Brown", Color(0.5f, 0.4f, 0.3f, 1.0f)},
            {"Olive", Color(0.5f, 0.5f, 0.3f, 1.0f)},
            {"Muted Purple", Color(0.6f, 0.4f, 0.6f, 1.0f)},
        };
    }

Color getColor(const std::string& name) {
        // Ensure the palette is initialized
        initializeColorPalette();
        auto it = colorMap.find(name);

        // Use assert to catch issues during development
        assert(it != colorMap.end() && "Color not found in the palette!");

        if (it != colorMap.end()) {
            return it->second;
        } else {
            // If the color is not found (e.g., in release mode where assert is ignored),
            // default to White.
            return colorMap["White"];
        }
    }

    // Check if a color exists
    bool hasColor(const std::string& name) {
        initializeColorPalette();
        return colorMap.find(name) != colorMap.end();
    }

} // namespace graphics
