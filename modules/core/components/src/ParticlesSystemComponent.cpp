#include "ParticlesSystemComponent.hpp"

void ParticleComponent::Update(double deltaTime) {
    if (life > lifetime) {
        // Reset the particle
        life = 0;
    } else {
        auto size = StartSize + (EndSize - StartSize) * (life / lifetime);
        // Update the particle size
        // Update the particle position

        life += deltaTime;
    }
}

void ParticlesSystemComponent::SetNumberOfParticles(int numParticles) { this->numParticles = numParticles; }

void ParticlesSystemComponent::SetParticleStartSize(float size) {}

void ParticlesSystemComponent::SetParticleEndSize(float size) {}

void ParticlesSystemComponent::SetParticleLifetime(float lifetime) {}

void ParticlesSystemComponent::SetParticleGravity(math::Vector3 gravity) { this->gravity = gravity; }

void ParticlesSystemComponent::SetParticlesCollision(bool collision) {}

void ParticlesSystemComponent::AddParticles(int numParticles) {}

void ParticlesSystemComponent::RemoveParticles(int numParticles) {}
