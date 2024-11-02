#include "fontLoaderFactory.hpp"
#include <string>

#include <memory>  // For std::unique_ptr

static std::unique_ptr<IFontLoader> CreateFontLoader(const std::string& type) {
    if (type == "raylib") {
        return std::make_unique<RaylibFontLoader>();  // Create and return a unique pointer to RaylibFontLoader
    }
    // Add other font loaders here in the future
    
    return nullptr;  // Return nullptr if no valid type is provided
}

