#include "RaylibFontLoader.hpp"

namespace graphics {
// Implement GetFontDefault using Raylib's GetFontDefault function
Font RaylibFontLoader::GetFontDefault() const {
    return ::GetFontDefault();
}

// Implement LoadFont using Raylib's LoadFont function
Font RaylibFontLoader::LoadFont(const char* fileName) const {
    return ::LoadFont(fileName);
}

// Implement LoadFontEx using Raylib's LoadFontEx function
Font RaylibFontLoader::LoadFontEx(const char* fileName, int fontSize, int* codepoints, int codepointCount) const {
    return ::LoadFontEx(fileName, fontSize, codepoints, codepointCount);
}

// Implement LoadFontFromImage using Raylib's LoadFontFromImage function
Font RaylibFontLoader::LoadFontFromImage(Image image, Color key, int firstChar) const {
    return ::LoadFontFromImage(image, key, firstChar);
}

// Implement LoadFontFromMemory using Raylib's LoadFontFromMemory function
Font RaylibFontLoader::LoadFontFromMemory(const char* fileType, const unsigned char* fileData, int dataSize, int fontSize, int* codepoints, int codepointCount) const {
    return ::LoadFontFromMemory(fileType, fileData, dataSize, fontSize, codepoints, codepointCount);
}

// Implement IsFontReady using Raylib's IsFontReady function
bool RaylibFontLoader::IsFontReady(Font font) const {
    return ::IsFontReady(font);
}

// Implement LoadFontData using Raylib's LoadFontData function
GlyphInfo* RaylibFontLoader::LoadFontData(const unsigned char* fileData, int dataSize, int fontSize, int* codepoints, int codepointCount, int type) const {
    return ::LoadFontData(fileData, dataSize, fontSize, codepoints, codepointCount, type);
}

// Implement GenImageFontAtlas using Raylib's GenImageFontAtlas function
Image RaylibFontLoader::GenImageFontAtlas(const GlyphInfo* glyphs, Rectangle** glyphRecs, int glyphCount, int fontSize, int padding, int packMethod) const {
    return ::GenImageFontAtlas(glyphs, glyphRecs, glyphCount, fontSize, padding, packMethod);
}

// Implement UnloadFontData using Raylib's UnloadFontData function
void RaylibFontLoader::UnloadFontData(GlyphInfo* glyphs, int glyphCount) const {
    ::UnloadFontData(glyphs, glyphCount);
}

// Implement UnloadFont using Raylib's UnloadFont function
void RaylibFontLoader::UnloadFont(Font font) const {
    ::UnloadFont(font);
}

// Implement ExportFontAsCode using Raylib's ExportFontAsCode function
bool RaylibFontLoader::ExportFontAsCode(Font font, const char* fileName) const {
    return ::ExportFontAsCode(font, fileName);
}

}