#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include "IResourceManager.hpp"
#include <functional>
#include <unordered_map>
#include <memory>
#include <string>
#include "Resouce.hpp"

namespace resources {

/**
 * @brief A concrete implementation of the IResourceManager interface.
 */
class ResourceManager : public IResourceManager {
public:
    using LoaderFunc = std::function<std::shared_ptr<void>(const std::string&)>;
    using ResourceMap = std::unordered_map<std::string, std::shared_ptr<void>>;

    ResourceManager();
    ~ResourceManager() override;

    /**
     * @brief Register a loader function for a specific resource type.
     *
     * @param type The resource type.
     * @param loader The loader function for that resource type.
     */
    void RegisterLoader(ResourceType type, LoaderFunc loader);

    std::shared_ptr<void> Load(ResourceType type, const std::string& fileName) override;

    void Unload(ResourceType type, const std::string& fileName) override;

    bool IsLoaded(ResourceType type, const std::string& fileName) const override;

    void UnloadAll() override;

private:
    std::string GenerateKey(ResourceType type, const std::string& fileName) const;

    ResourceMap resources;                     ///< Map of loaded resources.
    std::unordered_map<ResourceType, LoaderFunc> loaders; ///< Map of resource loaders.
};

}
#endif // RESOURCE_MANAGER_HPP
