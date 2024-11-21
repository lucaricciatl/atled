#ifndef SCRIPTCOMPONENT_HPP
#define SCRIPTCOMPONENT_HPP

#include "Component.hpp"

class ScriptComponent : public Component {
public:
  ScriptComponent(Entity *owner);

  void OnStart() override;
  void OnUpdate(float deltaTime) override;
  void OnDraw() override;
};

#endif // SCRIPTCOMPONENT_HPP
