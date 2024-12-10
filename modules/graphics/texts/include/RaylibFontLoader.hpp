#ifndef RAYLIBFONTLOADER_HPP
#define RAYLIBFONTLOADER_HPP

#include "IFontLoader.hpp"
#include "raylib.hpp"

namespace graphics
{

    // Concrete class implementing FontLoader using Raylib's font functions

    class RaylibFontLoader : public IFontLoader
    {
    public:
        // Implement GetFontDefault using Raylib's GetFontDefault function
        raylib::Font GetFontDefault() const override;

        // Implement LoadFont using Raylib's LoadFont function
        raylib::Font LoadFont(const char *fileName) const override;

        // Implement LoadFontEx using Raylib's LoadFontEx function
        raylib::Font LoadFontEx(const char *fileName, int fontSize, int *codepoints, int codepointCount) const override;

        // Implement LoadFontFromImage using Raylib's LoadFontFromImage function
        raylib::Font LoadFontFromImage(raylib::Image image, Color key, int firstChar) const override;

        // Implement LoadFontFromMemory using Raylib's LoadFontFromMemory function
        raylib::Font LoadFontFromMemory(const char *fileType, const unsigned char *fileData, int dataSize, int fontSize, int *codepoints, int codepointCount) const override;

        // Implement IsFontReady using Raylib's IsFontReady function
        bool IsFontReady(raylib::Font font) const override;

        // Implement LoadFontData using Raylib's LoadFontData function
        raylib::GlyphInfo *LoadFontData(const unsigned char *fileData, int dataSize, int fontSize, int *codepoints, int codepointCount, int type) const override;

        // Implement GenImageFontAtlas using Raylib's GenImageFontAtlas function
        raylib::Image GenImageFontAtlas(const raylib::GlyphInfo *glyphs, raylib::Rectangle **glyphRecs, int glyphCount, int fontSize, int padding, int packMethod) const override;

        // Implement UnloadFontData using Raylib's UnloadFontData function
        void UnloadFontData(raylib::GlyphInfo *glyphs, int glyphCount) const override;

        // Implement UnloadFont using Raylib's UnloadFont function
        void UnloadFont(raylib::Font font) const override;

        // Implement ExportFontAsCode using Raylib's ExportFontAsCode function
        bool ExportFontAsCode(raylib::Font font, const char *fileName) const override;
    };

}
#endif // RAYLIBFONTLOADER_HPP
