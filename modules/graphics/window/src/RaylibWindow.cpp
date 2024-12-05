#include "RaylibWindow.hpp"


RaylibWindow::RaylibWindow() {
}

RaylibWindow::~RaylibWindow() {
    raylib::CloseWindow();  // Calls the underlying raylib function to close the window
}

void RaylibWindow::InitWindow(int width, int height, const char *title) {
    raylib::InitWindow(width, height, title);  // Calls Raylib's InitWindow
}

void RaylibWindow::CloseWindow() {
    return raylib::CloseWindow();
}

bool RaylibWindow::ShouldClose() const {
    return raylib::WindowShouldClose();
}

bool RaylibWindow::IsReady() const {
    return raylib::IsWindowReady();
}

bool RaylibWindow::IsFullscreen() const {
    return raylib::IsWindowFullscreen();
}

bool RaylibWindow::IsHidden() const {
    return raylib::IsWindowHidden();
}

bool RaylibWindow::IsMinimized() const {
    return raylib::IsWindowMinimized();
}

bool RaylibWindow::IsMaximized() const {
    return raylib::IsWindowMaximized();
}

bool RaylibWindow::IsFocused() const {
    return raylib::IsWindowFocused();
}

bool RaylibWindow::IsResized() const {
    return raylib::IsWindowResized();
}

bool RaylibWindow::IsState(unsigned int flag) const {
    return raylib::IsWindowState(flag);
}

void RaylibWindow::SetState(unsigned int flags) {
    raylib::SetWindowState(flags);
}

void RaylibWindow::ClearState(unsigned int flags) {
    raylib::ClearWindowState(flags);
}

void RaylibWindow::ToggleFullscreen() {
    raylib::ToggleFullscreen();
}

void RaylibWindow::Maximize() {
    raylib::MaximizeWindow();
}

void RaylibWindow::Minimize() {
    raylib::MinimizeWindow();
}

void RaylibWindow::Restore() {
    raylib::RestoreWindow();
}

void RaylibWindow::SetIcon(raylib::Image image) {
    raylib::SetWindowIcon(image);
}

void RaylibWindow::SetIcons(raylib::Image *images, int count) {
    raylib::SetWindowIcons(images, count);
}

void RaylibWindow::SetTitle(const char *title) {
    raylib::SetWindowTitle(title);
}

void RaylibWindow::SetPosition(int x, int y) {
    raylib::SetWindowPosition(x, y);
}

void RaylibWindow::SetMonitor(int monitor) {
    raylib::SetWindowMonitor(monitor);
}

void RaylibWindow::SetMinSize(int width, int height) {
    raylib::SetWindowMinSize(width, height);
}

void RaylibWindow::SetMaxSize(int width, int height) {
    raylib::SetWindowMaxSize(width, height);
}

void RaylibWindow::SetSize(int width, int height) {
    raylib::SetWindowSize(width, height);
}

void RaylibWindow::SetOpacity(float opacity) {
    raylib::SetWindowOpacity(opacity);
}

void RaylibWindow::Focus() {
    raylib::SetWindowFocused();
}

void RaylibWindow::SetClipboardText(const char *text) {
    raylib::SetClipboardText(text);
}

const char *RaylibWindow::GetClipboardText() const {
    return raylib::GetClipboardText();
}

void RaylibWindow::EnableEventWaiting() {
    raylib::EnableEventWaiting();
}

void RaylibWindow::DisableEventWaiting() {
    raylib::DisableEventWaiting();
}
