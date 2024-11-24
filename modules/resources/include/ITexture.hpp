#ifndef ITEXTURE_HPP
#define ITEXTURE_HPP

#include <string>

namespace resources {

class ITexture {
public:
    virtual ~ITexture() = default;

    // Load texture data from a file
    virtual bool LoadFromFile(const std::string& fileName) = 0;

    // Unload texture data
    virtual void Unload() = 0;

    // Check if the texture is loaded
    virtual bool IsLoaded() const = 0;

    // Get texture dimensions
    virtual int GetWidth() const = 0;
    virtual int GetHeight() const = 0;

    // Other texture-related methods
};

#endif // ITEXTURE_HPP
