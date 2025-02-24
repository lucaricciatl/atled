#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "raylib.hpp"  // Include raylib (or another library) for window management functions
#include "IWindow.hpp"

class RaylibWindow : public IWindow {
public:
    // Constructor and Destructor
    RaylibWindow();  // Constructor to initialize the window
    ~RaylibWindow();  // Destructor to close the window

    // Window functions
    void InitWindow(int width, int height, const char *title);
    void CloseWindow(void);
    bool ShouldClose(void) const;
    bool IsReady(void) const;
    bool IsFullscreen(void) const;
    bool IsHidden(void) const;
    bool IsMinimized(void) const;
    bool IsMaximized(void) const;
    bool IsFocused(void) const;
    bool IsResized(void) const;
    bool IsState(unsigned int flag) const;

    void SetState(unsigned int flags);
    void ClearState(unsigned int flags);
    void ToggleFullscreen(void);
    void Maximize(void);
    void Minimize(void);
    void Restore(void);

    void SetIcon(raylib::Image image);
    void SetIcons(raylib::Image *images, int count);
    void SetTitle(const char *title);
    void SetPosition(int x, int y);
    void SetMonitor(int monitor);
    void SetMinSize(int width, int height);
    void SetMaxSize(int width, int height);
    void SetSize(int width, int height);
    void SetOpacity(float opacity);
    void Focus(void);

    // Clipboard functions
    void SetClipboardText(const char *text);
    const char *GetClipboardText(void) const;

    // Event waiting functions
    void EnableEventWaiting(void);
    void DisableEventWaiting(void);
};

#endif // WINDOW_HPP
