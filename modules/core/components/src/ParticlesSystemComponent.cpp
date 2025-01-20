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
void ParticleComponent::SetSpeed(const float speed) { 
    mSpeed = speed; 
}
void ParticlesSystemComponent::SetNumberOfParticles(int numParticles) { mNumParticles = numParticles; }

void ParticlesSystemComponent::SetParticleStartSize(float size) {}

void ParticlesSystemComponent::SetParticleEndSize(float size) {}

void ParticlesSystemComponent::SetParticleLifetime(float lifetime) {}

void ParticlesSystemComponent::SetParticleGravity(math::Vector3 gravity) { mGravity = gravity; }

void ParticlesSystemComponent::SetParticlesCollision(bool collision) {}

void ParticlesSystemComponent::SetSpeed(float aSpeed) { mSpeed = aSpeed; }

void ParticlesSystemComponent::SetEmissionRate(float aRate) { mRate = aRate; };
