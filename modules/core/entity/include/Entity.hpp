#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <vector>
#include <memory>
#include <algorithm>
#include <functional>

class Entity {
private:
    Entity* parent = nullptr; // Pointer to the parent entity
    std::vector<Entity*> children; // List of child entities

public:
    // Constructor and Destructor
    Entity();
    virtual ~Entity();

    // Parent-Child Management
    void SetParent(Entity* newParent);
    Entity* GetParent() const;

    void AddChild(Entity* child);
    void RemoveChild(Entity* child);
    const std::vector<Entity*>& GetChildren() const;

    // Hierarchy Traversal
    void TraverseHierarchy(const std::function<void(Entity*)>& callback);

protected:
    // Event hooks (override in derived classes if needed)
    virtual void OnParentChanged(Entity* oldParent, Entity* newParent);
    virtual void OnChildAdded(Entity* child);
    virtual void OnChildRemoved(Entity* child);
};

#endif // ENTITY_HPP
