#include "TextRenderer.hpp"

// Constructor: create the textDrawer instance using the factory
TextRenderer::TextRenderer() {
    textDrawer = TextDrawerFactory::CreateTextDrawer();
}

// Destructor: clean up the textDrawer instance
TextRenderer::~TextRenderer() {
    delete textDrawer;
}

// Implement RenderFPS using the textDrawer instance
void TextRenderer::RenderFPS(int posX, int posY) {
    textDrawer->DrawFPS(posX, posY);
}

// Implement RenderText using the textDrawer instance
void TextRenderer::RenderText(const char* text, int posX, int posY, int fontSize, Color color) {
    textDrawer->DrawText(text, posX, posY, fontSize, color);
}

// Implement RenderTextEx using the textDrawer instance
void TextRenderer::RenderTextEx(Font font, const char* text, Vector2 position, float fontSize, float spacing, Color tint) {
    textDrawer->DrawTextEx(font, text, position, fontSize, spacing, tint);
}

// Implement RenderTextPro using the textDrawer instance
void TextRenderer::RenderTextPro(Font font, const char* text, Vector2 position, Vector2 origin, float rotation, float fontSize, float spacing, Color tint) {
    textDrawer->DrawTextPro(font, text, position, origin, rotation, fontSize, spacing, tint);
}

// Implement RenderCharacter using the textDrawer instance
void TextRenderer::RenderCharacter(Font font, int codepoint, Vector2 position, float fontSize, Color tint) {
    textDrawer->DrawTextCodepoint(font, codepoint, position, fontSize, tint);
}

// Implement RenderCharacters using the textDrawer instance
void TextRenderer::RenderCharacters(Font font, const int* codepoints, int codepointCount, Vector2 position, float fontSize, float spacing, Color tint) {
    textDrawer->DrawTextCodepoints(font, codepoints, codepointCount, position, fontSize, spacing, tint);
}
