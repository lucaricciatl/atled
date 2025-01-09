#include <iostream>
#include <memory>

#include "AtledMouse.hpp"
#include "MouseFactory.hpp"  // Ensure this header is included

int main() {
    try {
        // Create an AtledMouse instance
        auto mouse = input::MouseFactory::CreateMouse(input::MouseType::Atled);

        // Optional: Start a background thread to continuously update mouse state
        mouse->Start();

        // Move mouse to (400, 300)
        mouse->SetMousePosition(400, 300);
        std::cout << "Set mouse position to (400, 300)\n";
        mouse->GetMousePosition();
        std::cout << "Mouse position: " << mouse->GetMousePosition().x << ", " << mouse->GetMousePosition().y
                  << std::endl;
        // Show or hide cursor
        mouse->HideCursor();
        std::cout << "Cursor is hidden? " << std::boolalpha << mouse->IsCursorHidden() << std::endl;
        mouse->ShowCursor();
        std::cout << "Cursor is hidden? " << std::boolalpha << mouse->IsCursorHidden() << std::endl;

        // Query mouse button states
        std::cout << "Left button is down? " << std::boolalpha << mouse->IsButtonDown(0) << std::endl;

        // Stop background thread before exiting
        mouse->Stop();
    } catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << "\n";
        return 1;
    }
    return 0;
}
