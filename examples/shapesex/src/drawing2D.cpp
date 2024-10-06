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

  auto configs = graphics::GfxConfig({FLAG_WINDOW_RESIZABLE, FLAG_VSYNC_HINT,
                                      FLAG_WINDOW_HIGHDPI, FLAG_MSAA_4X_HINT});
  input::Mouse mouse;
  mouse.Start();  // Start the mouse thread
  graphicsMng->SetConfigs(configs);
  graphicsMng->Start();

  return 0;
}




