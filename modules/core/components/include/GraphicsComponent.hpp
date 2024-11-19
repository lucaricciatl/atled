#ifndef GRAPHICSCOMPONENT_HPP
#define GRAPHICSCOMPONENT_HPP

#include "Component.hpp"


class GraphicsComponent : public Component {
public:
  GraphicsComponent(Object *owner);

  void OnDraw() override;
};

#endif // GRAPHICSCOMPONENT_HPP
