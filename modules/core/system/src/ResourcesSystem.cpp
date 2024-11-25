#include "ResourcesSystem.hpp"
#include <iostream> // For debug/logging purposes

ResourceSystem::ResourceSystem(ResourceManager* resourceMgr)
    : resourceManager(std::move(resourceMgr)) {}

void ResourceSystem::Init() {
    // Initialize the ResourceSystem
    std::cout << "ResourceSystem initialized." << std::endl;
}

void ResourceSystem::Update(float deltaTime) {
    // Periodic updates related to resources (e.g., cleanup or async loading)

}

void ResourceSystem::Shutdown() {
    // Free all resources and prepare for system shutdown
    std::cout << "ResourceSystem shutting down..." << std::endl;
    resourceManager->UnloadAll();
}

void ResourceSystem::LoadResource(const std::string& resourceName, const std::string& ResourcePath) {
    // Delegate resource loading to ResourceManager
    std::cout << "Loading resource: " << resourceName << std::endl;

}

void ResourceSystem::UnloadResource(const std::string& resourceName) {
    // Delegate resource unloading to ResourceManager
    std::cout << "Unloading resource: " << resourceName << std::endl;

}
