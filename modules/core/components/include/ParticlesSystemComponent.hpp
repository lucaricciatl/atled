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
#include <AtledEngine.hpp>

namespace {
  constexpr int defaultmeshring = 3;
  constexpr int defaultmeshslice = 3;
}
class ParticleComponent : public Component {
   public:
    ParticleComponent(Entity* owner, std::shared_ptr<ServiceProvider> serviceProvider, float startSize = 0.01,
                      float endSize = 0.01, float lifetime = 1.0f, bool collision = false, bool gravity = false,
                      float speed = 3, const graphics::Color& color = getColor("Elegant Soft Gray"))
        : Component(owner),  // Call base class constructor
          physicsManager(serviceProvider->GetPhysicsManager()),
          mFrame(owner->GetComponent<FrameComponent>()->GetFrame()),
          mSpeed(speed),
          mStartSize(startSize),
          mEndSize(endSize),
          mCollisionEnabled(collision),
          life(0)
    {
        // Create and configure the shape component
        auto shape = owner->AddComponent<ShapeComponent>();
        shape->SetModel<Sphere>(startSize, math::Vector3(0, 0, 0), defaultmeshring, defaultmeshslice, color);
        static std::random_device rd;                           // Seed for the random number engine
        static std::mt19937 gen(rd());                          // Mersenne Twister random number generator
        static std::uniform_real_distribution<> dis(0.0, 1.0);  // Random numbers in range [0.0, 1.0]
        // Set position using the generated random numbers
        // Generate random x, y, z
        xr = dis(gen);
        yr = dis(gen);
        zr = dis(gen);
        mLifetime = lifetime + dis(gen);
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
    double xr;
    double yr;
    double zr;
};

class ParticlesSystemComponent : public Component {
   public:
    ParticlesSystemComponent(Entity* owner, std::shared_ptr<ServiceProvider> serviceProvider, int numParticles = 1000,
                             float startSize = 0.1, float EndSize = 0.01, float lifetime = 5.0f,
                             bool collision = false, float speed = 0)
        : Component(owner),  // Call base class constructor
          physicsManager(serviceProvider->GetPhysicsManager()),
          mFrame(owner->GetComponent<FrameComponent>()->GetFrame()),
          numParticles(numParticles) {
        // Create and store particle entities
        auto engine = serviceProvider->GetEngine();
        mParticles.reserve(numParticles);
        for (int i = 0; i < numParticles; ++i) {
            auto particleEntity = engine->CreateEntity();
            particleEntity->AddComponent<ParticleComponent>();
            mParticles.emplace_back(particleEntity);
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
    std::vector<std::shared_ptr<Entity>> mParticles;
    void AddParticles(int numParticles);
    void RemoveParticles(int numParticles);

    int numParticles;
    float mSpeed;
    float mRate;
    
    math::Vector3 gravity;
    math::Vector3 position;
};

#endif  // PARTICLESSYSTEMCOMPONENT_HPP
