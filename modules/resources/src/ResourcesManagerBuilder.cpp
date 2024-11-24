#include "ResourceManagerBuilder.hpp"
#include <stdexcept>
#include <iostream>

namespace resources {

ResourceManagerBuilder& ResourceManagerBuilder::SetType(ResourceManagerType type) {
    managerType = type;
    return *this;
}

std::unique_ptr<ResourceManager> ResourceManagerBuilder::Build() {
    switch (managerType) {
        case ResourceManagerType::Default:
            std::cout << "Building Default Resource Manager" << std::endl;
            return std::make_unique<ResourceManager>();
        default:
            throw std::runtime_error("Unsupported ResourceManagerType specified!");
    }
}

} // namespace resources
