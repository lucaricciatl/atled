#include "DisplayFactory.hpp"

std::unique_ptr<IDisplay> DisplayFactory::CreateDisplay(DisplayType type) {
    switch (type) {
        case DisplayType::Raylib:
            return std::make_unique<RaylibDisplay>();  // Return Raylib display implementation
        // Add more cases here for different types of display backends (SDL, GLFW, etc.)
        default:
            return nullptr;
    }
}
