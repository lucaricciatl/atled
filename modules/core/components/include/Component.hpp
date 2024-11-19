#ifndef COMPONENT_HPP
#define COMPONENT_HPP

class Object; // Forward declaration

class Component {
public:
    Object* owner;

    Component(Object* owner) : owner(owner) {}
    virtual ~Component() = default;

    virtual void OnStart() {}
    virtual void OnUpdate(float deltaTime) {}
    virtual void OnDraw() {}
};

#endif // COMPONENT_HPP
