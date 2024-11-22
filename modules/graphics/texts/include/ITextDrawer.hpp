#ifndef TEXTDRAWER_HPP
#define TEXTDRAWER_HPP

// Include the necessary headers for Color, Font, and Vector2 (adjust as needed)
#include "raylib.hpp"  // Assuming raylib is the library used for rendering

namespace graphics {

// Abstract class for Text Drawing
class ITextDrawer {
public:
    // Virtual destructor to ensure proper cleanup of derived classes
  virtual ~ITextDrawer() = default;

  // Pure virtual function to draw FPS at a specific position
  virtual void DrawFPS(int posX, int posY) = 0;

  // Pure virtual function to draw text using the default font
  virtual void DrawText(const char *text, int posX, int posY, int fontSize,
                        Color color) = 0;

  // Pure virtual function to draw text with custom font and additional
  // parameters
  virtual void DrawTextEx(Font font, const char *text, Vector2 position,
                          float fontSize, float spacing, Color tint) = 0;

  // Pure virtual function to draw text with advanced options such as rotation
  // and origin
  virtual void DrawTextPro(Font font, const char *text, Vector2 position,
                           Vector2 origin, float rotation, float fontSize,
                           float spacing, Color tint) = 0;

  // Pure virtual function to draw a single character (codepoint)
  virtual void DrawTextCodepoint(Font font, int codepoint, Vector2 position,
                                 float fontSize, Color tint) = 0;

  // Pure virtual function to draw multiple characters (codepoints)
  virtual void DrawTextCodepoints(Font font, const int *codepoints,
                                  int codepointCount, Vector2 position,
                                  float fontSize, float spacing,
                                  Color tint) = 0;
};

}
#endif // TEXTDRAWER_HPP
