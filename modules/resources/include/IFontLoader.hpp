#ifndef FONTLOADER_HPP
#define FONTLOADER_HPP

#include "raylib.hpp"

namespace resources {

// Abstract class for font loading and unloading operations
class IFontLoader {
public:
    // Virtual destructor for proper cleanup of derived classes
    virtual ~IFontLoader() = default;

    // Pure virtual function to get the default font
    virtual raylib::Font GetFontDefault() const = 0;

    // Pure virtual function to load a font from file
    virtual raylib::Font LoadFont(const char* fileName) const = 0;

    // Pure virtual function to load a font from file with extended parameters
    virtual raylib::Font LoadFontEx(const char* fileName, int fontSize, int* codepoints, int codepointCount) const = 0;

    // Pure virtual function to load a font from an image
    virtual raylib::Font LoadFontFromImage(raylib::Image image, raylib::Color key, int firstChar) const = 0;

    // Pure virtual function to load a font from memory
    virtual raylib::Font LoadFontFromMemory(const char* fileType, const unsigned char* fileData, int dataSize, int fontSize, int* codepoints, int codepointCount) const = 0;

    // Pure virtual function to check if a font is ready
    virtual bool IsFontReady(raylib::Font font) const = 0;

    // Pure virtual function to load font data for further use
    virtual raylib::GlyphInfo* LoadFontData(const unsigned char* fileData, int dataSize, int fontSize, int* codepoints, int codepointCount, int type) const = 0;

    // Pure virtual function to generate an image font atlas using glyph information
    virtual raylib::Image GenImageFontAtlas(const raylib::GlyphInfo* glyphs, raylib::Rectangle** glyphRecs, int glyphCount, int fontSize, int padding, int packMethod) const = 0;

    // Pure virtual function to unload font glyph information
    virtual void UnloadFontData(raylib::GlyphInfo* glyphs, int glyphCount) const = 0;

    // Pure virtual function to unload a font from GPU memory
    virtual void UnloadFont(raylib::Font font) const = 0;

    // Pure virtual function to export a font as code
    virtual bool ExportFontAsCode(raylib::Font font, const char* fileName) const = 0;
};

}
#endif // FONTLOADER_HPP
