#ifndef RAYLIBTEXTDRAWER_HPP
#define RAYLIBTEXTDRAWER_HPP

#include "ITextDrawer.hpp"
#include "raylib.hpp" // Raylib includes
#include "Color.hpp"

namespace graphics
{

    // Concrete class that implements TextDrawer using Raylib
    class RaylibTextDrawer : public ITextDrawer
    {
    public:
        ~RaylibTextDrawer();
        // Implement DrawFPS using Raylib's DrawFPS function
        void DrawFPS(int posX, int posY) override;

        // Implement DrawText using Raylib's DrawText function
        void DrawText(const char *text, int posX, int posY, int fontSize,
                      graphics::Color color) override;

        // Implement DrawTextEx using Raylib's DrawTextEx function
        void DrawTextEx(raylib::Font font, const char *text, raylib::Vector2 position, float fontSize,
                        float spacing, graphics::Color tint) override;

        // Implement DrawTextPro using Raylib's DrawTextPro function
        void DrawTextPro(raylib::Font font, const char *text, raylib::Vector2 position,
                         raylib::Vector2 origin, float rotation, float fontSize,
                         float spacing, graphics::Color tint) override;

        // Implement DrawTextCodepoint using Raylib's DrawTextCodepoint function
        void DrawTextCodepoint(raylib::Font font, int codepoint, raylib::Vector2 position,
                               float fontSize, graphics::Color tint) override;

        // Implement DrawTextCodepoints using Raylib's DrawTextCodepoints function
        void DrawTextCodepoints(raylib::Font font, const int *codepoints, int codepointCount,
                                raylib::Vector2 position, float fontSize, float spacing,
                                graphics::Color tint) override;
    };

}

#endif // RAYLIBTEXTDRAWER_HPP
