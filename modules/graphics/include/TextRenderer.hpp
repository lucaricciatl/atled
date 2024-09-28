#ifndef TEXTRENDERER_HPP
#define TEXTRENDERER_HPP

#include "TextFactory.hpp"

// Class that uses TextDrawer to manage and render text elements
class TextRenderer {
private:
    ITextDrawer* textDrawer;  // Pointer to the TextDrawer instance

public:
    // Constructor: create the textDrawer instance using the factory
    TextRenderer();

    // Destructor: clean up the textDrawer instance
    ~TextRenderer();

    // Method to render the FPS at a specific position
    void RenderFPS(int posX, int posY);

    // Method to render a simple text message at a specific position
    void RenderText(const char* text, int posX, int posY, int fontSize, Color color);

    // Method to render text using a custom font and parameters
    void RenderTextEx(Font font, const char* text, Vector2 position, float fontSize, float spacing, Color tint);

    // Method to render text with advanced options such as rotation and origin
    void RenderTextPro(Font font, const char* text, Vector2 position, Vector2 origin, float rotation, float fontSize, float spacing, Color tint);

    // Method to render a single character (codepoint)
    void RenderCharacter(Font font, int codepoint, Vector2 position, float fontSize, Color tint);

    // Method to render multiple characters (codepoints)
    void RenderCharacters(Font font, const int* codepoints, int codepointCount, Vector2 position, float fontSize, float spacing, Color tint);
};

#endif // TEXTRENDERER_HPP
