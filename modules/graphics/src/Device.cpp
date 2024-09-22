#include "device.hpp"
#include "raylib.h"  // Assuming raylib.h contains the RLAPI declarations
namespace graphics {

// Create a new Device instance
std::unique_ptr<Device> Device::Create() {
    return std::make_unique<Device>();
}

// Screen-related functions
int Device::GetScreenWidth() const {
    return raylib::GetScreenWidth();
}

int Device::GetScreenHeight() const {
    return raylib::GetScreenHeight();
}

int Device::GetRenderWidth() const {
    return raylib::GetRenderWidth();
}

int Device::GetRenderHeight() const {
    return raylib::GetRenderHeight();
}

// Monitor-related functions
int Device::GetMonitorCount() const {
    return raylib::GetMonitorCount();
}

int Device::GetCurrentMonitor() const {
    return raylib::GetCurrentMonitor();
}

raylib::Vector2 Device::GetMonitorPosition(int aMonitor) const {
    return raylib::GetMonitorPosition(aMonitor);
}

int Device::GetMonitorWidth(int aMonitor) const {
    return raylib::GetMonitorWidth(aMonitor);
}

int Device::GetMonitorHeight(int aMonitor) const {
    return raylib::GetMonitorHeight(aMonitor);
}

int Device::GetMonitorPhysicalWidth(int aMonitor) const {
    return raylib::GetMonitorPhysicalWidth(aMonitor);
}

int Device::GetMonitorPhysicalHeight(int aMonitor) const {
    return raylib::GetMonitorPhysicalHeight(aMonitor);
}

int Device::GetMonitorRefreshRate(int aMonitor) const {
    return raylib::GetMonitorRefreshRate(aMonitor);
}

} // namespace graphics
