#include "GraphicsManagerImpl.hpp"

GraphicsManagerImpl::GraphicsManagerImpl(int numBodies)
    : simulation(numBodies) {}

void GraphicsManagerImpl::Init() {
    auto ctx = GetGraphicsContext();
    ctx->SetSize(900, 900);
    ctx->SetTitle("N-body Simulation");

    // Initialize the simulation and graphics settings
    simulation.InitializeBodies();
    for (const auto& circle : simulation.GetCircles()) {
        AddCircle(1, circle);
    }

    auto configs = graphics::GfxConfig({FLAG_WINDOW_RESIZABLE, FLAG_VSYNC_HINT,
                                        FLAG_WINDOW_HIGHDPI, FLAG_MSAA_4X_HINT});
    SetConfigs(configs);
    ctx->InitWindowManager();

}

void GraphicsManagerImpl::Render() {
    float dt = 0.005f; // Time step for the simulation
    simulation.Update(dt);

    GetGraphicsContext()->BeginDrawing();
    Clear(::Color(0, 0, 0, 0));
    DrawLayer(1);    
    GetGraphicsContext()->EndDrawing(); // Finish the current frame

  


}
