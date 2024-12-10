#include "raylib.hpp"
#include "RaylibTextDrawer.hpp"

namespace graphics
{
    using namespace raylib;
    RaylibTextDrawer::~RaylibTextDrawer()
    {
        // Destructor implementation (if necessary)
    }
    // Implement the DrawFPS function
    void RaylibTextDrawer::DrawFPS(int posX, int posY)
    {
        raylib::DrawFPS(posX, posY); // Call Raylib's DrawFPS function
    }

    // Implement the DrawText function
    void RaylibTextDrawer::DrawText(const char *text, int posX, int posY, int fontSize, Color color)
    {
        raylib::DrawText(text, posX, posY, fontSize, color); // Call Raylib's DrawText function
    }

    // Implement the DrawTextEx function
    void RaylibTextDrawer::DrawTextEx(raylib::Font font, const char *text, raylib::Vector2 position, float fontSize, float spacing, Color tint)
    {
        raylib::DrawTextEx(font, text, position, fontSize, spacing, tint); // Call Raylib's DrawTextEx function
    }

    // Implement the DrawTextPro function
    void RaylibTextDrawer::DrawTextPro(raylib::Font font, const char *text, raylib::Vector2 position, raylib::Vector2 origin, float rotation, float fontSize, float spacing, Color tint)
    {
        raylib::DrawTextPro(font, text, position, origin, rotation, fontSize, spacing, tint); // Call Raylib's DrawTextPro function
    }

    // Implement the DrawTextCodepoint function
    void RaylibTextDrawer::DrawTextCodepoint(raylib::Font font, int codepoint, raylib::Vector2 position, float fontSize, Color tint)
    {
        raylib::DrawTextCodepoint(font, codepoint, position, fontSize, tint); // Call Raylib's DrawTextCodepoint function
    }

    // Implement the DrawTextCodepoints function
    void RaylibTextDrawer::DrawTextCodepoints(raylib::Font font, const int *codepoints, int codepointCount, raylib::Vector2 position, float fontSize, float spacing, Color tint)
    {
        raylib::DrawTextCodepoints(font, codepoints, codepointCount, position, fontSize, spacing, tint); // Call Raylib's DrawTextCodepoints function
    }

}