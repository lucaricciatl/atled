#ifdef __APPLE__
#include "screenshot_util.hpp"
#include <iostream>
#include <ApplicationServices/ApplicationServices.h>

void MacScreenshot(const char* filename) {
    // macOS implementation using Quartz
    CGImageRef screenshot = CGWindowListCreateImage(CGRectInfinite,
                                                    kCGWindowListOptionOnScreenOnly,
                                                    kCGNullWindowID,
                                                    kCGWindowImageDefault);
    if (screenshot) {
        // TODO: Save the CGImageRef to file using ImageIO or similar framework.
        std::cout << "Screenshot captured successfully (macOS) with filename: " << filename << std::endl;
        CGImageRelease(screenshot);
    } else {
        std::cerr << "Failed to capture screenshot on macOS." << std::endl;
    }
}
#endif