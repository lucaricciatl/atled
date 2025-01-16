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
#include <CoreEngine.hpp>

class ParticleComponent : public Component {
   public:
    ParticleComponent(Entity* owner, std::shared_ptr<ServiceProvider> serviceProvider, float startSize = 0.01,
                      float EndSize = 0.01, float lifetime = 1.0f, bool collision = false)
        : Component(owner),  // Call base class constructor
          physicsManager(serviceProvider->GetPhysicsManager()),
          mFrame(owner->GetComponent<FrameComponent>()->GetFrame()) {
          auto shape = owner->AddComponent<ShapeComponent>();
          shape->SetModel<Sphere>(0.8, math::Vector3(0, 0, 0), 20, 20, getColor("Elegant Dark Blue Gray"));
          }

    void Update(double deltaTime) override;

   private:
    std::shared_ptr<physics::PhysicsManager> physicsManager;
    std::shared_ptr<physics::RigidBody> rigidBody;
    std::shared_ptr<physics::Frame> mFrame;
    float StartSize;
    float EndSize;
    float lifetime;
    float life;
    bool collision;
};

class ParticlesSystemComponent : public Component {
   public:
    ParticlesSystemComponent(Entity* owner, std::shared_ptr<ServiceProvider> serviceProvider, int numParticles = 1000,
                             float startSize = 0.01, float EndSize = 0.01, float lifetime = 1.0f,
                             bool collision = false)
        : Component(owner),  // Call base class constructor
          physicsManager(serviceProvider->GetPhysicsManager()),
          mFrame(owner->GetComponent<FrameComponent>()->GetFrame()),
          numParticles(numParticles) {
        // Generate particles based on the specified parameters
        for (int i = 0; i < numParticles; i++) {
            owner->AddComponent<ParticleComponent>(startSize, EndSize, lifetime, collision);
        }
    }

    void SetNumberOfParticles(int numParticles);
    void SetParticleStartSize(float size);
    void SetParticleEndSize(float size);
    void SetParticleLifetime(float lifetime);
    void SetParticleGravity(math::Vector3 gravity);
    void SetParticlesCollision(bool collision);


   private:
    std::shared_ptr<physics::PhysicsManager> physicsManager;
    std::shared_ptr<physics::Frame> mFrame;

    void AddParticles(int numParticles);
    void RemoveParticles(int numParticles);

    std::vector<Entity*> particles;

    int numParticles;
    float spread;
    math::Vector3 gravity;
    math::Vector3 position;
};

#endif  // PARTICLESSYSTEMCOMPONENT_HPP
