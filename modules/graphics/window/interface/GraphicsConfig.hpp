
#pragma once
#include "Raylib.hpp"
#include <vector>
namespace graphics{

struct GraphicsConfig {
    // Static default flag
    const std::vector<ConfigFlags> defaultFlags = {
        FLAG_VSYNC_HINT,
        FLAG_MSAA_4X_HINT,
        FLAG_WINDOW_HIGHDPI,
        FLAG_WINDOW_RESIZABLE
    };
    // Vector to store window configuration flags
    std::vector<ConfigFlags> WindowConfig;

    GraphicsConfig() {
        for (const ConfigFlags& config : defaultFlags) {
            WindowConfig.push_back(config);  // Initialize with the default flag
        }
    }

    // Constructor to allow custom flags
    GraphicsConfig(std::vector<ConfigFlags> customFlags) : WindowConfig(customFlags) {}
};

}