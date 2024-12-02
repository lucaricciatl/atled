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
    ResourceManager();
    ~ResourceManager() override;

    void Load(std::string aPath) override;

    void Unload() override;

    bool IsLoaded() override;

    void UnloadAll() override;

private:

};

}
#endif // RESOURCE_MANAGER_HPP
