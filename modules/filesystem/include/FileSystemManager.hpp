// FileSystem.hpp

#ifndef FILESYSTEM_HPP
#define FILESYSTEM_HPP

#include <string>
#include <vector>
#include <filesystem>

class FileSystem {
public:
    FileSystem();
    ~FileSystem();

    // Get the current working directory
    std::filesystem::path getCurrentPath() const;

    // Set the current working directory
    void setCurrentPath(const std::filesystem::path& path);

    // Search for files matching a pattern in a directory (non-recursive)
    std::vector<std::filesystem::path> searchFiles(
        const std::filesystem::path& directory,
        const std::string& pattern) const;

    // Search for files matching a pattern in a directory (recursive)
    std::vector<std::filesystem::path> searchFilesRecursive(
        const std::filesystem::path& directory,
        const std::string& pattern) const;

    // Check if a file exists
    bool fileExists(const std::filesystem::path& filePath) const;

    // Copy a file to a new location
    void copyFile(
        const std::filesystem::path& source,
        const std::filesystem::path& destination,
        bool overwrite = false) const;

    // Find a specific file in a directory (non-recursive)
    std::filesystem::path findPath(
        const std::filesystem::path& directory,
        const std::string& filename) const;

    // Find a specific file in a directory (recursive)
    std::filesystem::path findPathRecursive(
        const std::filesystem::path& directory,
        const std::string& filename) const;

    // Additional filesystem operations can be added here
    void createDirectory(const std::filesystem::path& dirPath) const;
};

#endif // FILESYSTEM_HPP
