#include "graphicsImpl.hpp"
#include <iostream>
#include <vector>
#include <cmath>

using namespace graphics;

struct Body {
    Vector2 position;
    Vector2 velocity;
    float mass;
    Color color;
};

namespace {
float stime = 0.0f;  // Initialize time variable

// Gravitational constant for the simulation (tweak as necessary)
const float G = 6.67430e-9f;

// Delta time (fixed time step for simulation)
const float deltaTime = 1;

#include <cmath>  // For sqrt

// Function to calculate the gravitational force between two bodies
Vector2 CalculateGravitationalForce(const Body& body1, const Body& body2) {
    Vector2 direction; 
    direction.x = body2.position.x - body1.position.x;
    direction.y = body2.position.y - body1.position.y;
    float distance = sqrt(direction.x * direction.x + direction.y * direction.y);
    
    // Prevent division by zero and stabilize very close bodies
    if (distance < 1.0f) distance = 1.0f;
    
    float forceMagnitude = (G * body1.mass * body2.mass) / (distance * distance);
    Vector2 force;
    force.x = direction.x / distance * forceMagnitude;  // Normalize and apply magnitude
    force.y = direction.y / distance * forceMagnitude;  // Normalize and apply magnitude

    return force;
}
}  // namespace

std::vector<Body> bodies;  // Global vector to hold our three bodies

void GraphicsManagerImpl::Init() {
    // Initialize layers and buffers
    mContext->mLayerManager.AddLayer(1);
    mContext->mLayerManager.AddLayer(2);
    auto layer = mContext->mLayerManager.GetLayerById(1);
    auto layer2 = mContext->mLayerManager.GetLayerById(2);
    auto bm = layer->GetBufferManager();

    // Create separate buffers for each body
    polyBuffer = bm->createBuffer(BufferType::POLY2D);  // Buffer for body 1
    polyBuffer2 = bm->createBuffer(BufferType::POLY2D);  // Buffer for body 2
    polyBuffer3 = bm->createBuffer(BufferType::POLY2D);  // Buffer for body 3

    // Initialize three bodies with initial positions, velocities, and masses
    bodies.push_back({{600.0f, 600.0f}, {3.0f, -1.0f}, 1.0e10f, RED});  // Body 1
    bodies.push_back({{300.0f, 300.0f}, {0.0f, -6.0f}, 2.0e10f, GREEN});  // Body 2
    bodies.push_back({{450.0f, 450.0f}, {0.0f, 0.0f}, 1e12f, BLUE});  // Body 3
}


void UpdateBodies(std::vector<Body>& bodies) {
    // Copy bodies for calculations to avoid modifying the bodies mid-calculation
    std::vector<Body> newBodies = bodies;

    for (size_t i = 0; i < bodies.size(); ++i) {
        Vector2 netForce = {0.0f, 0.0f};
        
        // Calculate net gravitational force on each body from every other body
        for (size_t j = 0; j < bodies.size(); ++j) {
            if (i != j) {
                Vector2 force = CalculateGravitationalForce(bodies[i], bodies[j]);
                netForce.x += force.x;
                netForce.y += force.y;
            }
        }

        // Update velocity based on the net force (F = ma, a = F/m)
        Vector2 acceleration;
        acceleration.x = netForce.x / bodies[i].mass;
        acceleration.y = netForce.y / bodies[i].mass;
        newBodies[i].velocity.x += acceleration.x * deltaTime;
        newBodies[i].velocity.y += acceleration.y * deltaTime;
        // Update position based on the velocity
        newBodies[i].position.x += newBodies[i].velocity.x * deltaTime;
        newBodies[i].position.y += newBodies[i].velocity.y * deltaTime;

    }

    // Update the bodies with new positions and velocities
    bodies = newBodies;
}

void RenderBodyWithBuffer(std::shared_ptr<graphics::Buffer2D> buffer, const Body& body, int numSegments = 100) {
    // Create a polygonal approximation of a circle for the body
    std::vector<ColoredPoint2D> bodyCircle;
    float radius = 8 *  log(body.mass) / log(1.0e10f);  // Scale radius based on the mass

    // Generate points for the polygon that approximates the circle
      std::vector<ColoredPoint2D> points;
      auto colrt = RED;
      points.emplace_back(static_cast<int>(body.position.x + 0), static_cast<int>(body.position.y + 0),
                          colrt);  // Example points
      for (int i = 0; i < (53); ++i) {
        // Apply oscillation to the polygon points
        int x = static_cast<int>(body.position.x + radius * sin(2 * PI / 52 * i));
        int y = static_cast<int>(body.position.y + radius * cos(2 * PI / 52 * i));
        points.emplace_back(x, y, colrt);
      }

    // Set the buffer with the generated circle points
    buffer->SetBuffer(points);
    buffer->DrawBuffer();  // Draw the circle
}

void RenderBodies(GraphicsManagerImpl* gfxManager, const std::vector<Body>& bodies) {
    // Render each body with its own buffer
    if (bodies.size() > 0) {
        RenderBodyWithBuffer(gfxManager->polyBuffer, bodies[0]);  // Render Body 1
    }
    if (bodies.size() > 1) {
        RenderBodyWithBuffer(gfxManager->polyBuffer2, bodies[1]);  // Render Body 2
    }
    if (bodies.size() > 2) {
        RenderBodyWithBuffer(gfxManager->polyBuffer3, bodies[2]);  // Render Body 3
    }
}


void GraphicsManagerImpl::Render() {
    if (mContext->isReady) {
        mContext->Begin();

        // Update the positions of the bodies based on gravitational forces
        UpdateBodies(bodies);

        // Render each body as a circle using its own buffer
        RenderBodies(this, bodies);

        // Clear the screen with a slight transparency for a trailing effect
        auto col = Color(0, 0, 0, 0);
        mContext->Clear(col);
        
        mContext->End();

        stime += deltaTime;  // Increment time for the simulation
    }
}