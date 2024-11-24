#include "ResourceManager.hpp"
#include "Resouce.hpp"
#include <stdexcept>

using namespace resources;

ResourceManager::ResourceManager() = default;

ResourceManager::~ResourceManager() {
    UnloadAll();
}

void ResourceManager::RegisterLoader(ResourceType type, LoaderFunc loader) {
    loaders[type] = loader;
}

std::shared_ptr<void> ResourceManager::Load(ResourceType type, const std::string& fileName) {
    auto loaderIt = loaders.find(type);
    if (loaderIt == loaders.end()) {
        throw std::runtime_error("No loader registered for resource type.");
    }

    auto resourceKey = GenerateKey(type, fileName);
    auto resourceIt = resources.find(resourceKey);
    if (resourceIt != resources.end()) {
        return resourceIt->second;
    }

    auto resource = loaderIt->second(fileName);
    resources[resourceKey] = resource;
    return resource;
}

void ResourceManager::Unload(ResourceType type, const std::string& fileName) {
    auto resourceKey = GenerateKey(type, fileName);
    resources.erase(resourceKey);
}

bool ResourceManager::IsLoaded(ResourceType type, const std::string& fileName) const {
    auto resourceKey = GenerateKey(type, fileName);
    return resources.find(resourceKey) != resources.end();
}

void ResourceManager::UnloadAll() {
    resources.clear();
}

std::string ResourceManager::GenerateKey(ResourceType type, const std::string& fileName) const {
    return std::to_string(static_cast<int>(type)) + ":" + fileName;
}
