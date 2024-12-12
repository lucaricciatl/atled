#include "CollisionChecker.hpp"
#include "BoundingBox.hpp" // Assuming Mesh has a bounding box or similar property

// Constructor
CollisionChecker::CollisionChecker(const std::vector<std::shared_ptr<Mesh>>& meshes)
    : meshes(meshes) {}

// Adds a new mesh to the list
void CollisionChecker::AddMesh(std::shared_ptr<Mesh> mesh) {
    meshes.push_back(mesh);
}

// Removes a mesh from the list
void CollisionChecker::RemoveMesh(std::shared_ptr<Mesh> mesh) {
    meshes.erase(std::remove(meshes.begin(), meshes.end(), mesh), meshes.end());
}

// Checks for collisions between all meshes and returns pairs of colliding meshes
std::vector<std::pair<std::shared_ptr<Mesh>, std::shared_ptr<Mesh>>> CollisionChecker::CheckCollisions() const {
    std::vector<std::pair<std::shared_ptr<Mesh>, std::shared_ptr<Mesh>>> collidingPairs;

    for (size_t i = 0; i < meshes.size(); ++i) {
        for (size_t j = i + 1; j < meshes.size(); ++j) {
            if (AreMeshesColliding(*meshes[i], *meshes[j])) {
                collidingPairs.emplace_back(meshes[i], meshes[j]);
            }
        }
    }

    return collidingPairs;
}

// Checks if a specific mesh collides with any other mesh in the list
std::vector<std::shared_ptr<Mesh>> CollisionChecker::CheckCollisions(const std::shared_ptr<Mesh>& mesh) const {
    std::vector<std::shared_ptr<Mesh>> collidingMeshes;

    for (const auto& otherMesh : meshes) {
        if (mesh != otherMesh && AreMeshesColliding(*mesh, *otherMesh)) {
            collidingMeshes.push_back(otherMesh);
        }
    }

    return collidingMeshes;
}

// Helper function to check if two meshes collide (e.g., AABB intersection)
bool CollisionChecker::AreMeshesColliding(const Mesh& mesh1, const Mesh& mesh2) const {
    // Assume the Mesh class has a method or property to get the bounding box
    const BoundingBox& box1 = mesh1.GetBoundingBox();
    const BoundingBox& box2 = mesh2.GetBoundingBox();

    // AABB intersection logic
    return (box1.min.x <= box2.max.x && box1.max.x >= box2.min.x) &&
           (box1.min.y <= box2.max.y && box1.max.y >= box2.min.y) &&
           (box1.min.z <= box2.max.z && box1.max.z >= box2.min.z);
}
