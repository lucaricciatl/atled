#ifndef MATERIAL_FACTORY_HPP
#define MATERIAL_FACTORY_HPP

#include <string>
#include <memory>

// Base class for materials.
class Material {
public:
    Material() = default;
    virtual ~Material() = default;

    // Pure virtual function that derived classes must implement.
    virtual std::string getInfo() const = 0;
};

// A concrete implementation of Material.
class ConcreteMaterial : public Material {
public:
    // Constructor accepting a name for the material.
    explicit ConcreteMaterial(const std::string& name);

    // Override getInfo to return material information.
    std::string getInfo() const override;

private:
    std::string name_;
};

// MaterialFactory class responsible for creating Material objects.
class MaterialFactory {
public:
    MaterialFactory() = default;
    ~MaterialFactory() = default;

    // Factory method that creates a Material based on the given type.
    // Returns a unique pointer to a Material.
    static std::unique_ptr<Material> createMaterial(const std::string& type, const std::string& name);
};

#endif // MATERIAL_FACTORY_HPP
