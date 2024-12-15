#ifndef PHYSICS_MANAGER_H
#define PHYSICS_MANAGER_H

#include <memory>
#include <thread>
#include <vector>
#include <mutex>
#include "body.hpp"
#include "ICollider.hpp"
#include "ColliderFactory.hpp"
#include "SimpleCollider.hpp"
#include "AdvancedCollider.hpp"

namespace physics {
// Forward declarations
struct PhysicsConfig;


class PhysicsManager {
public:
    // Constructor and Destructor
    PhysicsManager();
    ~PhysicsManager();

    // Deleted copy constructor and assignment operator to prevent copying
    PhysicsManager(const PhysicsManager&) = delete;
    PhysicsManager& operator=(const PhysicsManager&) = delete;

    void Start();
    void Init();
    void Update();

    void AddBody(std::shared_ptr<Body> aBody) {
        bodies.emplace_back(aBody);
    }

    void ComputeCollisions();
    void ComputeReactions();
    void ComputeDeformations();
    void ComputeCinematics();

protected:
    void Run(); // Thread loop function

private:
    // Member Variables
    std::shared_ptr<ICollider> mCollider;
    std::unique_ptr<std::thread> mThread;
    std::shared_ptr<PhysicsConfig> mConfigs;
    std::vector<std::shared_ptr<Body>> bodies;
    // Synchronyization
    std::mutex mMutex;
    bool mRunning;


};



};
#endif // PHYSICS_MANAGER_H
