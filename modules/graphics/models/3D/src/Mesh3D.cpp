#include "Mesh3D.hpp"
#include <iostream>
#include <fstream>

namespace graphics{

// Constructor

Mesh3D::Mesh3D() {

}
Mesh3D::Mesh3D(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices)
    : vertices(vertices), indices(indices) {

}

Mesh3D::~Mesh3D() {

}

// Getters
const std::vector<Vertex>& Mesh3D::GetVertices() const {
    return vertices;
}

const std::vector<unsigned int>& Mesh3D::GetIndices() const {
    return indices;
}

// Private method to set up GPU buffers
void Mesh3D::Draw() {

}

}