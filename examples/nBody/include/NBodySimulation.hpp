#ifndef NBODY_SIMULATION_HPP
#define NBODY_SIMULATION_HPP

#include "Point2D.hpp"
#include <vector>
#include <memory>
#include "Circle.hpp"
#include "Model2DFactory.hpp"
#include <cmath>

using namespace graphics;

struct Body {
    Coordinates2D position;
    Coordinates2D velocity;
    float mass;
    Color color;

    Body(Coordinates2D pos, Coordinates2D vel, float m, Color col)
        : position(pos), velocity(vel), mass(m), color(col) {}
};

class NBodySimulation {
public:
    NBodySimulation(int numBodies);
    void InitializeBodies();
    void Update(float dt);
    const std::vector<std::shared_ptr<Circle>>& GetCircles() const;

private:
    std::vector<Body> bodies;
    std::vector<std::shared_ptr<Circle>> circles;
    const float G = 6.67430e-11;
    const float damping = 0.9;
    const float distanceTolerance = 1.0;

    Coordinates2D CalculateGravitationalForce(const Body& a, const Body& b) const;
    float Distance(const Coordinates2D& a, const Coordinates2D& b) const;
};

#endif // NBODY_SIMULATION_HPP
