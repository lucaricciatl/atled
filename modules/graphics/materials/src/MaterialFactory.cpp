#include "MaterialFactory.hpp"
#include <memory>  // Ensure this is included for std::make_unique

// Implementation for ConcreteMaterial's constructor.
ConcreteMaterial::ConcreteMaterial(const std::string& name)
    : name_(name) {}

// Implementation for ConcreteMaterial's getInfo method.
std::string ConcreteMaterial::getInfo() const {
    return "ConcreteMaterial: " + name_;
}

// Implementation for MaterialFactory's createMaterial method.
std::unique_ptr<Material> MaterialFactory::createMaterial(const std::string& type, const std::string& name) {
    // Check the material type and instantiate the appropriate material.
    if (type == "concrete") {
        return std::make_unique<ConcreteMaterial>(name);
    } else {
        // For unknown types, you might want to handle this differently.
        // Here we return a ConcreteMaterial for demonstration.
        return std::make_unique<ConcreteMaterial>(name);
    }
}
