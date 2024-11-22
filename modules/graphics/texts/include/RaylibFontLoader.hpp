#ifndef RAYLIBFONTLOADER_HPP
#define RAYLIBFONTLOADER_HPP

#include "IFontLoader.hpp"
#include "raylib.hpp"

namespace graphics {

// Concrete class implementing FontLoader using Raylib's font functions
class RaylibFontLoader : public IFontLoader {
public:
    // Implement GetFontDefault using Raylib's GetFontDefault function
    Font GetFontDefault() const override;

    // Implement LoadFont using Raylib's LoadFont function
    Font LoadFont(const char* fileName) const override;

    // Implement LoadFontEx using Raylib's LoadFontEx function
    Font LoadFontEx(const char* fileName, int fontSize, int* codepoints, int codepointCount) const override;

    // Implement LoadFontFromImage using Raylib's LoadFontFromImage function
    Font LoadFontFromImage(Image image, Color key, int firstChar) const override;

    // Implement LoadFontFromMemory using Raylib's LoadFontFromMemory function
    Font LoadFontFromMemory(const char* fileType, const unsigned char* fileData, int dataSize, int fontSize, int* codepoints, int codepointCount) const override;

    // Implement IsFontReady using Raylib's IsFontReady function
    bool IsFontReady(Font font) const override;

    // Implement LoadFontData using Raylib's LoadFontData function
    GlyphInfo* LoadFontData(const unsigned char* fileData, int dataSize, int fontSize, int* codepoints, int codepointCount, int type) const override;

    // Implement GenImageFontAtlas using Raylib's GenImageFontAtlas function
    Image GenImageFontAtlas(const GlyphInfo* glyphs, Rectangle** glyphRecs, int glyphCount, int fontSize, int padding, int packMethod) const override;

    // Implement UnloadFontData using Raylib's UnloadFontData function
    void UnloadFontData(GlyphInfo* glyphs, int glyphCount) const override;

    // Implement UnloadFont using Raylib's UnloadFont function
    void UnloadFont(Font font) const override;

    // Implement ExportFontAsCode using Raylib's ExportFontAsCode function
    bool ExportFontAsCode(Font font, const char* fileName) const override;
};

}
#endif // RAYLIBFONTLOADER_HPP
