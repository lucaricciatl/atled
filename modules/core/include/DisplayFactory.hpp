#ifndef DISPLAY_FACTORY_HPP
#define DISPLAY_FACTORY_HPP

#include <memory>
#include "IDisplay.hpp"
#include "RaylibDisplay.hpp"  // Include RaylibDisplay for Raylib implementation

// Enum to represent the different types of display backends
enum class DisplayType {
    Raylib,
    // Add other types as needed (e.g., SDL, GLFW, etc.)
};

class DisplayFactory {
public:
    // Factory method to create displays based on the DisplayType
    static std::unique_ptr<IDisplay> CreateDisplay(DisplayType type);
};

#endif // DISPLAY_FACTORY_HPP
