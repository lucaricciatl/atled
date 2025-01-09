#include "ParticlesSystemComponent.hpp"

void ParticlesSystemComponent::SetNumberOfParticles(int numParticles) { this->numParticles = numParticles; }

void ParticlesSystemComponent::SetParticleStartSize(float size) { this->StartSize = size; }

void ParticlesSystemComponent::SetParticleEndSize(float size) { this->EndSize = size; }

void ParticlesSystemComponent::SetParticleLifetime(float lifetime) { this->lifetime = lifetime; }

void ParticlesSystemComponent::SetParticleSpread(float spread) { this->spread = spread; }

void ParticlesSystemComponent::SetParticleGravity(math::Vector3 gravity) { this->gravity = gravity; }

void ParticlesSystemComponent::SetParticlesCollision(bool collision) { this->collision = collision; }

void ParticlesSystemComponent::OnAction(Action action, bool activated) {}

void ParticlesSystemComponent::Update(double deltaTime) {}
