#include <iostream>
#include <vector>
#include <cmath>
#include "graphicsImpl.hpp"
#include "Circle.hpp"
#include "Model2DFactory.hpp"
#include "Model2D.hpp"  
using namespace graphics;

// Define a struct for the bodies in the N-body simulation
struct Body {
    Coordinates2D position;
    Coordinates2D velocity;
    float mass;
    Color color;

    Body(Coordinates2D pos, Coordinates2D vel, float m, Color col)
        : position(pos), velocity(vel), mass(m), color(col) {}
};

namespace {
    const float G = 6.67430e-11; // Gravitational constant
    float times = 0.0f;
    int nBody = 1000;
    const float damping = 0.9;  // Damping factor to simulate drag/friction
    const float distanceTolerance = 1;  // Tolerance to avoid zero distance
    std::vector<Body> bodies;
    std::vector<std::shared_ptr<Circle>> circles;
}


// Helper function to calculate the distance between two points
float Distance(const Coordinates2D& a, const Coordinates2D& b) {
    return sqrt((a.GetX() - b.GetX()) * (a.GetX() - b.GetX()) + (a.GetY() - b.GetY()) * (a.GetY() - b.GetY()));
}

// Helper function to calculate gravitational force
Coordinates2D CalculateGravitationalForce(const Body& a, const Body& b) {
    float distance = Distance(a.position, b.position);
    if (distance < distanceTolerance) { return Coordinates2D(0, 0); };

    float force = (G * a.mass * b.mass) / (distance * distance);
    
    // Calculate the direction of the force
    float dx = b.position.GetX() - a.position.GetX();
    float dy = b.position.GetY() - a.position.GetY();
    float angle = atan2(dy, dx);
    
    // Return the force vector
    return Coordinates2D(force * cos(angle), force * sin(angle));
}





void GraphicsManagerImpl::Init() {
    auto ctx = GetGraphicsContext();
    ctx->SetSize(900, 900);
    ctx->SetTitle("N-body Simulation");

    // Seed for randomness
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate random bodies
    for (int i = 0; i < nBody; ++i) {
        // Random position within the window (900x900)
        float posX = static_cast<float>(std::rand() % 900);
        float posY = static_cast<float>(std::rand() % 900);
        
        // Random velocity in the range [-1, 1] for both x and y
        float velX = static_cast<float>((std::rand() % 200 - 100) / 100.0f);
        float velY = static_cast<float>((std::rand() % 200 - 100) / 100.0f);
        
        // Random mass in the range [1e14, 5e15]
        float mass = static_cast<float>((std::rand() % 500) + 100) * 1e12;
        
        // Random color for the body
        int red = std::rand() % 256;
        int green = std::rand() % 256;
        int blue = std::rand() % 256;
        Color color(red, green, blue, 255);

        // Create the body and add it to the vector
        bodies.push_back(Body(Coordinates2D(posX, posY), Coordinates2D(velX, velY), mass, color));
    }
    // Render each body as a circle
    for (size_t i = 0; i < bodies.size(); i++) {
        auto circle = Model2DFactory::CreateCircle();
        circle->SetCenter(bodies[i].position);
        circle->SetRadius(1);  // Set a fixed radius for simplicity
        circle->SetColor(bodies[i].color);
        circles.push_back(circle);  // Add the circle to the circles vector
        AddCircle(static_cast<int>(1), circle);
    }
    
    // Configure the graphics settings
    auto configs = graphics::GfxConfig({FLAG_WINDOW_RESIZABLE, FLAG_VSYNC_HINT,
                                        FLAG_WINDOW_HIGHDPI, FLAG_MSAA_4X_HINT});
    SetConfigs(configs);
}

void UpdateBodies(float dt) {
    std::vector<Coordinates2D> forces(bodies.size(), Coordinates2D(0, 0));

    // Calculate the gravitational forces
    for (size_t i = 0; i < bodies.size(); i++) {
        for (size_t j = 0; j < bodies.size(); j++) {
            if (i != j) {
                forces[i] = forces[i] + CalculateGravitationalForce(bodies[i], bodies[j]);
            }
        }
    }

    // Update velocities and positions based on the forces and apply damping
    for (size_t i = 0; i < bodies.size(); i++) {
        Coordinates2D acceleration(forces[i].GetX() / bodies[i].mass, forces[i].GetY() / bodies[i].mass);

        // Update velocity with damping
        bodies[i].velocity = Coordinates2D(
            (bodies[i].velocity.GetX() + acceleration.GetX() * dt) * damping,
            (bodies[i].velocity.GetY() + acceleration.GetY() * dt) * damping
        );

        // Update position
        bodies[i].position = Coordinates2D(
            bodies[i].position.GetX() + bodies[i].velocity.GetX() * dt,
            bodies[i].position.GetY() + bodies[i].velocity.GetY() * dt
        );
    }
}

void GraphicsManagerImpl::Render() {
    // Update positions and velocities of the bodies
    float dt = 0.01f;  // Time step for the simulation
    UpdateBodies(dt);

    BeginDrawing();
    Clear(Color(0, 0, 0, 0));

    // Update the positions of the circles
    for (size_t i = 0; i < bodies.size(); ++i) {
        // Update the center of each circle based on the current position of the corresponding body
        circles[i]->SetCenter(bodies[i].position);  // Update the center of the circle
    }

    DrawLayer(1);



    EndDrawing();

}
