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

class ParticlesSystemComponent : public Component {
public:
    ParticlesSystemComponent(Entity* owner, std::shared_ptr<ServiceProvider> serviceProvider)
        : Component(owner), // Call base class constructor
        physicsManager(serviceProvider->GetPhysicsManager()),
        mFrame(owner->GetComponent<FrameComponent>()->GetFrame()) {
    }

   void SetNumberOfParticles(int numParticles);
   void SetParticleSize(float size);
   void SetParticleSpeed(float speed);
   void SetParticleLifetime(float lifetime);
   void SetParticleDirection(math::Vector3 direction);
   void SetParticleSpread(float spread);
   void SetParticleGravity(math::Vector3 gravity);
   void SetParticleGeneratorPosition(math::Vector3 position);
   void SetParticlesCollision(bool collision);
   void SetRandomness(float randomness);

    void OnAction(Action action, bool activated);
    void Update(double deltaTime);


private:
    std::shared_ptr<physics::PhysicsManager> physicsManager;
    std::shared_ptr<physics::Frame> mFrame;
    
    int numParticles;
    float size;
    graphics::Color color;
    float speed;
    float lifetime;
    math::Vector3 direction;
    float spread;
    math::Vector3 gravity;
    math::Vector3 position;
    bool collision;
    float randomness;

};

#endif // PHYSICSCOMPONENT_HPP
