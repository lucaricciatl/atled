#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <memory>
#include "raylib.h"  // Assuming raylib.h contains the RLAPI declarations

namespace graphics {

class Device {
public:
    static std::unique_ptr<Device> Create();

    // Screen-related functions
    int GetScreenWidth() const;
    int GetScreenHeight() const;
    int GetRenderWidth() const;
    int GetRenderHeight() const;

    // Monitor-related functions
    int GetMonitorCount() const;
    int GetCurrentMonitor() const;
    raylib::Vector2 GetMonitorPosition(int aMonitor) const;
    int GetMonitorWidth(int aMonitor) const;
    int GetMonitorHeight(int aMonitor) const;
    int GetMonitorPhysicalWidth(int aMonitor) const;
    int GetMonitorPhysicalHeight(int aMonitor) const;
    int GetMonitorRefreshRate(int aMonitor) const;

    Device() = default;
};

} // namespace graphics

#endif // DEVICE_HPP
