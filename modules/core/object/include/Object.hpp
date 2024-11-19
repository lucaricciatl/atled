#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <vector>
#include <memory>
#include "Component.hpp"

class GameObject {
public:
    int id;
    std::vector<std::shared_ptr<Component>> components;

    GameObject(int id);

    template<typename T>
    std::shared_ptr<T> GetComponent();

    void AddComponent(std::shared_ptr<Component> component);

    void OnStart();
    void OnUpdate(float deltaTime);
    void OnDraw();
};

#include "GameObject.inl" // Implementazioni dei template

#endif // GAMEOBJECT_HPP
