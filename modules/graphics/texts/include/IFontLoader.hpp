#ifndef FONTLOADER_HPP
#define FONTLOADER_HPP

#include "raylib.h"

namespace graphics {

// Abstract class for font loading and unloading operations
class IFontLoader {
public:
    // Virtual destructor for proper cleanup of derived classes
    virtual ~IFontLoader() = default;

    // Pure virtual function to get the default font
    virtual Font GetFontDefault() const = 0;

    // Pure virtual function to load a font from file
    virtual Font LoadFont(const char* fileName) const = 0;

    // Pure virtual function to load a font from file with extended parameters
    virtual Font LoadFontEx(const char* fileName, int fontSize, int* codepoints, int codepointCount) const = 0;

    // Pure virtual function to load a font from an image
    virtual Font LoadFontFromImage(Image image, Color key, int firstChar) const = 0;

    // Pure virtual function to load a font from memory
    virtual Font LoadFontFromMemory(const char* fileType, const unsigned char* fileData, int dataSize, int fontSize, int* codepoints, int codepointCount) const = 0;

    // Pure virtual function to check if a font is ready
    virtual bool IsFontReady(Font font) const = 0;

    // Pure virtual function to load font data for further use
    virtual GlyphInfo* LoadFontData(const unsigned char* fileData, int dataSize, int fontSize, int* codepoints, int codepointCount, int type) const = 0;

    // Pure virtual function to generate an image font atlas using glyph information
    virtual Image GenImageFontAtlas(const GlyphInfo* glyphs, Rectangle** glyphRecs, int glyphCount, int fontSize, int padding, int packMethod) const = 0;

    // Pure virtual function to unload font glyph information
    virtual void UnloadFontData(GlyphInfo* glyphs, int glyphCount) const = 0;

    // Pure virtual function to unload a font from GPU memory
    virtual void UnloadFont(Font font) const = 0;

    // Pure virtual function to export a font as code
    virtual bool ExportFontAsCode(Font font, const char* fileName) const = 0;
};

}
#endif // FONTLOADER_HPP
