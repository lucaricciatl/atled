// Texture.h

#ifndef TEXTURE_H
#define TEXTURE_H

#include "gfx.hpp"
#include <string>
namespace graphics {

class Texture2D {
public:
    // Constructors and Destructor
    Texture2D();
    Texture2D(const std::string& fileName);
    Texture2D(const Image& image);
    ~Texture2D();

    // Texture Loading Methods
    bool LoadFromFile(const std::string& fileName);
    bool LoadFromImage(const Image& image);
    bool LoadCubemap(const Image& image, int layout);
    bool LoadRenderTexture(int width, int height);

    // Texture Unloading Methods
    void Unload();
    void UnloadRenderTexture();

    // Texture Update Methods
    void Update(const void* pixels);
    void UpdateRec(Rectangle rec, const void* pixels);

    // Texture Status Check
    bool IsReady() const;

    // Getters
    Texture2D GetTexture() const;
    RenderTexture2D GetRenderTexture() const;

private:
    Texture texture;
    RenderTexture2D renderTexture;
    bool isTextureLoaded;
    bool isRenderTextureLoaded;
};

}
#endif // TEXTURE_H
