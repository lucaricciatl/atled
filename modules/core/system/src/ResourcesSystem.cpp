#include "ResourcesSystem.hpp"
#include <iostream> // For debug/logging purposes

ResourceSystem::ResourceSystem(ResourceManager* resourceMgr)
    : resourceManager(std::shared_ptr<ResourceManager>(resourceMgr)) {}

void ResourceSystem::Init() {
    // Initialize system (e.g., load default search paths if required)
}

void ResourceSystem::Update(float deltaTime) {
    // Update logic, if any, for the resource system
}

void ResourceSystem::Shutdown() {
    // Cleanup resources and shutdown
}

void ResourceSystem::LoadResource(const std::string& resourceName, const std::string& resourcePath) {
    // Logic to load the resource
}

void ResourceSystem::UnloadResource(const std::string& resourceName) {
    // Logic to unload the resource
}

void ResourceSystem::AddSearchPath(const std::string& path) {
    searchPaths.push_back(path);
}

void ResourceSystem::RemoveSearchPath(const std::string& path) {
    searchPaths.erase(std::remove(searchPaths.begin(), searchPaths.end(), path), searchPaths.end());
}

const std::vector<std::string>& ResourceSystem::GetSearchPaths() const {
    return searchPaths;
}

