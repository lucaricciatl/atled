#pragma once


#include <execution> 
#include "NBodySimulation.hpp"
#include <cstdlib>  // For std::rand and std::srand
#include <ctime>    // For std::time




NBodySimulation::NBodySimulation(int numBodies) {
    bodies.reserve(numBodies);
    circles.reserve(numBodies);
}

void NBodySimulation::InitializeBodies() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed the random generator

    // Generate random bodies
    for (int i = 0; i < bodies.capacity(); ++i) {
        float posX = static_cast<float>(std::rand() % 900);
        float posY = static_cast<float>(std::rand() % 900);
        float velX = static_cast<float>((std::rand() % 200 - 100) / 100.0f);
        float velY = static_cast<float>((std::rand() % 200 - 100) / 100.0f);
        float mass = static_cast<float>((std::rand() % 500) + 100) * 1e12;
        Color color(std::rand() % 256, std::rand() % 256, std::rand() % 256, 255);

        bodies.emplace_back(Coordinates2D(posX, posY), Coordinates2D(velX, velY), mass, color);

        auto circle = graphics::Model2DFactory::CreateCircle();
        circle->SetCenter(bodies.back().position);
        circle->SetRadius(1);  // Set radius of each body for rendering
        circle->SetColor(bodies.back().color);
        circles.push_back(circle);
    }
}

float NBodySimulation::Distance(const Coordinates2D& a, const Coordinates2D& b) const {
    return std::sqrt((a.GetX() - b.GetX()) * (a.GetX() - b.GetX()) +
        (a.GetY() - b.GetY()) * (a.GetY() - b.GetY()));
}

Coordinates2D NBodySimulation::CalculateGravitationalForce(const Body& a, const Body& b) const {
    float distance = Distance(a.position, b.position);
    if (distance < distanceTolerance) {
        return Coordinates2D(0, 0); // Avoid division by zero if too close
    }

    float force = (G * a.mass * b.mass) / (distance * distance);
    float dx = b.position.GetX() - a.position.GetX();
    float dy = b.position.GetY() - a.position.GetY();
    float angle = std::atan2(dy, dx);

    return Coordinates2D(force * std::cos(angle), force * std::sin(angle));
}


void NBodySimulation::Update(float dt) {
    std::vector<Coordinates2D> forces(bodies.size(), Coordinates2D(0, 0));

    // Calculate gravitational forces in parallel
    std::for_each(std::execution::par, bodies.begin(), bodies.end(), [&](Body& bodyA) {
        size_t i = &bodyA - &bodies[0];  // Find index of the current body
        for (size_t j = 0; j < bodies.size(); ++j) {
            if (i != j) {
                forces[i] = forces[i] + CalculateGravitationalForce(bodies[i], bodies[j]);
            }
        }
        });

    // Update velocities and positions in parallel based on forces
    std::for_each(std::execution::par, bodies.begin(), bodies.end(), [&](Body& body) {
        size_t i = &body - &bodies[0];  // Find index of the current body
        Coordinates2D acceleration(forces[i].GetX() / bodies[i].mass, forces[i].GetY() / bodies[i].mass);
        bodies[i].velocity = Coordinates2D(
            (bodies[i].velocity.GetX() + acceleration.GetX() * dt) * damping,
            (bodies[i].velocity.GetY() + acceleration.GetY() * dt) * damping
        );
        bodies[i].position = Coordinates2D(
            bodies[i].position.GetX() + bodies[i].velocity.GetX() * dt,
            bodies[i].position.GetY() + bodies[i].velocity.GetY() * dt
        );

        // Update corresponding circle's position
        circles[i]->SetCenter(bodies[i].position);
        });
}

const std::vector<std::shared_ptr<graphics::Circle>>& NBodySimulation::GetCircles() const {
    return circles;
}
