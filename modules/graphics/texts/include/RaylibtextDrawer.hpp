#ifndef RAYLIBTEXTDRAWER_HPP
#define RAYLIBTEXTDRAWER_HPP

#include "ITextDrawer.hpp"
#include "raylib.hpp"  // Raylib includes

namespace graphics {

// Concrete class that implements TextDrawer using Raylib
class RaylibTextDrawer : public ITextDrawer {
public:
  ~RaylibTextDrawer();
  // Implement DrawFPS using Raylib's DrawFPS function
  void DrawFPS(int posX, int posY) override;

  // Implement DrawText using Raylib's DrawText function
  void DrawText(const char *text, int posX, int posY, int fontSize,
                Color color) override;

  // Implement DrawTextEx using Raylib's DrawTextEx function
  void DrawTextEx(Font font, const char *text, Vector2 position, float fontSize,
                  float spacing, Color tint) override;

  // Implement DrawTextPro using Raylib's DrawTextPro function
  void DrawTextPro(Font font, const char *text, Vector2 position,
                   Vector2 origin, float rotation, float fontSize,
                   float spacing, Color tint) override;

  // Implement DrawTextCodepoint using Raylib's DrawTextCodepoint function
  void DrawTextCodepoint(Font font, int codepoint, Vector2 position,
                         float fontSize, Color tint) override;

  // Implement DrawTextCodepoints using Raylib's DrawTextCodepoints function
  void DrawTextCodepoints(Font font, const int *codepoints, int codepointCount,
                          Vector2 position, float fontSize, float spacing,
                          Color tint) override;
};
}

#endif // RAYLIBTEXTDRAWER_HPP
