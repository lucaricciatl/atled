#ifndef SCREENSHOT_UTIL_H
#define SCREENSHOT_UTIL_H

#include <string>

// Returns a filename based on current date/time, e.g., "screenshot_20250609_153045.png".
std::string GetTimeStamp();

#ifdef _WIN32
// Windows-specific screenshot function that saves the screenshot to the provided filename.
void WinScreenshot(const char* filename);
#endif

#ifdef __APPLE__
// macOS-specific screenshot function that saves the screenshot to the provided filename.
void MacScreenshot(const char* filename);
#endif

#ifdef __linux__
// Linux-specific screenshot function that saves the screenshot to the provided filename.
void LinuxScreenshot(const char* filename);
#endif

// General wrapper that selects the correct platform-specific screenshot function.
void SaveScreenshot();

#endif // SCREENSHOT_UTIL_H