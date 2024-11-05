#include "InputManagerBuilder.hpp"

namespace input {

InputManagerBuilder& InputManagerBuilder::SetKeyboardType(KeyboardType type) {
    keyboardType = type;
    return *this;
}

InputManagerBuilder& InputManagerBuilder::SetMouseType(MouseType type) {
    mouseType = type;
    return *this;
}

std::unique_ptr<InputManager> InputManagerBuilder::Build() {
    auto keyboard = KeyboardInputFactory::CreateKeyboardInput(keyboardType);
    auto mouse = MouseFactory::CreateMouse(mouseType);
    return std::make_unique<InputManager>(std::move(keyboard), std::move(mouse));
}

} // namespace input
