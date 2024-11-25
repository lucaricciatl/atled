#ifndef RESOURCE_SYSTEM_HPP
#define RESOURCE_SYSTEM_HPP

#include "System.hpp"
#include "ResourceManager.hpp"
#include <memory>


using namespace resources;

class ResourceSystem : public System {
public:
    ResourceSystem(ResourceManager* resourceMgr);
    ~ResourceSystem() override = default;

    void Init() override;
    void Update(float deltaTime) override;
    void Shutdown() override;

    // Additional methods for resource management
    void LoadResource(const std::string& resourceName, const std::string& ResourcePath);
    void UnloadResource(const std::string& resourceName);

private:
    std::shared_ptr<ResourceManager> resourceManager;
};


#endif // RESOURCE_SYSTEM_HPP
