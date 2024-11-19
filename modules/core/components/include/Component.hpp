#ifndef COMPONENT_HPP
#define COMPONENT_HPP

class GameObject; // Forward declaration

class Component {
public:
    GameObject* owner;

    Component(GameObject* owner) : owner(owner) {}
    virtual ~Component() = default;

    virtual void OnStart() {}
    virtual void OnUpdate(float deltaTime) {}
    virtual void OnDraw() {}
};

#endif // COMPONENT_HPP
