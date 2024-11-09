#include "raylib.h"

#include "RaylibTextDrawer.hpp"

// Implement the DrawFPS function
void RaylibTextDrawer::DrawFPS(int posX, int posY) {
    ::DrawFPS(posX, posY);  // Call Raylib's DrawFPS function
}

// Implement the DrawText function
void RaylibTextDrawer::DrawText(const char* text, int posX, int posY, int fontSize, Color color) {
    ::DrawText(text, posX, posY, fontSize, color);  // Call Raylib's DrawText function
}

// Implement the DrawTextEx function
void RaylibTextDrawer::DrawTextEx(Font font, const char* text, Vector2 position, float fontSize, float spacing, Color tint) {
    ::DrawTextEx(font, text, position, fontSize, spacing, tint);  // Call Raylib's DrawTextEx function
}

// Implement the DrawTextPro function
void RaylibTextDrawer::DrawTextPro(Font font, const char* text, Vector2 position, Vector2 origin, float rotation, float fontSize, float spacing, Color tint) {
    ::DrawTextPro(font, text, position, origin, rotation, fontSize, spacing, tint);  // Call Raylib's DrawTextPro function
}

// Implement the DrawTextCodepoint function
void RaylibTextDrawer::DrawTextCodepoint(Font font, int codepoint, Vector2 position, float fontSize, Color tint) {
    ::DrawTextCodepoint(font, codepoint, position, fontSize, tint);  // Call Raylib's DrawTextCodepoint function
}

// Implement the DrawTextCodepoints function
void RaylibTextDrawer::DrawTextCodepoints(Font font, const int* codepoints, int codepointCount, Vector2 position, float fontSize, float spacing, Color tint) {
    ::DrawTextCodepoints(font, codepoints, codepointCount, position, fontSize, spacing, tint);  // Call Raylib's DrawTextCodepoints function
}
