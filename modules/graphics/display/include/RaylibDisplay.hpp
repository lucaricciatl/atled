// RaylibDisplay.hpp
#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "raylib.h"  // Include raylib for window management functions
#include "IDisplay.hpp"

class RaylibDisplay : public IDisplay {
public:
    RaylibDisplay();  
    ~RaylibDisplay();  

    // Implement all required virtual functions from IDisplay

    void* GetHandle(void) override;
    int GetScreenWidth(void) override;
    int GetScreenHeight(void) override;
    int GetRenderWidth(void) override;
    int GetRenderHeight(void) override;
    int GetMonitorCount(void) override;
    int GetCurrentMonitor(void) override;
    Vector2 GetMonitorPosition(int monitor) override;
    int GetMonitorWidth(int monitor) override;
    int GetMonitorHeight(int monitor) override;
    int GetMonitorPhysicalWidth(int monitor) override;
    int GetMonitorPhysicalHeight(int monitor) override;
    int GetMonitorRefreshRate(int monitor) override;
    Vector2 GetPosition(void) override;
    Vector2 GetScaleDPI(void) override;
    const char* GetMonitorName(int monitor) override;
};

#endif // WINDOW_HPP