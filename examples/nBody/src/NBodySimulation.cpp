#include "NBodySimulation.hpp"
#include <random>
#include <FrameComponent.hpp>
#include <cmath>

// Constructor to initialize entities and body data
NBodySimulation::NBodySimulation(std::vector<std::shared_ptr<Entity>> entities)
    : entities(std::move(entities)) {
    InitializeBodyData();
}

// Initialize velocity and mass for each entity
void NBodySimulation::InitializeBodyData() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distVel(-50.0f, 50.0f);
    std::uniform_real_distribution<float> distMass(1e12f, 1e14f);

    bodies.reserve(entities.size()); // Reserve space for performance
    for (const auto& entity : entities) {
        Coordinates2D initialVelocity(distVel(gen), distVel(gen));
        float mass = distMass(gen);
        bodies.push_back({ initialVelocity, mass });
    }
}

// Calculate gravitational force between two bodies
Coordinates2D NBodySimulation::CalculateGravitationalForce(const Coordinates2D& pos1, float mass1,
    const Coordinates2D& pos2, float mass2) const {
    float dx = pos2.GetX() - pos1.GetX();
    float dy = pos2.GetY() - pos1.GetY();
    float distanceSquared = dx * dx + dy * dy + 1e-10f; // Prevent division by zero
    float distance = std::sqrt(distanceSquared);
    float forceMagnitude = (G * mass1 * mass2) / distanceSquared;

    return Coordinates2D(forceMagnitude * dx / distance, forceMagnitude * dy / distance);
}

// Build quadtree for the current entity positions
QuadTreeNode* NBodySimulation::BuildQuadTree() {
    float xMin = -1e6f, xMax = 1e6f, yMin = -1e6f, yMax = 1e6f; // Adjust based on simulation bounds
    QuadTreeNode* root = new QuadTreeNode({ (xMin + xMax) / 2, (yMin + yMax) / 2 }, xMin, xMax, yMin, yMax);

    for (size_t i = 0; i < entities.size(); ++i) {
        auto frameComponent = entities[i]->GetComponent<FrameComponent>();
        if (!frameComponent) continue;
        auto pos = frameComponent->GetPosition();
        Coordinates2D entityPos(pos->getX(), pos->getY());
        InsertEntity(root, i, entityPos, root->xMin, root->xMax, root->yMin, root->yMax);
    }
    return root;
}

// Main update loop using FMM
void NBodySimulation::Update(float dt) {
    QuadTreeNode* root = BuildQuadTree(); // Build quadtree

    std::vector<Coordinates2D> forces(entities.size(), Coordinates2D(0.0f, 0.0f));
    float theta = 0.5f; // Threshold for multipole approximation accuracy

    // Calculate forces using FMM
    for (size_t i = 0; i < entities.size(); ++i) {
        auto frameComponent = entities[i]->GetComponent<FrameComponent>();
        if (!frameComponent) continue;
        auto position = frameComponent->GetPosition();
        Coordinates2D entityPos(position->getX(), position->getY());
        ComputeForcesFMM(root, i, entityPos, forces, theta);
    }

    // Update positions and velocities
    UpdateBodies(forces, dt);

    delete root; // Clean up the quadtree
}

void NBodySimulation::UpdateBodies(const std::vector<Coordinates2D>& forces, float dt) {
    for (size_t i = 0; i < entities.size(); ++i) {
        auto frameComponent = entities[i]->GetComponent<FrameComponent>();
        if (!frameComponent) continue;

        float invMass = 1.0f / bodies[i].mass;
        Coordinates2D acceleration(forces[i].GetX() * invMass, forces[i].GetY() * invMass);

        // Update velocity with damping
        bodies[i].velocity = Coordinates2D(
            (bodies[i].velocity.GetX() + acceleration.GetX() * dt) * dampingFactor,
            (bodies[i].velocity.GetY() + acceleration.GetY() * dt) * dampingFactor
        );

        // Update position based on velocity
        Coordinates2D newPos(
            frameComponent->GetPosition()->getX() + bodies[i].velocity.GetX() * dt,
            frameComponent->GetPosition()->getY() + bodies[i].velocity.GetY() * dt
        );

        frameComponent->SetPosition(newPos.GetX(), newPos.GetY(), 0.0f);
    }
}


// Insert an entity into the quadtree
void NBodySimulation::InsertEntity(
    QuadTreeNode* node,
    size_t entityIndex,
    const Coordinates2D& pos,
    float xMin,
    float xMax,
    float yMin,
    float yMax,
    size_t maxEntitiesPerNode
) {
    // Update node's mass and center of mass
    float entityMass = bodies[entityIndex].mass;
    float totalMass = node->mass + entityMass;
    node->centerOfMass = (node->centerOfMass * node->mass + pos * entityMass) * (1/totalMass);
    node->mass = totalMass;

    // If the node is a leaf and has space, add the entity here
    if (node->isLeaf) {
        node->entities.push_back(entityIndex);

        // If the node exceeds capacity, subdivide it
        if (node->entities.size() > maxEntitiesPerNode) {
            SubdivideNode(node);
        }
        return;
    }

    // If the node is not a leaf, determine the correct child node
    size_t quadrant = GetQuadrant(pos, node->center);

    // Recursively insert into the appropriate child
    InsertEntity(node->children[quadrant], entityIndex, pos,
        node->children[quadrant]->xMin, node->children[quadrant]->xMax,
        node->children[quadrant]->yMin, node->children[quadrant]->yMax, maxEntitiesPerNode);
}

