#include "GraphicsContext.hpp"
#include "Keyboard.hpp"
#include "Mouse.hpp"
#include "graphicsImpl.hpp"

int main() {
  // Initialize the GraphicsManager
  auto graphicsMng = std::make_shared<GraphicsManagerImpl>();
  graphicsMng->Init();
  auto ctx = graphicsMng->GetGraphicsContext();
  ctx->SetSize(900, 900);
  ctx->SetTitle("Atled");

  auto configs =
      graphics::GfxConfig({FLAG_WINDOW_UNDECORATED, FLAG_WINDOW_TRANSPARENT});
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


