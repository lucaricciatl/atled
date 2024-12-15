#ifndef PHYSICSCOMPONENT_HPP
#define PHYSICSCOMPONENT_HPP

#include "Component.hpp"
#include "Action.hpp"  // Fixed include (correct path or filename)
#include "RigidBody.hpp"
#include <memory> // Added for std::shared_ptr
#include "FrameComponent.hpp"
#include "PhysicsManager.hpp"
#include "ServiceProvider.hpp"
#include "ShapeComponent.hpp"

class RigidBodyComponent : public Component {
public:
    RigidBodyComponent(Entity* owner, std::shared_ptr<ServiceProvider> serviceProvider)
        : Component(owner), // Call base class constructor
        physicsManager(serviceProvider->GetPhysicsManager()), // Initialize PhysicsManager
        rigidBody(std::make_shared<RigidBody>()) { // Create RigidBody instance
        owner->GetComponent<ShapeComponent>();
        // Retrieve the FrameComponent and set the frame
        mFrame = owner->GetComponent<FrameComponent>()->GetFrame();

        // Register the rigid body with the PhysicsManager
        physicsManager->AddBody(std::static_pointer_cast<Body>(rigidBody));
    }

    void OnAction(Action action, bool activated);
    void Update(double deltaTime);

    void SetCollidable(bool aCollidable);
    void SetStatic(bool aStatic);
    void SetUseGravity(bool aGravity);

    bool IsCollidable();
    bool IsStatic();

private:
    std::shared_ptr<physics::PhysicsManager> physicsManager;
    std::shared_ptr<physics::RigidBody> rigidBody;
    std::shared_ptr<physics::Frame> mFrame;
};

#endif // PHYSICSCOMPONENT_HPP
