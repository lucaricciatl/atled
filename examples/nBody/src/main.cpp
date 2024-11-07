#include "GraphicsManagerImpl.hpp"
#include <memory>

int main() {
    auto graphicsManager = std::make_shared<GraphicsManagerImpl>(1000); // 1000 bodies for simulation

    graphicsManager->Init();
    graphicsManager->Start(); // Runs the main rendering loop

    return 0;
}