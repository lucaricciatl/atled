#include "windowFactory.hpp"

std::unique_ptr<IWindow> WindowFactory::CreateWindow(WindowType type) {
    switch (type) {
        case WindowType::Raylib:
            return std::make_unique<RaylibWindow>();
        default:
            return nullptr;
    }
}