// FileSystem.cpp

#include "FileSystemManager.hpp"
#include <regex>
#include <iostream>

FileSystem::FileSystem() {
    // Constructor
}

FileSystem::~FileSystem() {
    // Destructor
}

std::filesystem::path FileSystem::getCurrentPath() const {
    return std::filesystem::current_path();
}

void FileSystem::setCurrentPath(const std::filesystem::path& path) {
    std::filesystem::current_path(path);
}

std::vector<std::filesystem::path> FileSystem::searchFiles(
    const std::filesystem::path& directory,
    const std::string& pattern) const {

    std::vector<std::filesystem::path> results;

    if (!std::filesystem::exists(directory) || !std::filesystem::is_directory(directory)) {
        return results;
    }

    std::regex regexPattern(pattern);

    for (const auto& entry : std::filesystem::directory_iterator(directory)) {
        if (std::filesystem::is_regular_file(entry.status())) {
            if (std::regex_match(entry.path().filename().string(), regexPattern)) {
                results.push_back(entry.path());
            }
        }
    }

    return results;
}

std::vector<std::filesystem::path> FileSystem::searchFilesRecursive(
    const std::filesystem::path& directory,
    const std::string& pattern) const {

    std::vector<std::filesystem::path> results;

    if (!std::filesystem::exists(directory) || !std::filesystem::is_directory(directory)) {
        return results;
    }

    std::regex regexPattern(pattern);

    for (const auto& entry : std::filesystem::recursive_directory_iterator(directory)) {
        if (std::filesystem::is_regular_file(entry.status())) {
            if (std::regex_match(entry.path().filename().string(), regexPattern)) {
                results.push_back(entry.path());
            }
        }
    }

    return results;
}

bool FileSystem::fileExists(const std::filesystem::path& filePath) const {
    return std::filesystem::exists(filePath);
}

void FileSystem::copyFile(
    const std::filesystem::path& source,
    const std::filesystem::path& destination,
    bool overwrite) const {

    std::filesystem::copy_options options = std::filesystem::copy_options::none;

    if (overwrite) {
        options |= std::filesystem::copy_options::overwrite_existing;
    } else {
        options |= std::filesystem::copy_options::skip_existing;
    }

    std::filesystem::copy_file(source, destination, options);
}

std::filesystem::path FileSystem::findPath(
    const std::filesystem::path& directory,
    const std::string& filename) const {

    if (!std::filesystem::exists(directory) || !std::filesystem::is_directory(directory)) {
        return "";
    }

    for (const auto& entry : std::filesystem::directory_iterator(directory)) {
        if (entry.path().filename() == filename) {
            return entry.path();
        }
    }

    return "";
}

std::filesystem::path FileSystem::findPathRecursive(
    const std::filesystem::path& directory,
    const std::string& filename) const {

    if (!std::filesystem::exists(directory) || !std::filesystem::is_directory(directory)) {
        return "";
    }

    for (const auto& entry : std::filesystem::recursive_directory_iterator(directory)) {
        if (entry.path().filename() == filename) {
            return entry.path();
        }
    }

    return "";
}
