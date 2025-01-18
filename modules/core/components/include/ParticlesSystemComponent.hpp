#ifndef PARTICLESSYSTEMCOMPONENT_HPP
#define PARTICLESSYSTEMCOMPONENT_HPP

#include <CoreEngine.hpp>
#include <memory>  // Added for std::shared_ptr

#include "Action.hpp"  // Fixed include (correct path or filename)
#include "Component.hpp"
#include "FrameComponent.hpp"
#include "PhysicsManager.hpp"
#include "RigidBody.hpp"
#include "ServiceProvider.hpp"
#include "ShapeComponent.hpp"
#include <random>


namespace {
  constexpr int defaultmeshring = 3;
  constexpr int defaultmeshslice = 3;
}
class ParticleComponent : public Component {
   public:
    ParticleComponent(Entity* owner, std::shared_ptr<ServiceProvider> serviceProvider, float startSize = 0.01,
                      float endSize = 0.01, float lifetime = 1.0f, bool collision = false, bool gravity = false,
                      float speed = 0, const graphics::Color& color = getColor("Elegant Soft Gray"))
        : Component(owner),  // Call base class constructor
          physicsManager(serviceProvider->GetPhysicsManager()),
          mFrame(owner->GetComponent<FrameComponent>()->GetFrame()),
          mSpeed(speed),
          mStartSize(startSize),
          mEndSize(endSize),
          mLifetime(lifetime),
          mCollisionEnabled(collision)
    {
        // Create and configure the shape component
        auto shape = owner->AddComponent<ShapeComponent>();
        shape->SetModel<Sphere>(startSize, math::Vector3(0, 0, 0), defaultmeshring, defaultmeshslice, color);
    }

    void Update(double deltaTime) override;
    void SetSpeed(const float speed);

   private:
    std::shared_ptr<physics::PhysicsManager> physicsManager;
    std::shared_ptr<physics::RigidBody> rigidBody;
    std::shared_ptr<physics::Frame> mFrame;
    std::shared_ptr<ShapeComponent> shape;
    float mStartSize;
    float mEndSize;
    float mLifetime;
    float life;
    bool mCollisionEnabled;
    float mSpeed;

};

class ParticlesSystemComponent : public Component {
   public:
    ParticlesSystemComponent(Entity* owner, std::shared_ptr<ServiceProvider> serviceProvider, int numParticles = 1000,
                             float startSize = 0.01, float EndSize = 0.01, float lifetime = 5.0f,
                             bool collision = false, float speed = 0)
        : Component(owner),  // Call base class constructor
          physicsManager(serviceProvider->GetPhysicsManager()),
          mFrame(owner->GetComponent<FrameComponent>()->GetFrame()),
          numParticles(numParticles) {

        for (int i = 0; i < numParticles; i++) {

        }
    }

    void SetNumberOfParticles(int numParticles);
    void SetParticleStartSize(float size);
    void SetParticleEndSize(float size);
    void SetParticleLifetime(float lifetime);
    void SetParticleGravity(math::Vector3 gravity);
    void SetParticlesCollision(bool collision);

    void SetSpeed(float aSpeed);
    void SetEmissionRate(float aRate);

   private:
    std::shared_ptr<physics::PhysicsManager> physicsManager;
    std::shared_ptr<physics::Frame> mFrame;
    std::vector<std::shared_ptr<ParticleComponent>> mParticles;
    std::vector<Entity*> particles;
    void AddParticles(int numParticles);
    void RemoveParticles(int numParticles);

    int numParticles;
    float mSpeed;
    float mRate;
    
    math::Vector3 gravity;
    math::Vector3 position;
};

#endif  // PARTICLESSYSTEMCOMPONENT_HPP
