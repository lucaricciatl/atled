// graphics.h
#pragma once

#include <unordered_map>
#include <string>
#include <Color.hpp>

namespace graphics {
    // Initializes the color palette with predefined colors
    void initializeColorPalette();

    // Retrieves a color by name. Throws std::runtime_error if not found.
    const Color& getColor(const std::string& name);

    // Checks if a color exists in the palette
    bool hasColor(const std::string& name);
}