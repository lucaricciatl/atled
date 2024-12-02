#ifndef MESH_HPP
#define MESH_HPP

#include <string>
#include <vector>
#include <memory>
#include "raylib.hpp"
#include "Model3D.hpp"

namespace graphics{
using namespace raylib;

// Vertex structure
struct Vertex {
    Vector3 position;  // Position in 3D space
    Vector3 normal;    // Normal vector
    Vector2 texCoords; // Texture coordinates
};

class Mesh3D : public Model3D {
public:
    // Constructor
    Mesh3D();
    Mesh3D(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);
    ~Mesh3D();

    // Getters
    const std::vector<Vertex>& GetVertices() const;
    const std::vector<unsigned int>& GetIndices() const;
    void Draw();
    void SetMesh();

private:
    // Vertex and index data
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    raylib::Model mModel; 
};


}
#endif // MESH_HPP