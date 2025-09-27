#ifndef NBODY_SIMULATION_HPP
#define NBODY_SIMULATION_HPP

#include <Entity.hpp>
#include <Point2D.hpp>
#include <memory>
#include <vector>

namespace nbody {
// Constants
constexpr float G = 6.67430e-11f;  // Gravitational constant
constexpr float damping = 0.99f;   // Damping factor for velocity updates

// Structure to hold body data
struct Body {
    Coordinates2D velocity;
    float mass;
};

// QuadTreeNode structure for Fast Multipole Method
struct QuadTreeNode {
    std::vector<size_t> entities;           // Indices of entities in this node
    Coordinates2D center;                   // Center of the node
    float mass = 0.0f;                      // Total mass in the node
    Coordinates2D centerOfMass;             // Center of mass for the node
    QuadTreeNode* children[4] = {nullptr};  // Child nodes
    bool isLeaf = true;

    // Bounds of the node
    float xMin, xMax, yMin, yMax;

    QuadTreeNode(const Coordinates2D& center, float xMin, float xMax, float yMin, float yMax)
        : center(center), centerOfMass(0.0f, 0.0f), xMin(xMin), xMax(xMax), yMin(yMin), yMax(yMax) {}

    ~QuadTreeNode() {
        for (auto* child : children) {
            delete child;
        }
    }
};

class NBodySimulation {
   public:
    // Constructor
    explicit NBodySimulation(std::vector<std::shared_ptr<Entity>> entities);

    // Update the simulation
    void Update(float dt);

   private:
    std::vector<std::shared_ptr<Entity>> entities;  // List of entities
    std::vector<Body> bodies;                       // Body data (mass and velocity)

    // Initialize body data
    void InitializeBodyData();

    // Calculate gravitational force between two bodies
    Coordinates2D CalculateGravitationalForce(const Coordinates2D& pos1, float mass1, const Coordinates2D& pos2,
                                              float mass2) const;

    // Build the quadtree for FMM
    QuadTreeNode* BuildQuadTree();

    // Calculate node size
    float CalculateNodeSize(const QuadTreeNode* node) const;

    // Calculate distance between two positions
    float CalculateDistance(const Coordinates2D& pos1, const Coordinates2D& pos2) const;

    // Approximate force using multipole expansion
    Coordinates2D ApproximateForce(const Coordinates2D& entityPos, const Coordinates2D& centerOfMass, float massNode,
                                   float massEntity) const;

    // Insert an entity into the quadtree
    void InsertEntity(QuadTreeNode* node, size_t entityIndex, const Coordinates2D& pos, float xMin, float xMax,
                      float yMin, float yMax, size_t maxEntities = 4);

    // Subdivide a quadtree node into 4 child nodes
    void SubdivideNode(QuadTreeNode* node);

    // Determine the quadrant of a position relative to a node's center
    size_t GetQuadrant(const Coordinates2D& pos, const Coordinates2D& center) const;

    // Compute forces using FMM
    void ComputeForcesFMM(const QuadTreeNode* node, size_t entityIndex, const Coordinates2D& entityPos,
                          std::vector<Coordinates2D>& forces, float theta) const;

    // Update bodies based on computed forces
    void UpdateBodies(const std::vector<Coordinates2D>& forces, float dt);

    void SetDampingFactor(float damping);
    void SetMinDistanceThreshold(float threshold);

    float dampingFactor = 0.9999f;       // Damping applied to gravitational force
    float minDistanceThreshold = 30.0f;  // Minimum distance threshold for force calculation
};

}  // namespace nbody

#endif  // NBODY_SIMULATION_HPP
