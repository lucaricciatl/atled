#ifndef PHYSICSCOMPONENT_HPP
#define PHYSICSCOMPONENT_HPP

#include "Component.hpp"
#include "Action.hpp"  // Fixed include (correct path or filename)
#include "RigidBody.hpp"
#include <memory> // Added for std::shared_ptr
#include "FrameComponent.hpp"

class RigidBodyComponent : public physics::RigidBody, public Component {
public:
    RigidBodyComponent(Entity* owner, std::shared_ptr<ServiceProvider> serviceProvider)
        : Component(owner), physics::RigidBody() {
        mFrame = owner->GetComponent<FrameComponent>()->GetFrame();
    }

    void OnAction(Action action, bool activated);
    void Update(double deltaTime);

private:


};

#endif // PHYSICSCOMPONENT_HPP
