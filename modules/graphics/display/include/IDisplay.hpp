#ifndef IDISPLAY_HPP
#define IDISPLAY_HPP

#include <raylib.hpp>  // Assuming you're using Raylib for Vector2 and other window functions

class IDisplay {
public:
    virtual ~IDisplay() = default;

    // Pure virtual functions that derived classes must implement
    virtual void* GetHandle(void) = 0;
    virtual int GetScreenWidth(void) = 0;
    virtual int GetScreenHeight(void) = 0;
    virtual int GetRenderWidth(void) = 0;
    virtual int GetRenderHeight(void) = 0;
    virtual int GetMonitorCount(void) = 0;
    virtual int GetCurrentMonitor(void) = 0;
    virtual Vector2 GetMonitorPosition(int monitor) = 0;
    virtual int GetMonitorWidth(int monitor) = 0;
    virtual int GetMonitorHeight(int monitor) = 0;
    virtual int GetMonitorPhysicalWidth(int monitor) = 0;
    virtual int GetMonitorPhysicalHeight(int monitor) = 0;
    virtual int GetMonitorRefreshRate(int monitor) = 0;
    virtual Vector2 GetPosition(void) = 0;
    virtual Vector2 GetScaleDPI(void) = 0;
    virtual const char* GetMonitorName(int monitor) = 0;
};

#endif // IDISPLAY_HPP