// Determine the quadrant of a position relative to a node's center
size_t NBodySimulation::GetQuadrant(const Coordinates2D& pos, const Coordinates2D& center) const {
    if (pos.GetX() < center.GetX()) {
        if (pos.GetY() < center.GetY()) return 2; // Bottom-left
        else return 0; // Top-left
    }
    else {
        if (pos.GetY() < center.GetY()) return 3; // Bottom-right
        else return 1; // Top-right
    }
}

// Subdivide a quadtree node into 4 child nodes
void NBodySimulation::SubdivideNode(QuadTreeNode* node) {
    node->isLeaf = false;
    float xMid = (node->xMin + node->xMax) / 2;
    float yMid = (node->yMin + node->yMax) / 2;

    // Create child nodes with updated bounds
    node->children[0] = new QuadTreeNode({ (node->xMin + xMid) / 2, (yMid + node->yMax) / 2 },
        node->xMin, xMid, yMid, node->yMax); // Top-left
    node->children[1] = new QuadTreeNode({ (xMid + node->xMax) / 2, (yMid + node->yMax) / 2 },
        xMid, node->xMax, yMid, node->yMax); // Top-right
    node->children[2] = new QuadTreeNode({ (node->xMin + xMid) / 2, (node->yMin + yMid) / 2 },
        node->xMin, xMid, node->yMin, yMid); // Bottom-left
    node->children[3] = new QuadTreeNode({ (xMid + node->xMax) / 2, (node->yMin + yMid) / 2 },
        xMid, node->xMax, node->yMin, yMid); // Bottom-right

    // Re-insert entities into child nodes
    std::vector<size_t> entitiesToReinsert = std::move(node->entities);
    node->entities.clear();

    for (size_t entityIndex : entitiesToReinsert) {
        auto frameComponent = entities[entityIndex]->GetComponent<FrameComponent>();
        if (!frameComponent) continue;

        auto pos = frameComponent->GetPosition();
        Coordinates2D coord(pos->getX(), pos->getY());
        size_t quadrant = GetQuadrant(coord, node->center);

        InsertEntity(node->children[quadrant], entityIndex, coord,
            node->children[quadrant]->xMin, node->children[quadrant]->xMax,
            node->children[quadrant]->yMin, node->children[quadrant]->yMax);
    }
}

// Compute forces using FMM
void NBodySimulation::ComputeForcesFMM(const QuadTreeNode* node, size_t entityIndex, const Coordinates2D& entityPos,
    std::vector<Coordinates2D>& forces, float theta) const {
    if (node->isLeaf && (node->entities.size() == 0 || (node->entities.size() == 1 && node->entities[0] == entityIndex))) {
        return; // Skip empty nodes or nodes containing only the current entity
    }

    float distance = CalculateDistance(entityPos, node->centerOfMass) + 1e-10f;
    float size = CalculateNodeSize(node);

    if ((node->isLeaf && node->entities.size() <= 1) || (size / distance) < theta) {
        // Use multipole approximation
        Coordinates2D approxForce = ApproximateForce(entityPos, node->centerOfMass, node->mass, bodies[entityIndex].mass);
        forces[entityIndex] = forces[entityIndex] + approxForce;
    }
    else {
        // Recurse into child nodes
        for (const QuadTreeNode* child : node->children) {
            if (child && child->mass > 0.0f) {
                ComputeForcesFMM(child, entityIndex, entityPos, forces, theta);
            }
        }
    }
}

// Approximate force using multipole expansion
Coordinates2D NBodySimulation::ApproximateForce(const Coordinates2D& entityPos, const Coordinates2D& centerOfMass,
    float massNode, float massEntity) const {
    float dx = centerOfMass.GetX() - entityPos.GetX();
    float dy = centerOfMass.GetY() - entityPos.GetY();
    float distanceSquared = dx * dx + dy * dy + 1e-10f;
    float distance = std::sqrt(distanceSquared);
    float forceMagnitude = (G * massEntity * massNode) / distanceSquared;

    return Coordinates2D(forceMagnitude * dx / distance, forceMagnitude * dy / distance);
}

// Calculate the distance between two positions
float NBodySimulation::CalculateDistance(const Coordinates2D& pos1, const Coordinates2D& pos2) const {
    float dx = pos2.GetX() - pos1.GetX();
    float dy = pos2.GetY() - pos1.GetY();
    return std::sqrt(dx * dx + dy * dy);
}

// Calculate the size of a node (length of one side)
float NBodySimulation::CalculateNodeSize(const QuadTreeNode* node) const {
    return std::max(node->xMax - node->xMin, node->yMax - node->yMin);
}

void NBodySimulation::SetDampingFactor(float damping) {
    dampingFactor = damping;
}

void NBodySimulation::SetMinDistanceThreshold(float threshold) {
    minDistanceThreshold = threshold;
}
