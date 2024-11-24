#ifndef IWINDOW_HPP
#define IWINDOW_HPP

#include "raylib.hpp"  // Assuming you're using Raylib or a similar library

class IWindow {
public:
    virtual ~IWindow() = default;

    // Declare all the window-related methods as pure virtual functions
    virtual void InitWindow(int width, int height, const char *title) = 0;
    virtual void CloseWindow(void) = 0;
    virtual bool ShouldClose(void) const = 0;
    virtual bool IsReady(void) const = 0;
    virtual bool IsFullscreen(void) const = 0;
    virtual bool IsHidden(void) const = 0;
    virtual bool IsMinimized(void) const = 0;
    virtual bool IsMaximized(void) const = 0;
    virtual bool IsFocused(void) const = 0;
    virtual bool IsResized(void) const = 0;
    virtual bool IsState(unsigned int flag) const = 0;

    virtual void SetState(unsigned int flags) = 0;
    virtual void ClearState(unsigned int flags) = 0;
    virtual void ToggleFullscreen(void) = 0;
    virtual void Maximize(void) = 0;
    virtual void Minimize(void) = 0;
    virtual void Restore(void) = 0;

    virtual void SetIcon(raylib::Image image) = 0;
    virtual void SetIcons(raylib::Image *images, int count) = 0;
    virtual void SetTitle(const char *title) = 0;
    virtual void SetPosition(int x, int y) = 0;
    virtual void SetMonitor(int monitor) = 0;
    virtual void SetMinSize(int width, int height) = 0;
    virtual void SetMaxSize(int width, int height) = 0;
    virtual void SetSize(int width, int height) = 0;
    virtual void SetOpacity(float opacity) = 0;
    virtual void Focus(void) = 0;

    virtual void SetClipboardText(const char *text) = 0;
    virtual const char *GetClipboardText(void) const = 0;

    virtual void EnableEventWaiting(void) = 0;
    virtual void DisableEventWaiting(void) = 0;
};

#endif // IWINDOW_HPP
