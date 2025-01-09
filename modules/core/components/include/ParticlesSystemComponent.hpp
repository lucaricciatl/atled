#ifndef PARTICLESSYSTEMCOMPONENT_HPP
#define PARTICLESSYSTEMCOMPONENT_HPP

#include <memory>  // Added for std::shared_ptr

#include "Action.hpp"  // Fixed include (correct path or filename)
#include "Component.hpp"
#include "FrameComponent.hpp"
#include "PhysicsManager.hpp"
#include "RigidBody.hpp"
#include "ServiceProvider.hpp"
#include "ShapeComponent.hpp"

class ParticlesSystemComponent : public Component {
   public:
    ParticlesSystemComponent(Entity* owner, std::shared_ptr<ServiceProvider> serviceProvider)
        : Component(owner),  // Call base class constructor
          physicsManager(serviceProvider->GetPhysicsManager()),
          mFrame(owner->GetComponent<FrameComponent>()->GetFrame()) {}

    void SetNumberOfParticles(int numParticles);
    void SetParticleStartSize(float size);
    void SetParticleEndSize(float size);
    void SetParticleLifetime(float lifetime);
    void SetParticleDirection(math::Vector3 direction);
    void SetParticleSpread(float spread);
    void SetParticleGravity(math::Vector3 gravity);
    void SetParticlesCollision(bool collision);

    void OnAction(Action action, bool activated);
    void Update(double deltaTime);

   private:
    std::shared_ptr<physics::PhysicsManager> physicsManager;
    std::shared_ptr<physics::Frame> mFrame;

    std::vector<physics::RigidBody> particles;

    int numParticles;
    float StartSize;
    float EndSize;
    float lifetime;
    float spread;
    math::Vector3 gravity;
    math::Vector3 position;
    bool collision;
};

#endif  // PARTICLESSYSTEMCOMPONENT_HPP
