#include "RaylibFontLoader.hpp"

namespace graphics {

// Implement GetFontDefault using Raylib's GetFontDefault function
raylib::Font RaylibFontLoader::GetFontDefault() const {
    return raylib::GetFontDefault();
}

// Implement LoadFont using Raylib's LoadFont function
raylib::Font RaylibFontLoader::LoadFont(const char* fileName) const {
    return raylib::LoadFont(fileName);
}

// Implement LoadFontEx using Raylib's LoadFontEx function
raylib::Font RaylibFontLoader::LoadFontEx(const char* fileName, int fontSize, int* codepoints, int codepointCount) const {
    return raylib::LoadFontEx(fileName, fontSize, codepoints, codepointCount);
}

// Implement LoadFontFromImage using Raylib's LoadFontFromImage function
raylib::Font RaylibFontLoader::LoadFontFromImage(raylib::Image image, raylib::Color key, int firstChar) const {
    return raylib::LoadFontFromImage(image, key, firstChar);
}

// Implement LoadFontFromMemory using Raylib's LoadFontFromMemory function
raylib::Font RaylibFontLoader::LoadFontFromMemory(const char* fileType, const unsigned char* fileData, int dataSize, int fontSize, int* codepoints, int codepointCount) const {
    return raylib::LoadFontFromMemory(fileType, fileData, dataSize, fontSize, codepoints, codepointCount);
}

// Implement IsFontReady using Raylib's IsFontReady function
bool RaylibFontLoader::IsFontReady(raylib::Font font) const {
    return raylib::IsFontReady(font);
}

// Implement LoadFontData using Raylib's LoadFontData function
raylib::GlyphInfo* RaylibFontLoader::LoadFontData(const unsigned char* fileData, int dataSize, int fontSize, int* codepoints, int codepointCount, int type) const {
    return raylib::LoadFontData(fileData, dataSize, fontSize, codepoints, codepointCount, type);
}

// Implement GenImageFontAtlas using Raylib's GenImageFontAtlas function
raylib::Image RaylibFontLoader::GenImageFontAtlas(const raylib::GlyphInfo* glyphs, raylib::Rectangle** glyphRecs, int glyphCount, int fontSize, int padding, int packMethod) const {
    return raylib::GenImageFontAtlas(glyphs, glyphRecs, glyphCount, fontSize, padding, packMethod);
}

// Implement UnloadFontData using Raylib's UnloadFontData function
void RaylibFontLoader::UnloadFontData(raylib::GlyphInfo* glyphs, int glyphCount) const {
    raylib::UnloadFontData(glyphs, glyphCount);
}

// Implement UnloadFont using Raylib's UnloadFont function
void RaylibFontLoader::UnloadFont(raylib::Font font) const {
    raylib::UnloadFont(font);
}

// Implement ExportFontAsCode using Raylib's ExportFontAsCode function
bool RaylibFontLoader::ExportFontAsCode(raylib::Font font, const char* fileName) const {
    return raylib::ExportFontAsCode(font, fileName);
}

}