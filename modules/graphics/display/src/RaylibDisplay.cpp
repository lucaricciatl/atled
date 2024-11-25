#include "RaylibDisplay.hpp"

RaylibDisplay::RaylibDisplay() {
    // Initialize the display, if necessary
}

RaylibDisplay::~RaylibDisplay() {
    // Cleanup the display, if necessary
}

// Implementing all functions from IDisplay interface

void* RaylibDisplay::GetHandle(void) {
    // Raylib does not provide a direct handle, so returning nullptr or a placeholder
    return nullptr;
}

int RaylibDisplay::GetScreenWidth(void) {
    return raylib::GetScreenWidth();
}

int RaylibDisplay::GetScreenHeight(void) {
    return raylib::GetScreenHeight();
}

int RaylibDisplay::GetRenderWidth(void) {
    return raylib::GetRenderWidth();
}

int RaylibDisplay::GetRenderHeight(void) {
    return raylib::GetRenderHeight();
}

int RaylibDisplay::GetMonitorCount(void) {
    return raylib::GetMonitorCount();
}

int RaylibDisplay::GetCurrentMonitor(void) {
    return raylib::GetCurrentMonitor();
}

raylib::Vector2 RaylibDisplay::GetMonitorPosition(int monitor) {
    return raylib::GetMonitorPosition(monitor);
}

int RaylibDisplay::GetMonitorWidth(int monitor) {
    return raylib::GetMonitorWidth(monitor);
}

int RaylibDisplay::GetMonitorHeight(int monitor) {
    return raylib::GetMonitorHeight(monitor);
}

int RaylibDisplay::GetMonitorPhysicalWidth(int monitor) {
    return raylib::GetMonitorPhysicalWidth(monitor);
}

int RaylibDisplay::GetMonitorPhysicalHeight(int monitor) {
    return raylib::GetMonitorPhysicalHeight(monitor);
}

int RaylibDisplay::GetMonitorRefreshRate(int monitor) {
    return raylib::GetMonitorRefreshRate(monitor);
}

raylib::Vector2 RaylibDisplay::GetPosition(void) {
    return raylib::GetWindowPosition();
}

raylib::Vector2 RaylibDisplay::GetScaleDPI(void) {
    return raylib::GetWindowScaleDPI();
}

const char* RaylibDisplay::GetMonitorName(int monitor) {
    return raylib::GetMonitorName(monitor);
}
