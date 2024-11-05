#ifndef INPUTMANAGERBUILDER_HPP
#define INPUTMANAGERBUILDER_HPP

#include "InputManager.hpp"
#include "KeyboardFactory.hpp"
#include "MouseFactory.hpp"

namespace input {

class InputManagerBuilder {
public:
    // Methods to set keyboard and mouse types
    InputManagerBuilder& SetKeyboardType(KeyboardType type);
    InputManagerBuilder& SetMouseType(MouseType type);

    // Build method to create the InputManager with the configured settings
    std::unique_ptr<InputManager> Build();

private:
    KeyboardType keyboardType = KeyboardType::Raylib; // Default type
    MouseType mouseType = MouseType::Raylib;          // Default type
};

} // namespace input

#endif // INPUTMANAGERBUILDER_HPP
