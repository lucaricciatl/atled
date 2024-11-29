#include "Mesh.hpp"
#include <iostream>
#include <fstream>

namespace graphics{

// Constructor
Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices)
    : vertices(vertices), indices(indices) {

}

// Destructor
Mesh::~Mesh() {

}

// Getters
const std::vector<Vertex>& Mesh::GetVertices() const {
    return vertices;
}

const std::vector<unsigned int>& Mesh::GetIndices() const {
    return indices;
}

// Private method to set up GPU buffers
void Mesh::Draw() {

}

}