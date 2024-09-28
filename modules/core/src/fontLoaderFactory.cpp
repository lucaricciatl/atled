#include "fontLoaderFactory.hpp"
#include <string>

static IFontLoader* CreateFontLoader(const std::string& type) {
    if (type == "raylib") {
        return new RaylibFontLoader();
    }
    // Add other font loaders here in the future
    return nullptr;
}
