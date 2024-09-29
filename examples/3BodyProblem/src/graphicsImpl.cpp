#include "graphicsImpl.hpp"

#include <cmath>
#include <iostream>
#include <vector>

using namespace graphics;

struct Body {
  Vector2 position;
  Vector2 velocity;
  float mass;
  Color color;
};

namespace {
const float G = 6.67430e-9f;   // Gravitational constant
const float deltaTime = 1.0f;  // Fixed time step
const float softening = 1.0f;  // Softening factor to prevent singularity
float stime = 0.0f;            // Simulation time
}  // namespace

std::vector<Body> bodies;  // Global vector to hold the bodies

// Function to calculate gravitational force between two bodies with softening
Vector2 CalculateGravitationalForce(const Body& body1, const Body& body2) {
  Vector2 direction = {body2.position.x - body1.position.x,
                       body2.position.y - body1.position.y};
  float distanceSquared = direction.x * direction.x + direction.y * direction.y;

  // Apply softening to avoid singularities
  distanceSquared = std::max(distanceSquared, softening * softening);

  float distance = std::sqrt(distanceSquared);
  float forceMagnitude = (G * body1.mass * body2.mass) / distanceSquared;

  Vector2 force = {direction.x / distance * forceMagnitude,
                   direction.y / distance * forceMagnitude};
  return force;
}

void UpdateBodies(std::vector<Body>& bodies) {
  std::vector<Body> newBodies = bodies;

  for (size_t i = 0; i < bodies.size(); ++i) {
    Vector2 netForce = {0.0f, 0.0f};

    for (size_t j = 0; j < bodies.size(); ++j) {
      if (i != j) {
        Vector2 force = CalculateGravitationalForce(bodies[i], bodies[j]);
        netForce.x += force.x;
        netForce.y += force.y;
      }
    }

    // Update velocity based on the net force (F = ma, a = F/m)
    Vector2 acceleration = {netForce.x / bodies[i].mass,
                            netForce.y / bodies[i].mass};
    newBodies[i].velocity.x += acceleration.x * deltaTime;
    newBodies[i].velocity.y += acceleration.y * deltaTime;

    // Update position based on the velocity
    newBodies[i].position.x += newBodies[i].velocity.x * deltaTime;
    newBodies[i].position.y += newBodies[i].velocity.y * deltaTime;
  }

  bodies = newBodies;
}

void RenderBodyWithBuffer(std::shared_ptr<graphics::Buffer2D> buffer,
                          const Body& body, int numSegments = 100) {
  std::vector<ColoredPoint2D> points;
  float radius = 8 * std::log(body.mass) /
                 std::log(1.0e10f);  // Scale radius based on the mass

  Color bodyColor = body.color;

  // Generate points for the circle approximation
  for (int i = 0; i < numSegments; ++i) {
    float theta = 2.0f * PI * i / numSegments;
    int x = static_cast<int>(body.position.x + radius * std::sin(theta));
    int y = static_cast<int>(body.position.y + radius * std::cos(theta));
    points.emplace_back(x, y, bodyColor);
  }

  buffer->SetBuffer(points);
  buffer->DrawBuffer();
}

void RenderBodies(GraphicsManagerImpl* gfxManager,
                  const std::vector<Body>& bodies) {
  if (bodies.size() > 0) {
    RenderBodyWithBuffer(gfxManager->polyBuffer, bodies[0]);
  }
  if (bodies.size() > 1) {
    RenderBodyWithBuffer(gfxManager->polyBuffer2, bodies[1]);
  }
  if (bodies.size() > 2) {
    RenderBodyWithBuffer(gfxManager->polyBuffer3, bodies[2]);
  }
}

void GraphicsManagerImpl::Init() {
  mContext->mLayerManager.AddLayer(1);
  mContext->mLayerManager.AddLayer(2);

  auto layer = mContext->mLayerManager.GetLayerById(1);
  auto layer2 = mContext->mLayerManager.GetLayerById(2);
  auto bm = layer->GetBufferManager();

  // Create buffers for bodies
  polyBuffer = bm->createBuffer(BufferType::POLY2D);
  polyBuffer2 = bm->createBuffer(BufferType::POLY2D);
  polyBuffer3 = bm->createBuffer(BufferType::POLY2D);

  // Initialize bodies with positions, velocities, and masses
  bodies.push_back({{600.0f, 600.0f}, {3.0f, -1.0f}, 1.0e10f, RED});
  bodies.push_back({{300.0f, 300.0f}, {0.0f, -6.0f}, 2.0e10f, GREEN});
  bodies.push_back({{450.0f, 450.0f}, {0.0f, 0.0f}, 1e12f, BLUE});
}

void GraphicsManagerImpl::Render() {
  if (mContext->isReady) {
    mContext->BeginDrawing();
    mContext->GetCamera()->setOffset(Vector2({300.0f, 300.0f}));
    mContext->GetCamera()->setTarget(Vector2{20.0f, 20.0f});
    mContext->GetCamera()->setRotation(0.0f);
    mContext->GetCamera()->setZoom(0.4f);
    mContext->GetCamera()->BeginCamera();

    // Update the bodies' positions
    UpdateBodies(bodies);

    // Render the bodies
    RenderBodies(this, bodies);

    // Clear the screen with a transparency effect
    mContext->Clear(Color(0, 0, 0, 0));

    mContext->EndDrawing();

    // Increment simulation time
    stime += deltaTime;
  }
}
