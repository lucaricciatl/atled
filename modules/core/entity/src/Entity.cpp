#include "Entity.hpp"
#include <stdexcept>
#include <functional>
#include <Position.hpp>
#include <Quaternion.hpp>
#include <FrameComponent.hpp>

// Constructor
Entity::Entity() : mFrame(std::make_shared<Frame>()) {
    
};

// Destructor
Entity::~Entity() {
    // Clean up hierarchy
    for (auto child : children) {
        child->SetParent(nullptr);
    }
    if (parent) {
        parent->RemoveChild(this);
    }
}

void Entity::Update(double deltaTime) {
        // Update all components
        for (auto& [type, component] : components) {
            if (component) {
                component->Update(deltaTime); // Call the component's Update method
            }
        }

        // Optionally update children entities
        for (auto* child : children) {
            if (child) {
                child->Update(deltaTime); // Recursively update child entities
            }
        }
};

void Entity::SetServiceProvider(std::shared_ptr<ServiceProvider> aServiceProvider) {
    mServiceProvider = aServiceProvider;
};

// Set the parent entity
void Entity::SetParent(Entity* newParent) {
    if (newParent == this) {
        throw std::logic_error("An entity cannot be its own parent.");
    }
    if (parent == newParent) {
        return; // No change
    }

    Entity* oldParent = parent;
    if (parent) {
        parent->RemoveChild(this);
    }
    parent = newParent;
    if (parent) {
        parent->AddChild(this);
    }

    OnParentChanged(oldParent, newParent);
}

// Get the parent entity
Entity* Entity::GetParent() const {
    return parent;
}

// Add a child entity
void Entity::AddChild(Entity* child) {
    if (child == this) {
        throw std::logic_error("An entity cannot be its own child.");
    }
    if (std::find(children.begin(), children.end(), child) != children.end()) {
        return; // Already a child
    }
    children.push_back(child);
    child->parent = this;

    OnChildAdded(child);
}

// Remove a child entity
void Entity::RemoveChild(Entity* child) {
    auto it = std::find(children.begin(), children.end(), child);
    if (it != children.end()) {
        children.erase(it);
        child->parent = nullptr;

        OnChildRemoved(child);
    }
}

// Get the list of children
const std::vector<Entity*>& Entity::GetChildren() const {
    return children;
}

// Traverse the hierarchy
void Entity::TraverseHierarchy(const std::function<void(Entity*)>& callback) {
    callback(this);
    for (auto child : children) {
        child->TraverseHierarchy(callback);
    }
}

// Hook: Called when the parent changes
void Entity::OnParentChanged(Entity* oldParent, Entity* newParent) {
    // Override to implement custom behavior
}

// Hook: Called when a child is added
void Entity::OnChildAdded(Entity* child) {
    // Override to implement custom behavior
}

// Hook: Called when a child is removed
void Entity::OnChildRemoved(Entity* child) {
    // Override to implement custom behavior
}


