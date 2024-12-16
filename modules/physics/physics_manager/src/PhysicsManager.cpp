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

        for (const auto& body : bodies) {
            if (body) {
                mCollider->AddBody(body.get());
            }
        }

        // Detect collisions
        for (const auto& body : bodies) {
            if (!body) continue;

            auto potentialCollisions = std::vector<Body*>();
            mCollider->Retrieve(potentialCollisions, body->GetBoundingBox());

            for (Body* other : potentialCollisions) {
                if (body.get() == other) continue; // Skip self-collision

                if (body->GetBoundingBox().Intersects(other->GetBoundingBox())) {
                    HandleCollision(body.get(), other);
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
    while (mRunning) {
        {
            std::lock_guard<std::mutex> lock(mMutex);

            for (auto body : bodies) {
                body->UpdatePhysics(0.01f);
            }
            // Perform physics computations
            ComputeCollisions();
            ComputeReactions();
            ComputeDeformations();
            ComputeCinematics();
        }
        // Sleep or wait for a fixed timestep
        std::this_thread::sleep_for(std::chrono::milliseconds(5)); // ~60 FPS
    }
}

void PhysicsManager::HandleCollision(Body* bodyA, Body* bodyB) {
}


};