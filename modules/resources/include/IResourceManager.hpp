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

    virtual void Load(std::string aPath) = 0;

    virtual void Unload() = 0;

    virtual bool IsLoaded() = 0;

    virtual void UnloadAll() = 0;
};


}
#endif // IRESOURCE_MANAGER_HPP
