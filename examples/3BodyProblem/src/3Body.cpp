#include "GraphicsContext.hpp"
#include "graphicsImpl.hpp"
#include "Mouse.hpp"
#include "Keyboard.hpp"

int main() {
    // Initialize the GraphicsManager
    auto graphicsMng = std::make_shared<GraphicsManagerImpl>();
    graphicsMng->Init();  // Initialize the graphics manager

    // Get the graphics context and configure the window
    auto ctx = graphicsMng->GetGraphicsContext();
    ctx->SetSize(900, 900);  // Set window size
    ctx->SetTitle("Atled");  // Set window title

    // Initialize keyboard and mouse input
    input::KeyboardInput keyboard;
    keyboard.Start();  // Start keyboard input handling
    input::Mouse mouse;
    mouse.Start();  // Start mouse input handling

    // Configure the graphics window (e.g., transparent, undecorated window)
    auto configs = graphics::GfxConfig();
    graphicsMng->SetConfigs(configs);  // Apply graphics configuration
    graphicsMng->Start();  // Start the rendering


    return 0;
}
