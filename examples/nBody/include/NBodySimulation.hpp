#include <Point2D.hpp>
#include <Entity.hpp>
class NBodySimulation {
public:
    // Constructor accepting entities
    NBodySimulation(std::vector<std::shared_ptr<Entity>> entities);

    // Update method to apply physics
    void Update(float dt);

private:
    struct BodyData {
        Coordinates2D velocity;
        float mass;
    };

    std::vector<std::shared_ptr<Entity>> entities;
    std::vector<BodyData> bodies;

    constexpr static float G = 6.67430e-11f;
    constexpr static float damping = 0.999f;

    Coordinates2D CalculateGravitationalForce(const Coordinates2D& pos1, float mass1,
        const Coordinates2D& pos2, float mass2) const;
    void InitializeBodyData(); // Internal method to initialize velocity and mass
};
