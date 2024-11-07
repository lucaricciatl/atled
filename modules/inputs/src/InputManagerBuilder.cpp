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
    return std::make_unique<InputManager>(keyboardType, mouseType);

}


} // namespace input
