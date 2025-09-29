#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

namespace logging {

enum class LogLevel {
    Info,
    Warning,
    Error
};

class Logger {
public:
    Logger(const std::string& aFilename);
    ~Logger();

    void Log(const std::string& aMessage, LogLevel aLevel);

private:
    std::ofstream mLogFile;

    std::string GetCurrentDateForFile() const;
    std::string GetLogLevelString(LogLevel aLevel) const;
    std::string GetCurrentTime() const;
    std::string GetLogLevelColor(LogLevel aLevel) const;
};

} // namespace logging
