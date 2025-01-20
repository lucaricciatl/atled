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
    ParticleComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> aServiceProvider, float aStartSize = 0.01,
                      float aEndSize = 0.01, float aLifetime = 1.0f, bool aCollision = false, bool aGravity = false,
                      float aSpeed = 3, const graphics::Color& aColor = getColor("Elegant Soft Gray"))
        : Component(aOwner),  // Call base class constructor
          physicsManager(aServiceProvider->GetPhysicsManager()),
          mFrame(aOwner->GetComponent<FrameComponent>()->GetFrame()),
          mSpeed(aSpeed),
          mStartSize(aStartSize),
          mEndSize(aEndSize),
          mCollisionEnabled(aCollision),
          life(0) {
        // Create and configure the shape component
        auto shape = aOwner->AddComponent<ShapeComponent>();
        shape->SetModel<Sphere>(aStartSize, math::Vector3(0, 0, 0), defaultmeshring, defaultmeshslice, aColor);
        static std::random_device rd;                           // Seed for the random number engine
        static std::mt19937 gen(rd());                          // Mersenne Twister random number generator
        static std::uniform_real_distribution<> dis(0.0, 1.0);  // Random numbers in range [0.0, 1.0]
        // Set position using the generated random numbers
        // Generate random x, y, z
        xr = dis(gen);
        yr = dis(gen);
        zr = dis(gen);
        mLifetime = aLifetime + dis(gen);
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
    ParticlesSystemComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> aServiceProvider,
                             int aNumParticles = 1000, float aStartSize = 0.1, float aEndSize = 0.01,
                             float aLifetime = 5.0f, bool aCollision = false, float aSpeed = 0)
        : Component(aOwner),  // Call base class constructor
          mPhysicsManager(aServiceProvider->GetPhysicsManager()),
          mFrame(aOwner->GetComponent<FrameComponent>()->GetFrame()),
          numParticles(numParticles) {
        // Create and store particle entities
        auto engine = aServiceProvider->GetEngine();
        mParticles.reserve(numParticles);
        for (int i = 0; i < numParticles; ++i) {
            auto particleEntity = engine->CreateEntity();
            particleEntity->AddComponent<ParticleComponent>();
            mParticles.emplace_back(particleEntity);
            aOwner->AddChild(particleEntity.get());
        }
    }

    void SetNumberOfParticles(int aNumParticles);
    void SetParticleStartSize(float aSize);
    void SetParticleEndSize(float aSize);
    void SetParticleLifetime(float aLifetime);
    void SetParticleGravity(math::Vector3 aGravity);
    void SetParticlesCollision(bool aCollision);

    void SetSpeed(float aSpeed);
    void SetEmissionRate(float aRate);

   private:
    std::shared_ptr<physics::PhysicsManager> mPhysicsManager;
    std::shared_ptr<physics::Frame> mFrame;
    std::vector<std::shared_ptr<Entity>> mParticles;

    int numParticles;
    float mSpeed;
    float mRate;

    math::Vector3 mGravity;
};

#endif  // PARTICLESSYSTEMCOMPONENT_HPP
