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


