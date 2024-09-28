#ifndef FONTLOADERFACTORY_HPP
#define FONTLOADERFACTORY_HPP

#include "IFontLoader.hpp"
#include "RaylibFontLoader.hpp"

// Factory class to create instances of FontLoader
class FontLoaderFactory {
public:
    // Static method to create and return a FontLoader instance
    static IFontLoader* CreateFontLoader() {
        // Currently, it creates a RaylibFontLoader
        return new RaylibFontLoader();
    }
};

#endif // FONTLOADERFACTORY_HPP
