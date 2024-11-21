
#pragma once
#include "Raylib.h"

namespace graphics{

struct GraphicsConfig {
    // Static default flag
    static constexpr ConfigFlags defaultFlags = FLAG_VSYNC_HINT;

    // Vector to store window configuration flags
    std::vector<ConfigFlags> WindowConfig;

    // Constructor with default flags
    GraphicsConfig() {
        WindowConfig.push_back(defaultFlags);  // Initialize with the default flag
    }

    // Constructor to allow custom flags
    GraphicsConfig(std::vector<ConfigFlags> customFlags) : WindowConfig(customFlags) {}
};

}