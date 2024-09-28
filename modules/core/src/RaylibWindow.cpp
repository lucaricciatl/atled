#include "RaylibWindow.hpp"

namespace raylib{
    


RaylibWindow::RaylibWindow() {
}

RaylibWindow::~RaylibWindow() {
    ::CloseWindow();  // Calls the underlying raylib function to close the window
}

void RaylibWindow::InitWindow(int width, int height, const char *title) {
    ::InitWindow(width, height, title);  // Calls Raylib's InitWindow
}

void RaylibWindow::CloseWindow() {
    return ::CloseWindow();
}

bool RaylibWindow::ShouldClose() const {
    return ::WindowShouldClose();
}

bool RaylibWindow::IsReady() const {
    return ::IsWindowReady();
}

bool RaylibWindow::IsFullscreen() const {
    return ::IsWindowFullscreen();
}

bool RaylibWindow::IsHidden() const {
    return ::IsWindowHidden();
}

bool RaylibWindow::IsMinimized() const {
    return ::IsWindowMinimized();
}

bool RaylibWindow::IsMaximized() const {
    return ::IsWindowMaximized();
}

bool RaylibWindow::IsFocused() const {
    return ::IsWindowFocused();
}

bool RaylibWindow::IsResized() const {
    return ::IsWindowResized();
}

bool RaylibWindow::IsState(unsigned int flag) const {
    return ::IsWindowState(flag);
}

void RaylibWindow::SetState(unsigned int flags) {
    ::SetWindowState(flags);
}

void RaylibWindow::ClearState(unsigned int flags) {
    ::ClearWindowState(flags);
}

void RaylibWindow::ToggleFullscreen() {
    ::ToggleFullscreen();
}

void RaylibWindow::Maximize() {
    ::MaximizeWindow();
}

void RaylibWindow::Minimize() {
    ::MinimizeWindow();
}

void RaylibWindow::Restore() {
    ::RestoreWindow();
}

void RaylibWindow::SetIcon(Image image) {
    ::SetWindowIcon(image);
}

void RaylibWindow::SetIcons(Image *images, int count) {
    ::SetWindowIcons(images, count);
}

void RaylibWindow::SetTitle(const char *title) {
    ::SetWindowTitle(title);
}

void RaylibWindow::SetPosition(int x, int y) {
    ::SetWindowPosition(x, y);
}

void RaylibWindow::SetMonitor(int monitor) {
    ::SetWindowMonitor(monitor);
}

void RaylibWindow::SetMinSize(int width, int height) {
    ::SetWindowMinSize(width, height);
}

void RaylibWindow::SetMaxSize(int width, int height) {
    ::SetWindowMaxSize(width, height);
}

void RaylibWindow::SetSize(int width, int height) {
    ::SetWindowSize(width, height);
}

void RaylibWindow::SetOpacity(float opacity) {
    ::SetWindowOpacity(opacity);
}

void RaylibWindow::Focus() {
    ::SetWindowFocused();
}

void RaylibWindow::SetClipboardText(const char *text) {
    ::SetClipboardText(text);
}

const char *RaylibWindow::GetClipboardText() const {
    return ::GetClipboardText();
}

void RaylibWindow::EnableEventWaiting() {
    ::EnableEventWaiting();
}

void RaylibWindow::DisableEventWaiting() {
    ::DisableEventWaiting();
}
}