#pragma once

#include <memory>
#include "ResourceManager.hpp"

namespace resources {

class ResourceManagerBuilder {
public:
    ResourceManagerBuilder() = default;

    // Configure the type of ResourceManager
    ResourceManagerBuilder& SetType(ResourceManagerType type);

    // Build method to create a ResourceManager instance
    std::unique_ptr<ResourceManager> Build();

private:
    ResourceManagerType managerType = ResourceManagerType::Invalid;
};

} // namespace resources
