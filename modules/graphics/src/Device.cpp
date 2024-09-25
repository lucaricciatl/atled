#include "device.hpp"
#include "gfx.hpp"  // Assuming gfx.hpp contains the RLAPI declarations
namespace graphics {

// Create a new Device instance
std::unique_ptr<Device> Device::Create() {
    return std::make_unique<Device>();
}

// Screen-related functions
int Device::GetScreenWidth() const {
    return gfx::GetScreenWidth();
}

int Device::GetScreenHeight() const {
    return gfx::GetScreenHeight();
}

int Device::GetRenderWidth() const {
    return gfx::GetRenderWidth();
}

int Device::GetRenderHeight() const {
    return gfx::GetRenderHeight();
}

// Monitor-related functions
int Device::GetMonitorCount() const {
    return gfx::GetMonitorCount();
}

int Device::GetCurrentMonitor() const {
    return gfx::GetCurrentMonitor();
}

Vector2 Device::GetMonitorPosition(int aMonitor) const {
    return gfx::GetMonitorPosition(aMonitor);
}

int Device::GetMonitorWidth(int aMonitor) const {
    return gfx::GetMonitorWidth(aMonitor);
}

int Device::GetMonitorHeight(int aMonitor) const {
    return gfx::GetMonitorHeight(aMonitor);
}

int Device::GetMonitorPhysicalWidth(int aMonitor) const {
    return gfx::GetMonitorPhysicalWidth(aMonitor);
}

int Device::GetMonitorPhysicalHeight(int aMonitor) const {
    return gfx::GetMonitorPhysicalHeight(aMonitor);
}

int Device::GetMonitorRefreshRate(int aMonitor) const {
    return gfx::GetMonitorRefreshRate(aMonitor);
}

} // namespace graphics
