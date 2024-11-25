#ifndef FONTLOADERFACTORY_HPP
#define FONTLOADERFACTORY_HPP

#include "IFontLoader.hpp"
#include "RaylibFontLoader.hpp"
#include <memory>  // For std::unique_ptr
#include <string>

namespace graphics{
// Factory class to create instances of FontLoader
class FontLoaderFactory {
public:
    // Static method to create and return a FontLoader instance


static std::unique_ptr<IFontLoader> CreateFontLoader(const std::string& type);

};

}
#endif // FONTLOADERFACTORY_HPP
