#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <vector>
#include <memory>
#include <algorithm>
#include <functional>
#include <Component.hpp>
#include <typeindex>
#include <ServiceProvider.hpp>
class Component;


class Entity {
private:
    Entity* parent = nullptr; // Pointer to the parent entity
    std::vector<Entity*> children; // List of child entities

public:
    // Constructor and Destructor
    Entity();
    virtual ~Entity();

    
    void Update(double deltaTime);

    void SetServiceProvider(std::shared_ptr<ServiceProvider> aServiceProvider);

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
    std::unordered_map<std::type_index, std::shared_ptr<Component>> components;
    std::shared_ptr<ServiceProvider> mServiceProvider;

};


// Add a component to the entity
template <typename ComponentType, typename... Args>
void Entity::AddComponent(Args&&... args) {
    static_assert(std::is_base_of<Component, ComponentType>::value,
        "ComponentType must derive from Component");

    // Automatically pass `this` (the owning entity) to the component constructor
    auto component = std::make_shared<ComponentType>(this, std::forward<Args>(args)...);
    components[typeid(ComponentType)] = component;
}

// Remove a component from the entity
template <typename ComponentType>
void Entity::RemoveComponent() {
    static_assert(std::is_base_of<Component, ComponentType>::value,
        "ComponentType must derive from Component");

    auto it = components.find(typeid(ComponentType));
    if (it != components.end()) {
        components.erase(it);
    }
}

// Get a component from the entity
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
