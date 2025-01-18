#include "ParticlesSystemComponent.hpp"

void ParticleComponent::Update(double deltaTime) {
    if (life > mLifetime) {
        
        life = 0;
    } else {
        auto size = mStartSize + (mEndSize - mStartSize) * (life / mLifetime);
        static std::random_device rd;                           // Seed for the random number engine
        static std::mt19937 gen(rd());                          // Mersenne Twister random number generator
        static std::uniform_real_distribution<> dis(0.0, 1.0);  // Random numbers in range [0.0, 1.0]
        // Set position using the generated random numbers
        // Generate random x, y, z
        double x = dis(gen);
        double y = dis(gen);
        double z = dis(gen);
        mFrame->SetPosition(x * mSpeed, y * mSpeed, z * mSpeed);

        life += deltaTime;
    }
}
void ParticleComponent::SetSpeed(const float speed) { 
    mSpeed = speed; 
}
void ParticlesSystemComponent::SetNumberOfParticles(int numParticles) { this->numParticles = numParticles; }

void ParticlesSystemComponent::SetParticleStartSize(float size) {}

void ParticlesSystemComponent::SetParticleEndSize(float size) {}

void ParticlesSystemComponent::SetParticleLifetime(float lifetime) {}

void ParticlesSystemComponent::SetParticleGravity(math::Vector3 gravity) { this->gravity = gravity; }

void ParticlesSystemComponent::SetParticlesCollision(bool collision) {}

void ParticlesSystemComponent::AddParticles(int numParticles) {}

void ParticlesSystemComponent::RemoveParticles(int numParticles) {}

void ParticlesSystemComponent::SetSpeed(float aSpeed) {


}

void ParticlesSystemComponent::SetEmissionRate(float aRate){ mRate = aRate;};
