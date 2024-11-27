#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <Component.hpp>
#include <typeindex>
#include <memory>
#include <vector>
#include <unordered_map>
#include <functional>
#include <cassert> // For runtime checks (optional)
#include <Frame.hpp>

using namespace physics;
// Forward declaration of Component
class Component;

class ServiceProvider; // Forward declaration of ServiceProvider

class Entity {
private:
    Entity* parent = nullptr; // Pointer to the parent entity
    std::vector<Entity*> children; // List of child entities

    // Components associated with this entity
    std::unordered_map<std::type_index, std::shared_ptr<Component>> components;

    // Service provider
    std::shared_ptr<ServiceProvider> mServiceProvider;

public:
    // Constructor and Destructor
    Entity();
    virtual ~Entity();
    void Update(double deltaTime);
    void SetServiceProvider(std::shared_ptr<ServiceProvider> aServiceProvider);
    void SetDefaultState();

    // Parent-Child Management
    void SetParent(Entity* newParent);
    Entity* GetParent() const;

    void AddChild(Entity* child);
    void RemoveChild(Entity* child);
    const std::vector<Entity*>& GetChildren() const;

    // Hierarchy Traversal
    void TraverseHierarchy(const std::function<void(Entity*)>& callback);

    // Component Management
    template <typename ComponentType, typename... Args>
    void AddComponent(Args&&... args);

    template <typename ComponentType>
    void RemoveComponent();

    template <typename ComponentType>
    std::shared_ptr<ComponentType> GetComponent() const;

protected:
    // Event hooks (override in derived classes if needed)
    virtual void OnParentChanged(Entity* oldParent, Entity* newParent);
    virtual void OnChildAdded(Entity* child);
    virtual void OnChildRemoved(Entity* child);
};

// Definitions of template methods

template <typename ComponentType, typename... Args>
void Entity::AddComponent(Args&&... args) {
    static_assert(std::is_base_of<Component, ComponentType>::value,
        "ComponentType must derive from Component");

    // Create and store the component, passing `this` and any additional arguments
    auto component = std::make_shared<ComponentType>(this, mServiceProvider , std::forward<Args>(args)...);
    components[typeid(ComponentType)] = component;
}

template <typename ComponentType>
void Entity::RemoveComponent() {
    static_assert(std::is_base_of<Component, ComponentType>::value,
        "ComponentType must derive from Component");

    auto it = components.find(typeid(ComponentType));
    if (it != components.end()) {
        components.erase(it);
    }
}

template <typename ComponentType>
std::shared_ptr<ComponentType> Entity::GetComponent() const {
    static_assert(std::is_base_of<Component, ComponentType>::value,
        "ComponentType must derive from Component");

    auto it = components.find(typeid(ComponentType));
    if (it != components.end()) {
        return std::static_pointer_cast<ComponentType>(it->second);
    }

    return nullptr; // Component not found
}


#endif // ENTITY_HPP
