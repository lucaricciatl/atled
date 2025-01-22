#include "ParticlesSystemComponent.hpp"

void ParticleComponent::Update(double deltaTime) {
    if (mLife > mLifetime) {
        mLife = 0;
        auto genpos = mOwner->GetParent()->GetComponent<FrameComponent>()->GetPosition();
        mFrame->SetPosition(genpos->GetX(), genpos->GetY(), genpos->GetZ());
    } else {
        auto size = mStartSize + (mEndSize - mStartSize) * (mLife / mLifetime);
        auto pos = mFrame->GetPosition();
        mFrame->SetPosition(pos->GetX() + xr * mSpeed * deltaTime, pos->GetY() + yr * mSpeed * deltaTime,
                            pos->GetZ() + zr * mSpeed * deltaTime);

        mLife += deltaTime;
    }
}

void ParticleComponent::SetLifetime(const float lifetime) { mLifetime = lifetime; }

void ParticleComponent::SetCollision(const bool collision) { mCollisionEnabled = collision; }

void ParticleComponent::SetEndSize(const float size) { mEndSize = size; }

void ParticleComponent::SetStartSize(const float size) { mStartSize = size; }

void ParticleComponent::SetSpeed(const float speed) { 
    mSpeed = speed; 
}
void ParticlesSystemComponent::SetNumberOfParticles(int numParticles) { mNumParticles = numParticles; }

void ParticlesSystemComponent::SetParticleStartSize(float size) {
    mStartSize = size;
    for (auto& particle : mParticles) {
        particle->GetComponent<ParticleComponent>()->SetStartSize(size);
    }
}

void ParticlesSystemComponent::SetParticleEndSize(float size) {
    mEndSize = size;
    for (auto& particle : mParticles) {
        particle->GetComponent<ParticleComponent>()->SetEndSize(size);
    }
}

void ParticlesSystemComponent::SetParticleLifetime(float lifetime) {
    mLifetime = lifetime;
    for (auto& particle : mParticles) {
        particle->GetComponent<ParticleComponent>()->SetLifetime(lifetime);
    }
}

void ParticlesSystemComponent::SetParticleGravity(math::Vector3 gravity) { mGravity = gravity; }

void ParticlesSystemComponent::SetParticlesCollision(bool collision) {
    mCollisionEnabled = collision;
    for (auto& particle : mParticles) {
        particle->GetComponent<ParticleComponent>()->SetCollision(collision);
    }
}

void ParticlesSystemComponent::SetSpeed(float aSpeed) {
    mSpeed = aSpeed;
    for (auto& particle : mParticles) {
        particle->GetComponent<ParticleComponent>()->SetSpeed(aSpeed);
    }
}

void ParticlesSystemComponent::SetEmissionRate(float aRate) { mRate = aRate; };
