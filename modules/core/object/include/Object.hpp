#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <vector>
#include <memory>
#include "Component.hpp"

class Object {
public:
    int id;
    std::vector<std::shared_ptr<Component>> components;

    Object(int id);

    template<typename T>
    std::shared_ptr<T> GetComponent();

    void AddComponent(std::shared_ptr<Component> component);

    void OnStart();
    void OnUpdate(float deltaTime);
    void OnDraw();
};



#endif // GAMEOBJECT_HPP
