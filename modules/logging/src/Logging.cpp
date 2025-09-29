#include "Logging.hpp"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <thread>

// Namespace for logging functions and classes
namespace logging {

// ANSI color codes for log levels
constexpr const char* ColorReset = "\033[0m";
constexpr const char* ColorInfo = "\033[32m";    // Green
constexpr const char* ColorWarning = "\033[33m"; // Yellow
constexpr const char* ColorError = "\033[31m";   // Red

// Helper function to get current date for filename
std::string Logger::GetCurrentDateForFile() const {
    auto now = std::chrono::system_clock::now();
    std::time_t nowTime = std::chrono::system_clock::to_time_t(now);
    std::tm nowTm;

    // Thread-safe localtime conversion
    #if defined(_WIN32) || defined(_WIN64)
        localtime_s(&nowTm, &nowTime);
    #else
        localtime_r(&nowTime, &nowTm);
    #endif


    std::stringstream ss;
    ss << std::put_time(&nowTm, "%Y-%m-%d");
    return ss.str();
}

// Constructor: Opens or creates the log file with the current date
Logger::Logger(const std::string& aFilename) {
    std::string date = GetCurrentDateForFile();
    std::string logFileName = date + ".log";
    
    // Open the file in append mode, creating it if it doesn't exist
    mLogFile.open(logFileName, std::ios::app);

    if (!mLogFile.is_open()) {
        std::cerr << "Failed to open log file: " << logFileName << std::endl;
    }
}

// Destructor: Closes the log file if it is open
Logger::~Logger() {
    if (mLogFile.is_open()) {
        mLogFile.close();
    }
}

// Log a message with the appropriate log level and timestamp
void Logger::Log(const std::string& aMessage, LogLevel aLevel) {
    std::string levelStr = GetLogLevelString(aLevel);
    std::string levelColor = GetLogLevelColor(aLevel);
    std::string timestamp = GetCurrentTime();

    // Write to the log file and console with color
    mLogFile << "[" << timestamp << "] [" << levelStr << "] " << aMessage << std::endl;
    std::cout << levelColor << "[" << timestamp << "] [" << levelStr << "] " << aMessage << ColorReset << std::endl;
}

// Get string representation of log level
std::string Logger::GetLogLevelString(LogLevel aLevel) const {
    switch (aLevel) {
        case LogLevel::Info: return "INFO";
        case LogLevel::Warning: return "WARNING";
        case LogLevel::Error: return "ERROR";
        default: return "UNKNOWN";
    }
}

// Get the current timestamp in a human-readable format
std::string Logger::GetCurrentTime() const {
    auto now = std::chrono::system_clock::now();
    std::time_t nowTime = std::chrono::system_clock::to_time_t(now);
    std::tm nowTm;
    #if defined(_WIN32) || defined(_WIN64)
        localtime_s(&nowTm, &nowTime);
    #else
        localtime_r(&nowTime, &nowTm);
    #endif

    std::stringstream ss;
    ss << std::put_time(&nowTm, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

// Get color representation of log level
std::string Logger::GetLogLevelColor(LogLevel aLevel) const {
    switch (aLevel) {
        case LogLevel::Info: return ColorInfo;
        case LogLevel::Warning: return ColorWarning;
        case LogLevel::Error: return ColorError;
        default: return ColorReset;
    }
}

} // namespace logging
