#ifndef SCRIPTCOMPONENT_HPP
#define SCRIPTCOMPONENT_HPP

#include "Component.hpp"
#include "Script.hpp" // Supponendo che tu abbia una classe Script o utilizzi un motore di scripting

class ScriptComponent : public Component {
public:
    Script* script;

    ScriptComponent(GameObject* owner, Script* script);

    void OnStart() override;
    void OnUpdate(float deltaTime) override;
    void OnDraw() override;
};

#endif // SCRIPTCOMPONENT_HPP
