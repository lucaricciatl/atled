#ifndef IRESOURCE_MANAGER_HPP
#define IRESOURCE_MANAGER_HPP

#include <string>
#include <memory>
#include <unordered_map>
#include "Resouce.hpp"
namespace resources {

enum class ResourceManagerType {
    Invalid,
    Default,
    Raylib
};

class IResourceManager {
public:
    virtual ~IResourceManager() = default;

    virtual std::shared_ptr<void> Load(ResourceType type, const std::string& fileName) = 0;

    virtual void Unload(ResourceType type, const std::string& fileName) = 0;

    virtual bool IsLoaded(ResourceType type, const std::string& fileName) const = 0;

    virtual void UnloadAll() = 0;
};

}
#endif // IRESOURCE_MANAGER_HPP
