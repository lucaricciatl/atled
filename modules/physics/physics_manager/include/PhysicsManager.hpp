#ifndef PHYSICS_MANAGER_H
#define PHYSICS_MANAGER_H

#include <memory>
#include <thread>
#include <vector>
#include <mutex>



namespace physics {
// Forward declarations
struct PhysicsConfig;
class Body;


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
    void AddBody(std::shared_ptr<Body> shape);

    void ComputeCollisions();
    void ComputeReactions();
    void ComputeDeformations();
    void ComputeCinematics();

protected:
    void Run(); // Thread loop function

private:
    // Member Variables
    std::unique_ptr<std::thread> mThread;
    std::shared_ptr<PhysicsConfig> mConfigs;

    // Synchronization
    std::mutex mMutex;
    bool mRunning;
};

};
#endif // PHYSICS_MANAGER_H
