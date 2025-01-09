#ifndef MOUSEFACTORY_HPP
#define MOUSEFACTORY_HPP

#include "IMouse.hpp"
#include <memory>
#include "AtledMouse.hpp"
#include "RaylibMouse.hpp"

namespace input {

class MouseFactory {
public:
  static std::unique_ptr<IMouse> CreateMouse(MouseType type) {
    switch (type) {
    case MouseType::Raylib:
      return std::make_unique<RaylibMouse>();
    case MouseType::Atled:
       return std::make_unique<AtledMouse>();
    default:
      return nullptr;
    }
    };
};

} // namespace input

#endif // MOUSEFACTORY_HPP
