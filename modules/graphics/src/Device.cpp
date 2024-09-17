#include "device.hpp"

namespace graphics {

// Create a new Device instance
std::unique_ptr<Device> Device::Create() {
    return std::make_unique<Device>();
}

// Screen-related functions
int Device::GetScreenWidth() const {
    return ::GetScreenWidth();
}

int Device::GetScreenHeight() const {
    return ::GetScreenHeight();
}

int Device::GetRenderWidth() const {
    return ::GetRenderWidth();
}

int Device::GetRenderHeight() const {
    return ::GetRenderHeight();
}

// Monitor-related functions
int Device::GetMonitorCount() const {
    return ::GetMonitorCount();
}

int Device::GetCurrentMonitor() const {
    return ::GetCurrentMonitor();
}

Vector2 Device::GetMonitorPosition(int aMonitor) const {
    return ::GetMonitorPosition(aMonitor);
}

int Device::GetMonitorWidth(int aMonitor) const {
    return ::GetMonitorWidth(aMonitor);
}

int Device::GetMonitorHeight(int aMonitor) const {
    return ::GetMonitorHeight(aMonitor);
}

int Device::GetMonitorPhysicalWidth(int aMonitor) const {
    return ::GetMonitorPhysicalWidth(aMonitor);
}

int Device::GetMonitorPhysicalHeight(int aMonitor) const {
    return ::GetMonitorPhysicalHeight(aMonitor);
}

int Device::GetMonitorRefreshRate(int aMonitor) const {
    return ::GetMonitorRefreshRate(aMonitor);
}

} // namespace graphics
