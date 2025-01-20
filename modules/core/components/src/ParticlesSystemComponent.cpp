#include "ParticlesSystemComponent.hpp"

void ParticleComponent::Update(double deltaTime) {
    if (life > mLifetime) {
        
        life = 0;
        auto genpos = owner->GetParent()->GetComponent<FrameComponent>()->GetPosition();
        mFrame->SetPosition(genpos->GetX(), genpos->GetY(), genpos->GetZ());
    } else {
        auto size = mStartSize + (mEndSize - mStartSize) * (life / mLifetime);
        auto pos = mFrame->GetPosition();
        mFrame->SetPosition(pos->GetX() + xr * mSpeed * deltaTime, pos->GetY() + yr * mSpeed * deltaTime,
                            pos->GetZ() + zr * mSpeed * deltaTime);

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

void ParticlesSystemComponent::SetParticleGravity(math::Vector3 gravity) { mGravity = gravity; }

void ParticlesSystemComponent::SetParticlesCollision(bool collision) {}

void ParticlesSystemComponent::AddParticles(int numParticles) {}

void ParticlesSystemComponent::RemoveParticles(int numParticles) {}

void ParticlesSystemComponent::SetSpeed(float aSpeed) {


}

void ParticlesSystemComponent::SetEmissionRate(float aRate) { mRate = aRate; };
