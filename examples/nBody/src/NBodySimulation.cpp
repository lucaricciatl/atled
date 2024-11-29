#include "NBodySimulation.hpp"
#include <random>
#include <FrameComponent.hpp>

// Constructor to initialize entities and body data
NBodySimulation::NBodySimulation(std::vector<std::shared_ptr<Entity>> entities)
    : entities(std::move(entities)) {
    InitializeBodyData();
}

// Initialize velocity and mass for each entity
void NBodySimulation::InitializeBodyData() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distVel(-50.0f, 50.0f);
    std::uniform_real_distribution<float> distMass(1e12f, 1e14f);

    for (const auto& entity : entities) {
        Coordinates2D initialVelocity(distVel(gen), distVel(gen));
        float mass = distMass(gen);
        bodies.push_back({ initialVelocity, mass });
    }
}

Coordinates2D NBodySimulation::CalculateGravitationalForce(const Coordinates2D& pos1, float mass1,
    const Coordinates2D& pos2, float mass2) const {
    float dx = pos2.GetX() - pos1.GetX();
    float dy = pos2.GetY() - pos1.GetY();
    float distance = std::sqrt(dx * dx + dy * dy) + 1e-5f; // Prevent division by zero
    float force = (G * mass1 * mass2) / (distance * distance);

    return Coordinates2D(force * dx / distance, force * dy / distance);
}

void NBodySimulation::Update(float dt) {
    std::vector<Coordinates2D> forces(entities.size(), Coordinates2D(0.0f, 0.0f));

    for (size_t i = 0; i < entities.size(); ++i) {
        auto frameComponent1 = entities[i]->GetComponent<FrameComponent>();
        if (!frameComponent1) continue;

        auto pos1 = frameComponent1->GetPosition();
        auto mass1 = bodies[i].mass;

        Coordinates2D coord1(pos1->getX(), pos1->getY());

        for (size_t j = 0; j < entities.size(); ++j) {
            if (i == j) continue;

            auto frameComponent2 = entities[j]->GetComponent<FrameComponent>();
            if (!frameComponent2) continue;

            auto pos2 = frameComponent2->GetPosition();
            auto mass2 = bodies[j].mass;

            Coordinates2D coord2(pos2->getX(), pos2->getY());

            forces[i] = forces[i] + CalculateGravitationalForce(coord1, mass1, coord2, mass2);
        }
    }

    for (size_t i = 0; i < entities.size(); ++i) {
        auto frameComponent = entities[i]->GetComponent<FrameComponent>();
        if (!frameComponent) continue;

        Coordinates2D acceleration(forces[i].GetX() / bodies[i].mass, forces[i].GetY() / bodies[i].mass);
        bodies[i].velocity = Coordinates2D(
            (bodies[i].velocity.GetX() + acceleration.GetX() * dt) * damping,
            (bodies[i].velocity.GetY() + acceleration.GetY() * dt) * damping
        );

        Coordinates2D newPos(
            frameComponent->GetPosition()->getX() + bodies[i].velocity.GetX() * dt,
            frameComponent->GetPosition()->getY() + bodies[i].velocity.GetY() * dt
        );

        frameComponent->SetPosition(newPos.GetX(), newPos.GetY(), 0.0f);
    }
}
