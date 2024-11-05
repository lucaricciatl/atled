#ifndef KEYBOARDINPUTFACTORY_HPP
#define KEYBOARDINPUTFACTORY_HPP

#include "IKeyboard.hpp"
#include "RaylibKeyboard.hpp"
#include <memory>

namespace input {

class KeyboardFactory {
public:
    static std::unique_ptr<IKeyboard> CreateKeyboardInput() {
        return std::make_unique<RaylibKeyboard>();
    }
};

} // namespace input

#endif // KEYBOARDINPUTFACTORY_HPP
