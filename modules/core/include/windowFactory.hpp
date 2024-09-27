#ifndef WINDOW_FACTORY_HPP
#define WINDOW_FACTORY_HPP

#include <memory>            // For std::unique_ptr
#include "RaylibWindow.hpp"  // Include the specific window implementations

enum class WindowType {
    Raylib
};


// WindowFactory class to create instances of IWindow
class WindowFactory {
public:
    // Static method to create windows based on the type
    static std::unique_ptr<IWindow> CreateWindow(WindowType type);
};

#endif // WINDOW_FACTORY_HPP
