#ifndef IMATERIAL_HPP
#define IMATERIAL_HPP

#include <string>
#include <memory>

namespace resources {

class ITexture;

class IMaterial {
public:
    virtual ~IMaterial() = default;

    // Load material data from a file
    virtual bool LoadFromFile(const std::string& fileName) = 0;

    // Unload material data
    virtual void Unload() = 0;

    // Check if the material is loaded
    virtual bool IsLoaded() const = 0;

    // Set and get textures
    virtual void SetTexture(const std::shared_ptr<ITexture>& texture) = 0;
    virtual std::shared_ptr<ITexture> GetTexture() const = 0;

    // Set and get shader properties, colors, etc.
    // virtual void SetShader(const IShader& shader) = 0;
    // virtual const IShader& GetShader() const = 0;

    // Other material-related methods
};

}
#endif // IMATERIAL_HPP
