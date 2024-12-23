#include "PhysicsManager.hpp"
#include <iostream>
#include "body.hpp"

namespace physics {

// Placeholder implementations for PhysicsConfig and Body
struct PhysicsConfig {
    // Add physics configuration parameters here
};


// Constructor
PhysicsManager::PhysicsManager()
    : mConfigs(std::make_shared<PhysicsConfig>()),
      mRunning(false),
      mCollider(ColliderFactory::CreateSimpleCollider()) {}

// Destructor
PhysicsManager::~PhysicsManager() {
    // Ensure the thread is properly joined before destruction
    if (mThread && mThread->joinable()) {
        mRunning = false;
        mThread->join();
    }
}


// Initialize Physics Manager
void PhysicsManager::Init() {
    Start();
}

// Start Physics Processing
void PhysicsManager::Start() {
    std::lock_guard<std::mutex> lock(mMutex);
    if (!mRunning) {
        mRunning = true;
        mThread = std::make_unique<std::thread>(&PhysicsManager::Run, this);
        std::cout << "PhysicsManager started." << std::endl;
    }
}

// Update Physics Manager (could be called per frame)
void PhysicsManager::Update() {
    std::lock_guard<std::mutex> lock(mMutex);
    if (mRunning) {
        // Update physics state here
    }
}

void PhysicsManager::ComputeCollisions() {
    // Add all bodies to the collider
    for (const auto& body : bodies) {
        if (body) {
            mCollider->AddBody(body.get());
        }
    }

    // Check for collisions between every pair of bodies
    for (size_t i = 0; i < bodies.size(); ++i) {
        Body* a = bodies[i].get();
        if (!a) continue;

        for (size_t j = i + 1; j < bodies.size(); ++j) {
            Body* b = bodies[j].get();
            if (!b) continue;

            // Use the direct two-body detection function
            if (mCollider->DetectCollisions(a, b)) {
                // Handle the collision between a and b
                // This could include resolving overlaps, applying impulses,
                // or triggering game events.
            }
        }
    }
}



// Compute Reactions
void PhysicsManager::ComputeReactions() {
    // Implement collision response logic here
    std::cout << "Computing reactions." << std::endl;
}

// Compute Deformations
void PhysicsManager::ComputeDeformations() {
    // Implement deformation calculations here
    std::cout << "Computing deformations." << std::endl;
}

// Compute Cinematics
void PhysicsManager::ComputeCinematics() {
    // Implement cinematic computations here
    std::cout << "Computing cinematics." << std::endl;
}

// Thread Loop Function
void PhysicsManager::Run() {
    float dt = 0.001f;
    mCollider->Setdt(dt);
    while (mRunning) {
        {
            std::lock_guard<std::mutex> lock(mMutex);

            // Perform physics computations
            ComputeCollisions();
            ComputeReactions();
            ComputeDeformations();
            ComputeCinematics();
            for (auto body : bodies) {
                body->UpdatePhysics(dt);
            }
        }
        // Sleep or wait for a fixed timestep
        std::this_thread::sleep_for(std::chrono::milliseconds(1)); // ~60 FPS
    }
}

void PhysicsManager::HandleCollision(Body* bodyA, Body* bodyB) {
}


};