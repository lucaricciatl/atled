#include "GraphicsContext.hpp"
#include "GraphicsManager.hpp"
#include "Polyline2D.hpp"
#include "Mouse.hpp"
#include "Keyboard.hpp"
#include "gfx.hpp"
int main() {
  // Initialize the GraphicsManager
  auto graphicsMng = std::make_shared<graphics::GraphicsManager>();
  auto ctx = graphicsMng->GetGraphicsContext();
  ctx->SetSize(900,900);
  ctx->SetTitle("Atled");
  KeyboardInput keyboard;
  keyboard.Start();
  auto configs = graphics::GfxConfig();
  input::Mouse mouse;
  mouse.Start();  // Start the mouse thread
  graphicsMng->SetConfigs(configs);
  graphicsMng->Start();
  // Main game loop
  while (true) {
    // depending on your GraphicsManager class design.
  }

  return 0;
}