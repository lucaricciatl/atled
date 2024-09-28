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
    KeyboardInput keyboard;
    keyboard.Start();  // Start keyboard input handling
    input::Mouse mouse;
    mouse.Start();  // Start mouse input handling

    // Configure the graphics window (e.g., transparent, undecorated window)
    auto configs = graphics::GfxConfig();
    graphicsMng->SetConfigs(configs);  // Apply graphics configuration
    graphicsMng->Start();  // Start the rendering

    // Main game loop
    bool running = true;
    while (running) {
        // Render frame (graphicsMng->Render() is called inside this loop)
        graphicsMng->Render();

        // Handle input (e.g., exit loop when the 'Escape' key is pressed)
        if (keyboard.IsKeyPressed(KEY_ESCAPE)) {
            running = false;  // Exit the loop if the Escape key is pressed
        }

        // Depending on how your mouse and keyboard handling works, you can also
        // add custom logic for mouse events or other keyboard input here.
        if (mouse.IsButtonPressed(MOUSE_LEFT_BUTTON)) {
            // Example of handling mouse click (implement your logic)
        }
        
        // Optionally, add a small sleep or frame limiting mechanism to avoid CPU overuse
        // std::this_thread::sleep_for(std::chrono::milliseconds(16));  // Approx 60 FPS
    }

    // Clean up and exit (if required, stop threads or free resources here)

    return 0;
}
