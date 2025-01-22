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
          mLife(0) {
        // Create and configure the shape component
        auto shape = aOwner->AddComponent<ShapeComponent>();
        shape->SetModel<Sphere>(aStartSize, math::Vector3(0, 0, 0), defaultmeshring, defaultmeshslice, aColor);
        static std::random_device rd;                           // Seed for the random number engine
        static std::mt19937 gen(rd());                          // Mersenne Twister random number generator
        static std::uniform_real_distribution<> dis(-aLifetime, aLifetime);  // Random numbers in range [0.0, 1.0]
        // Set position using the generated random numbers
        // Generate random x, y, z
        xr = dis(gen);
        yr = dis(gen);
        zr = dis(gen);
        mLifetime = aLifetime + dis(gen);
    }

    void Update(double aDt) override;
    void SetSpeed(const float aSpeed);
    void SetStartSize(const float aSize);
    void SetEndSize(const float aSize);
    void SetCollision(const bool aCollision);
    void SetLifetime(const float aLifetime);

   private:
    std::shared_ptr<physics::PhysicsManager> physicsManager;
    std::shared_ptr<physics::RigidBody> rigidBody;
    std::shared_ptr<physics::Frame> mFrame;
    std::shared_ptr<ShapeComponent> shape;
    float mStartSize;
    float mEndSize;

    float mLife;
    bool mCollisionEnabled;
    float mSpeed;

    // distributions
    double xr;
    double yr;
    double zr;
    float mLifetime;
};

class ParticlesSystemComponent : public Component {
   public:
    ParticlesSystemComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> aServiceProvider,
                             int aNumParticles = 1000, float aStartSize = 0.01, float aEndSize = 0.01,
                             float aLifetime = 5.0f, bool aCollision = false, bool aGravity = false, float aSpeed = 1,
                             const graphics::Color& aColor = getColor("Elegant Soft Gray"))
        : Component(aOwner),  // Call base class constructor
          mPhysicsManager(aServiceProvider->GetPhysicsManager()),
          mFrame(aOwner->GetComponent<FrameComponent>()->GetFrame()),
          mNumParticles(aNumParticles) {
        // Create and store particle entities
        auto engine = aServiceProvider->GetEngine();
        mParticles.reserve(mNumParticles);
        for (int i = 0; i < mNumParticles; ++i) {
            auto particleEntity = engine->CreateEntity();
            particleEntity->AddComponent<ParticleComponent>(aStartSize, aEndSize, aLifetime, aCollision, aGravity,
                                                            aSpeed, aColor);
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

    int mNumParticles;
    float mSpeed;
    float mRate;
    float mStartSize;
    float mEndSize;
    float mLifetime;
    bool mCollisionEnabled;

    math::Vector3 mGravity;
};

#endif  // PARTICLESSYSTEMCOMPONENT_HPP
