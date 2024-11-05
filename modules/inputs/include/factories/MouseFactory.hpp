#ifndef MOUSEFACTORY_HPP
#define MOUSEFACTORY_HPP

#include "IMouse.hpp"
#include "RaylibMouse.hpp"
#include <memory>

namespace input {

class MouseFactory {
public:
  static std::unique_ptr<IMouse> CreateMouse() {
    return std::make_unique<RaylibMouse>();
  }
};

} // namespace input

#endif // MOUSEFACTORY_HPP
