#include "Color.hpp"
#include "GraphicsContext.hpp"
#include "GraphicsManager.hpp"
#include "Polyline2D.hpp"

int main() {
  // Initialize the GraphicsManager
  auto graphicsMng = std::make_shared<graphics::GraphicsManager>();

  auto configs = graphics::GfxConfig(
      {FLAG_WINDOW_UNDECORATED, FLAG_WINDOW_TRANSPARENT});
  graphicsMng->SetConfigs(configs);
  graphicsMng->Start();
  // Main game loop
  while (true) {
    // depending on your GraphicsManager class design.
  }

  return 0;
}