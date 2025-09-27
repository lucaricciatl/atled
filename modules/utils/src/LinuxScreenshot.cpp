#ifdef __linux__
#include "screenshot_util.hpp"
#include <iostream>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

/* void LinuxScreenshot(const char* filename) {
    // Linux implementation using X11
    Display* display = XOpenDisplay(nullptr);
    if (display == nullptr) {
        std::cerr << "Cannot open X display." << std::endl;
        return;
    }

    Window root = DefaultRootWindow(display);
    XWindowAttributes gwa;
    XGetWindowAttributes(display, root, &gwa);
    int width = gwa.width;
    int height = gwa.height;

    XImage* image = XGetImage(display, root, 0, 0, width, height, AllPlanes, ZPixmap);
    if (image) {
        // TODO: Convert and save XImage to file (e.g., using libpng).
        std::cout << "Screenshot captured successfully (Linux) with filename: " << filename << std::endl;
        XDestroyImage(image);
    } else {
        std::cerr << "Failed to capture screenshot on Linux." << std::endl;
    }
    XCloseDisplay(display);
} */
#endif