#ifndef ENGINEBUILDER_HPP
#define ENGINEBUILDER_HPP

#include <memory>
#include "CoreEngine.hpp"
#include "InputManagerBuilder.hpp"
// #include "GraphicsManagerBuilder.hpp" // Placeholder for graphics management

namespace core {

class EngineBuilder {
public:
    EngineBuilder() = default;

    // Methods to configure the engine
    EngineBuilder& SetKeyboardType(input::KeyboardType type);
    EngineBuilder& SetMouseType(input::MouseType type);
    // EngineBuilder& SetGraphicsConfig(const graphics::GraphicsConfig& config); // Placeholder

    // Build method to create the CoreEngine instance
    std::unique_ptr<CoreEngine> Build();

private:
    input::InputManagerBuilder inputManagerBuilder;
    // graphics::GraphicsManagerBuilder graphicsManagerBuilder; // Placeholder
};

} // namespace engine

#endif // ENGINEBUILDER_HPP
