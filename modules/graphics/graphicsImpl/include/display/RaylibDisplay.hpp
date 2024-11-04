#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "raylib.h"  // Include raylib (or another library) for window management functions
#include "IDisplay.hpp"

class RaylibDisplay : public IDisplay {
public:
    RaylibDisplay();  
    ~RaylibDisplay(); 


    // Window information retrieval functions
    void *GetHandle(void) ;
    int GetScreenWidth(void) ;
    int GetScreenHeight(void) ;
    int GetRenderWidth(void) ;
    int GetRenderHeight(void) ;
    int GetMonitorCount(void) ;
    int GetCurrentMonitor(void) ;
    Vector2 GetMonitorPosition(int monitor) ;
    int GetMonitorWidth(int monitor) ;
    int GetMonitorHeight(int monitor) ;
    int GetMonitorPhysicalWidth(int monitor) ;
    int GetMonitorPhysicalHeight(int monitor) ;
    int GetMonitorRefreshRate(int monitor) ;
    Vector2 GetPosition(void) ;
    Vector2 GetScaleDPI(void) ;
    const char *GetMonitorName(int monitor) ;
};

#endif // WINDOW_HPP
