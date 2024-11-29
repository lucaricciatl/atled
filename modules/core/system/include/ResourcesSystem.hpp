#ifndef RESOURCE_SYSTEM_HPP
#define RESOURCE_SYSTEM_HPP

#include "System.hpp"
#include "ResourceManager.hpp"
#include <memory>
#include <vector>
#include <string>

using namespace resources;

class ResourceSystem : public System {
public:
    ResourceSystem(ResourceManager* resourceMgr);
    ~ResourceSystem() override = default;

    void Init() override;
    void Update(float deltaTime) override;
    void Shutdown() override;

    // Methods for resource management
    void LoadResource(const std::string& resourceName, const std::string& resourcePath);
    void UnloadResource(const std::string& resourceName);

    // Methods for managing resource search paths
    void AddSearchPath(const std::string& path);
    void RemoveSearchPath(const std::string& path);
    const std::vector<std::string>& GetSearchPaths() const;

private:
    std::shared_ptr<ResourceManager> resourceManager;
    std::vector<std::string> searchPaths; // List of resource search paths
};

#endif // RESOURCE_SYSTEM_HPP
