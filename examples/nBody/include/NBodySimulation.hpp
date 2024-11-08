#pragma once


#include "Model2DFactory.hpp"
#include "Point2D.hpp"
#include <vector>
#include <memory>
#include <cmath>
#include <ctime>


struct Body {
    Coordinates2D position;
    Coordinates2D velocity;
    float mass;
    Color color;

    Body(const Coordinates2D& pos, const Coordinates2D& vel, float m, const Color& col)
        : position(pos), velocity(vel), mass(m), color(col) {}
};

class NBodySimulation {
public:
    NBodySimulation(int numBodies = 1000);

    void InitializeBodies();
    void Update(float dt);
    const std::vector<std::shared_ptr<graphics::Circle>>& GetCircles() const;

private:
    std::vector<Body> bodies;
    std::vector<std::shared_ptr<graphics::Circle>> circles;

    const float G = 6.67430e-11f;          // Gravitational constant
    const float distanceTolerance = 1.0f; // Minimum distance to avoid division by zero
    const float damping = 0.99f;           // Damping factor for velocity

    float Distance(const Coordinates2D& a, const Coordinates2D& b) const;
    Coordinates2D CalculateGravitationalForce(const Body& a, const Body& b) const;
};
