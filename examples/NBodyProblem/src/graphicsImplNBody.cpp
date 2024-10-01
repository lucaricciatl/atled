#include "GraphicsManager.hpp"
#include "Buffer2D.hpp"
#include "PointBuffer2D.hpp"
#include "BuffersManager.hpp"
#include "graphicsImpl.hpp"
#include "Layer.hpp"
#include <cmath>
#include <iostream>
#include <vector>
#include "Keyboard.hpp"
#include "Mouse.hpp"
#include "Camera2D.hpp"  // Include your Camera2D implementation

using namespace graphics;

struct Body {
  Vector2 position;
  Vector2 velocity;
  float mass;
  Color color;
};

// Constants and Input
namespace {
const float G = 6.67430e-9f;   // Gravitational constant
const float deltaTime = 0.05f;  // Fixed time step
const float softening = 6.0f;  // Softening factor to prevent singularity
float stime = 0.0f;            // Simulation time
input::KeyboardInput Keyboard;
input::Mouse mouse;
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

// Function to update the positions and velocities of bodies
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

// Function to render individual bodies with a buffer
void RenderBodyWithBuffer(std::shared_ptr<graphics::Buffer2D> buffer,
                          const Body& body, int numSegments = 100) {
  std::vector<ColoredPoint2D> points;
  float radius = 8 * std::log(body.mass) / std::log(1.0e10f);  // Scale radius based on the mass
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

// Function to render all bodies
void RenderBodies(GraphicsManagerImpl* gfxManager, const std::vector<Body>& bodies) {
  for (size_t i = 0; i < bodies.size(); ++i) {
    std::shared_ptr<graphics::Buffer2D> buffer = (i % 3 == 0) ? gfxManager->polyBuffer
                                        : (i % 3 == 1) ? gfxManager->polyBuffer2
                                        : gfxManager->polyBuffer3;
    RenderBodyWithBuffer(buffer, bodies[i]);
  }
}

// Initialize Graphics Manager and Bodies
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

  // Dynamically create n bodies with random positions, velocities, and masses
  int n = 2000;  // Number of bodies
  for (int i = 0; i < n; ++i) {
    float mass = static_cast<float>(rand()) / RAND_MAX * 1e12f + 1e10f;  // Random mass
    Vector2 position = {static_cast<float>( rand() % 1900),static_cast<float>( rand() % 1900)};  // Random position
    Vector2 velocity = {0,0};  // Random velocity
    Color color = {rand() % 255, rand() % 255, rand() % 255, 255};  // Random color

    bodies.push_back({position, velocity, mass, color});
  }
}

// Global camera settings
float defaultzoom = 0.4f;       // Default zoom level
float zoom = 0.0f;              // Global zoom adjustment

// Render the scene
void GraphicsManagerImpl::Render() {
  if (mContext->isReady) {
    mContext->BeginDrawing();
    float x = 0;
    float y = 0;
    // Handle panning with mouse drag
    if (mouse.IsButtonDown(MOUSE_BUTTON_LEFT)) {
      input::MousePosition delta = mouse.GetMouseDelta();
      x -=
          delta.x * (defaultzoom + zoom);  // Adjust offset by zoom level
      y -=
          delta.y * (defaultzoom + zoom);  // Adjust offset by zoom level
    }

    // Handle zoom with mouse wheel
    float mouseWheelMove = mouse.GetMouseWheelMove();
    zoom += mouseWheelMove * 0.05f;  // Adjust zoom speed

    // Clamp zoom level to avoid extreme values
    zoom = std::clamp(zoom, -defaultzoom, 5.0f - defaultzoom);

    // Set the camera offset and zoom
    auto camera = mContext->GetCamera();
    camera->IncreaseOffsetX(-x);
    camera->IncreaseOffsetY(-y);
    camera->SetTargetX(20.0f);
    camera->SetTargetY(20.0f);
    camera->SetRotation(0.0f);
    camera->SetZoom(defaultzoom + zoom);  // Apply the zoom change

    // Begin camera rendering
    camera->BeginCamera();

    // Update and render bodies
    UpdateBodies(bodies);
    RenderBodies(this, bodies);

    // Clear the screen with a transparency effect
    mContext->Clear(Color(0, 0, 0, 0));

    mContext->EndDrawing();

    // Increment simulation time
    stime += deltaTime;
  }
}
