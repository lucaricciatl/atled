#include "ParticlesSystemComponent.hpp"

void ParticlesSystemComponent::SetNumberOfParticles(int numParticles) {
    this->numParticles = numParticles;
}

void ParticlesSystemComponent::SetParticleSize(float size) {
    this->size = size;
}

void ParticlesSystemComponent::SetParticleSpeed(float speed) {
    this->speed = speed;
}

void ParticlesSystemComponent::SetParticleLifetime(float lifetime) {
    this->lifetime = lifetime;
}

void ParticlesSystemComponent::SetParticleDirection(math::Vector3 direction) {
    this->direction = direction;
}

void ParticlesSystemComponent::SetParticleSpread(float spread) {
    this->spread = spread;
}

void ParticlesSystemComponent::SetParticleGravity(math::Vector3 gravity) {
    this->gravity = gravity;
}

void ParticlesSystemComponent::SetParticleGeneratorPosition(math::Vector3 position) {
    this->position = position;
}

void ParticlesSystemComponent::SetParticlesCollision(bool collision) {
    this->collision = collision;
}

void ParticlesSystemComponent::SetRandomness(float randomness) {
    this->randomness = randomness;
}

void ParticlesSystemComponent::OnAction(Action action, bool activated) {

}

void ParticlesSystemComponent::Update(double deltaTime) {

}
