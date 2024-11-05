#include "EngineBuilder.hpp"

namespace core {

EngineBuilder& EngineBuilder::SetKeyboardType(input::KeyboardType type) {
    inputManagerBuilder.SetKeyboardType(type);
    return *this;
}

EngineBuilder& EngineBuilder::SetMouseType(input::MouseType type) {
    inputManagerBuilder.SetMouseType(type);
    return *this;
}

// EngineBuilder& EngineBuilder::SetGraphicsConfig(const graphics::GraphicsConfig& config) {
//     graphicsManagerBuilder.SetConfig(config);
//     return *this;
// }

std::unique_ptr<CoreEngine> EngineBuilder::Build() {
    auto inputManager = inputManagerBuilder.Build();
    // auto graphicsManager = graphicsManagerBuilder.Build();
    return std::make_unique<CoreEngine>(std::move(inputManager) /*, std::move(graphicsManager) */);
}

} // namespace engine
