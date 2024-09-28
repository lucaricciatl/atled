#include "RaylibDisplay.hpp"
#include <raylib.h>

// Implement each method by calling corresponding Raylib functions
// Define the constructor
RaylibDisplay::RaylibDisplay() {

}

// Define the destructor
RaylibDisplay::~RaylibDisplay() {

}

void* RaylibDisplay::GetHandle(void) {
    return GetWindowHandle();  // Returns the native window handle
}

int RaylibDisplay::GetScreenWidth(void) {
    return GetScreenWidth();   // Returns the width of the screen
}

int RaylibDisplay::GetScreenHeight(void) {
    return GetScreenHeight();  // Returns the height of the screen
}

int RaylibDisplay::GetRenderWidth(void) {
    return GetRenderWidth();   // Returns the width of the rendering area
}

int RaylibDisplay::GetRenderHeight(void) {
    return GetRenderHeight();  // Returns the height of the rendering area
}

int RaylibDisplay::GetMonitorCount(void) {
    return GetMonitorCount();  // Returns the number of available monitors
}

int RaylibDisplay::GetCurrentMonitor(void) {
    return GetCurrentMonitor();  // Returns the current monitor index
}

Vector2 RaylibDisplay::GetMonitorPosition(int monitor) {
    return GetMonitorPosition(monitor);  // Returns the position of a specific monitor
}

int RaylibDisplay::GetMonitorWidth(int monitor) {
    return GetMonitorWidth(monitor);  // Returns the width of a specific monitor
}

int RaylibDisplay::GetMonitorHeight(int monitor) {
    return GetMonitorHeight(monitor);  // Returns the height of a specific monitor
}

int RaylibDisplay::GetMonitorPhysicalWidth(int monitor) {
    return GetMonitorPhysicalWidth(monitor);  // Returns the physical width of a specific monitor
}

int RaylibDisplay::GetMonitorPhysicalHeight(int monitor) {
    return GetMonitorPhysicalHeight(monitor);  // Returns the physical height of a specific monitor
}

int RaylibDisplay::GetMonitorRefreshRate(int monitor) {
    return GetMonitorRefreshRate(monitor);  // Returns the refresh rate of a specific monitor
}

Vector2 RaylibDisplay::GetPosition(void) {
    return GetWindowPosition();  // Returns the position of the window
}

Vector2 RaylibDisplay::GetScaleDPI(void) {
    return GetWindowScaleDPI();  // Returns the DPI scaling factor of the window
}
const char* RaylibDisplay::GetMonitorName(int monitor) {
    return GetMonitorName(monitor);  // Returns the name of a specific monitor
}
