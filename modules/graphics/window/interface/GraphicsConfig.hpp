
#pragma once
#include "Raylib.hpp"
#include <vector>
namespace graphics{

struct GraphicsConfig {

    int width;
    int height;
    bool fullscreen;
    bool vsync;
    int antialiasing;


    // Static default flag
    const std::vector<raylib::ConfigFlags> defaultFlags = {
        raylib::ConfigFlags::FLAG_VSYNC_HINT,
        raylib::ConfigFlags::FLAG_MSAA_4X_HINT,
        raylib::ConfigFlags::FLAG_WINDOW_HIGHDPI,
        raylib::ConfigFlags::FLAG_WINDOW_RESIZABLE
    };

    // Vector to store window configuration flags
    std::vector<raylib::ConfigFlags> WindowConfig;

    GraphicsConfig() {
        for (const raylib::ConfigFlags& config : defaultFlags) {
            WindowConfig.push_back(config);  // Initialize with the default flag
        }
    }

    // Constructor to allow custom flags
    GraphicsConfig(std::vector<raylib::ConfigFlags> customFlags) : WindowConfig(customFlags) {}
};

}