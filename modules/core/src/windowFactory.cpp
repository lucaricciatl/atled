#include "windowFactory.hpp"

std::unique_ptr<IWindow> WindowFactory::CreateWindow(WindowType type) {
    switch (type) {
        case WindowType::Raylib:
            return std::make_unique<raylib::RaylibWindow>();
        default:
            return nullptr;
    }
}