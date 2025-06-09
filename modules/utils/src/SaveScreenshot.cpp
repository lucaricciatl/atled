#include <cstdio>  // For std::strftime
#include <ctime>
#include <iostream>

#include "screenshot_util.hpp"
#ifdef _WIN32
#include <windows.h>
#else
#include <limits.h>
#include <unistd.h>
#endif
// Generate a filename (e.g., "screenshot_YYYYMMDD_HHMMSS.png")
std::string GetTimeStamp() {
    char buffer[64];
    std::time_t now = std::time(nullptr);
    std::strftime(buffer, sizeof(buffer), "screenshot_%Y%m%d_%H%M%S.png", std::localtime(&now));
    return std::string(buffer);
}
// Get the current working directory as an absolute path
std::string GetCurrentWorkingDirectory() {
#ifdef _WIN32
    char buffer[MAX_PATH];
    DWORD length = GetCurrentDirectoryA(MAX_PATH, buffer);
    if (length == 0 || length > MAX_PATH) {
        return std::string("");
    }
    return std::string(buffer);
#else
    char buffer[PATH_MAX];
    if (getcwd(buffer, PATH_MAX) != nullptr) {
        return std::string(buffer);
    } else {
        return std::string("");
    }
#endif
}
void SaveScreenshot() {
    // Generate the timestamp only once.
    std::string ts = GetTimeStamp();
    // Get current working directory.
    std::string cwd = GetCurrentWorkingDirectory();
    if (cwd.empty()) {
        std::cerr << "Unable to retrieve current working directory." << std::endl;
        return;
    }

    // Build the full path by appending the filename to the CWD.
    std::string fullPath = cwd;
#ifdef _WIN32
    // Windows usually uses backslashes, but it's safe to use forward slashes too.
    if (fullPath.back() != '\\' && fullPath.back() != '/') {
        fullPath += "\\";
    }
#else
    if (fullPath.back() != '/') {
        fullPath += "/";
    }
#endif
    fullPath += ts;
    // Print the absolute path where the screenshot will be saved.
    std::cout << "Saving screenshot to: " << fullPath << std::endl;
#ifdef _WIN32
    WinScreenshot(fullPath.c_str());
#elif defined(__APPLE__)
    MacScreenshot(fullPath.c_str());
#elif defined(__linux__)
    LinuxScreenshot(fullPath.c_str());
#else
    std::cerr << "Screenshot functionality is not implemented for this platform." << std::endl;
#endif
}