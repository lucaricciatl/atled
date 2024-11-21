#pragma once

#include <execution>
#include "NBodySimulation.hpp"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <memory>
#include <cmath>

constexpr float G = 6.67430e-11f; // Gravitational constant in m^3 kg^-1 s^-2 (SI units)


// Quadtree node class for 2D space
class QuadNode {
public:
    float xMin, xMax, yMin, yMax; // Boundaries of the node
    float mass = 0.0f;
    Coordinates2D centerOfMass;
    std::shared_ptr<Body> body; // Non-null for leaf nodes
    std::unique_ptr<QuadNode> NW, NE, SW, SE; // Children quadrants

    QuadNode(float xMin, float xMax, float yMin, float yMax)
        : xMin(xMin), xMax(xMax), yMin(yMin), yMax(yMax), centerOfMass(0, 0), body(nullptr) {}

    // Insert a body into the quadtree
    void Insert(std::shared_ptr<Body> newBody);

    // Check if the position is within boundaries
    bool Contains(const Coordinates2D& pos) const;

    // Calculate force exerted on a target body
    Coordinates2D CalculateForce(const Body& targetBody, float theta, float distanceTolerance) const;
};

void QuadNode::Insert(std::shared_ptr<Body> newBody) {
    if (!Contains(newBody->position)) return;

    if (mass == 0.0f && !body) {
        // Empty node, place body here
        mass = newBody->mass;
        centerOfMass = newBody->position;
        body = newBody;
    }
    else {
        // Internal node or leaf node with a body
        if (!NW) {
            // Subdivide the node
            float xMid = (xMin + xMax) / 2.0f;
            float yMid = (yMin + yMax) / 2.0f;

            NW = std::make_unique<QuadNode>(xMin, xMid, yMin, yMid);
            NE = std::make_unique<QuadNode>(xMid, xMax, yMin, yMid);
            SW = std::make_unique<QuadNode>(xMin, xMid, yMid, yMax);
            SE = std::make_unique<QuadNode>(xMid, xMax, yMid, yMax);

            if (body) {
                // Re-insert existing body into children
                NW->Insert(body);
                NE->Insert(body);
                SW->Insert(body);
                SE->Insert(body);
                body = nullptr; // Clear the body since it's now subdivided
            }
        }

        // Update mass and center of mass
        float totalMass = mass + newBody->mass;
        centerOfMass = Coordinates2D(
            (centerOfMass.GetX() * mass + newBody->position.GetX() * newBody->mass) / totalMass,
            (centerOfMass.GetY() * mass + newBody->position.GetY() * newBody->mass) / totalMass
        );
        mass = totalMass;

        // Insert the new body into the appropriate quadrant
        NW->Insert(newBody);
        NE->Insert(newBody);
        SW->Insert(newBody);
        SE->Insert(newBody);
    }
}

bool QuadNode::Contains(const Coordinates2D& pos) const {
    return (pos.GetX() >= xMin && pos.GetX() <= xMax && pos.GetY() >= yMin && pos.GetY() <= yMax);
}

Coordinates2D QuadNode::CalculateForce(const Body& targetBody, float theta, float distanceTolerance) const {
    if (mass == 0.0f || (body && body.get() == &targetBody)) {
        return Coordinates2D(0.0f, 0.0f); // No force from empty nodes or self
    }

    float dx = centerOfMass.GetX() - targetBody.position.GetX();
    float dy = centerOfMass.GetY() - targetBody.position.GetY();
    float distance = std::sqrt(dx * dx + dy * dy) + 1e-10f; // Avoid division by zero

    float width = xMax - xMin;
    if ((width / distance) < theta || (!NW && !NE && !SW && !SE)) {
        // Accept this node's mass distribution
        if (distance < distanceTolerance) {
            return Coordinates2D(0.0f, 0.0f);
        }
        constexpr float epsilon = 1e-5f; // Small constant to prevent instability
        float force = (G * targetBody.mass * mass) / ((distance * distance) + epsilon);
        float dampingFactor = 0.99f; // Slightly reduce the force
        force *= dampingFactor;
        float fx = force * dx / distance;
        float fy = force * dy / distance;
        return Coordinates2D(fx, fy);
    }
    else {
        // Recursively calculate force from children
        Coordinates2D force(0.0f, 0.0f);
        if (NW) force = force + NW->CalculateForce(targetBody, theta, distanceTolerance);
        if (NE) force = force + NE->CalculateForce(targetBody, theta, distanceTolerance);
        if (SW) force = force + SW->CalculateForce(targetBody, theta, distanceTolerance);
        if (SE) force = force + SE->CalculateForce(targetBody, theta, distanceTolerance);
        return force;
    }
}

// Updated NBodySimulation class methods
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
        float mass = static_cast<float>((std::rand() % 500) + 100) * 1e12f;
        Color color(std::rand() % 256, std::rand() % 256, std::rand() % 256, 255);

        bodies.emplace_back(Coordinates2D(posX, posY), Coordinates2D(velX, velY), mass, color);

        auto circle = graphics::Model2DFactory::CreateCircle();
        circle->SetCenter(bodies.back().position);
        circle->SetRadius(1.0f);  // Set radius of each body for rendering
        circle->SetColor(bodies.back().color);
        circles.push_back(circle);
    }
}

void NBodySimulation::Update(float dt) {
    // Build the quadtree
    float xMin = 0.0f, xMax = 900.0f, yMin = 0.0f, yMax = 900.0f;
    auto root = std::make_unique<QuadNode>(xMin, xMax, yMin, yMax);

    // Insert bodies into the quadtree
    for (size_t i = 0; i < bodies.size(); ++i) {
        root->Insert(std::make_shared<Body>(bodies[i]));
    }

    float theta = 0.5f; // Threshold parameter for approximation
    std::vector<Coordinates2D> forces(bodies.size(), Coordinates2D(0.0f, 0.0f));

    // Calculate gravitational forces using the quadtree
    std::for_each(std::execution::par, bodies.begin(), bodies.end(), [&](Body& body) {
        size_t i = &body - &bodies[0];
        forces[i] = root->CalculateForce(body, theta, distanceTolerance);
        });

    // Update velocities and positions in parallel based on forces
    std::for_each(std::execution::par, bodies.begin(), bodies.end(), [&](Body& body) {
        size_t i = &body - &bodies[0];
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

std::vector<std::shared_ptr<graphics::Circle>>& NBodySimulation::GetCircles() {
    return circles;
}
