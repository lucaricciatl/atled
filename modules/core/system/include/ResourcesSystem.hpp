#ifndef RESOURCE_SYSTEM_HPP
#define RESOURCE_SYSTEM_HPP

#include <memory>
#include <string>
#include <vector>
#include "nlohmann/json.hpp"
#include <fstream>
#include "ResourceManager.hpp"
#include "System.hpp"
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
    void LoadResources();
    void UnloadResources();

   private:
    void LoadTextures();
    void LoadSound();
    void LoadShaders();
    void LoadAssets();

    std::string ResPath = "/resources";
    std::shared_ptr<ResourceManager> resourceManager;
    std::vector<std::string> searchPaths;  // List of resource search paths
};

#endif  // RESOURCE_SYSTEM_HPP
