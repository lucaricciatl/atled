#ifndef COLLISION_CHECKER_HPP
#define COLLISION_CHECKER_HPP

#include <vector>
#include <memory>
#include "Mesh.hpp" // Include your Mesh class or struct header

class CollisionChecker {
public:
    // Constructor that takes a vector of meshes
    CollisionChecker(const std::vector<std::shared_ptr<graphics::Mesh>>& meshes);

    // Adds a new mesh to the list
    void AddMesh(std::shared_ptr<graphics::Mesh> mesh);

    // Removes a mesh from the list
    void RemoveMesh(std::shared_ptr<graphics::Mesh> mesh);

    // Checks for collisions between all meshes and returns pairs of colliding meshes
    std::vector<std::pair<std::shared_ptr<graphics::Mesh>, std::shared_ptr<graphics::Mesh>>> CheckCollisions() const;

    // Checks if a specific mesh collides with any other mesh in the list
    std::vector<std::shared_ptr<graphics::Mesh>> CheckCollisions(const std::shared_ptr<graphics::Mesh>& mesh) const;

private:
    // A vector holding all the meshes
    std::vector<std::shared_ptr<graphics::Mesh>> meshes;

    // Helper function to check if two meshes collide (e.g., AABB intersection)
    bool AreMeshesColliding(const graphics::Mesh& mesh1, const graphics::Mesh& mesh2) const;
};

#endif // COLLISION_CHECKER_HPP
