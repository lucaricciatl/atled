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
    return GetScreenWidth();
}

int RaylibDisplay::GetScreenHeight(void) {
    return GetScreenHeight();
}

int RaylibDisplay::GetRenderWidth(void) {
    return GetRenderWidth();
}

int RaylibDisplay::GetRenderHeight(void) {
    return GetRenderHeight();
}

int RaylibDisplay::GetMonitorCount(void) {
    return GetMonitorCount();
}

int RaylibDisplay::GetCurrentMonitor(void) {
    return GetCurrentMonitor();
}

Vector2 RaylibDisplay::GetMonitorPosition(int monitor) {
    return GetMonitorPosition(monitor);
}

int RaylibDisplay::GetMonitorWidth(int monitor) {
    return GetMonitorWidth(monitor);
}

int RaylibDisplay::GetMonitorHeight(int monitor) {
    return GetMonitorHeight(monitor);
}

int RaylibDisplay::GetMonitorPhysicalWidth(int monitor) {
    return GetMonitorPhysicalWidth(monitor);
}

int RaylibDisplay::GetMonitorPhysicalHeight(int monitor) {
    return GetMonitorPhysicalHeight(monitor);
}

int RaylibDisplay::GetMonitorRefreshRate(int monitor) {
    return GetMonitorRefreshRate(monitor);
}

Vector2 RaylibDisplay::GetPosition(void) {
    return GetWindowPosition();
}

Vector2 RaylibDisplay::GetScaleDPI(void) {
    return GetWindowScaleDPI();
}

const char* RaylibDisplay::GetMonitorName(int monitor) {
    return GetMonitorName(monitor);
}
