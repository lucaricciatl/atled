// Texture.cpp

#include "Texture.h"

namespace graphics {

Texture2D::Texture2D()
    : isTextureLoaded(false), isRenderTextureLoaded(false) {
    texture = { 0 };
    renderTexture = { 0 };
}

Texture2D::Texture2D(const std::string& fileName)
    : Texture() {
    LoadFromFile(fileName);
}

Texture2D::Texture(const Image& image)
    : Texture() {
    LoadFromImage(image);
}

Texture2D::~Texture() {
    Unload();
    UnloadRenderTexture();
}

bool Texture2D::LoadFromFile(const std::string& fileName) {
    if (isTextureLoaded) {
        Unload();
    }
    texture = LoadTexture(fileName.c_str());
    isTextureLoaded = IsTextureReady(texture);
    return isTextureLoaded;
}

bool Texture2D::LoadFromImage(const Image& image) {
    if (isTextureLoaded) {
        Unload();
    }
    texture = LoadTextureFromImage(image);
    isTextureLoaded = IsTextureReady(texture);
    return isTextureLoaded;
}

bool Texture2D::LoadCubemap(const Image& image, int layout) {
    if (isTextureLoaded) {
        Unload();
    }
    texture = LoadTextureCubemap(image, layout);
    isTextureLoaded = IsTextureReady(texture);
    return isTextureLoaded;
}

bool Texture2D::LoadRenderTexture(int width, int height) {
    if (isRenderTextureLoaded) {
        UnloadRenderTexture();
    }
    renderTexture = LoadRenderTexture(width, height);
    isRenderTextureLoaded = IsRenderTextureReady(renderTexture);
    return isRenderTextureLoaded;
}

void Texture2D::Unload() {
    if (isTextureLoaded) {
        UnloadTexture(texture);
        isTextureLoaded = false;
    }
}

void Texture2D::UnloadRenderTexture() {
    if (isRenderTextureLoaded) {
        UnloadRenderTexture(renderTexture);
        isRenderTextureLoaded = false;
    }
}

void Texture2D::Update(const void* pixels) {
    if (isTextureLoaded) {
        UpdateTexture(texture, pixels);
    }
}

void Texture2D::UpdateRec(Rectangle rec, const void* pixels) {
    if (isTextureLoaded) {
        UpdateTextureRec(texture, rec, pixels);
    }
}

bool Texture2D::IsReady() const {
    return isTextureLoaded || isRenderTextureLoaded;
}

Texture2D Texture2D::GetTexture() const {
    return texture;
}

RenderTexture2D Texture2D::GetRenderTexture() const {
    return renderTexture;
}

}