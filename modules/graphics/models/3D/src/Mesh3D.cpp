#include "Mesh3D.hpp"
#include <iostream>
#include <fstream>
#include "raylib.hpp"

namespace graphics{
using namespace raylib;
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
    DrawModel(mModel, Vector3{ -5,-5,-5 }, 2.0f, WHITE);
    DrawModel(mModel, Vector3{ 5,-5,-5 }, 2.0f, WHITE);
    DrawModel(mModel, Vector3{ -5,5,-5 }, 2.0f, WHITE);
    DrawModel(mModel, Vector3{ -5,5,5 }, 2.0f, WHITE);
    ::DrawGrid(10, 1.0);
}

void Mesh3D::SetMesh() {
    Mesh mesh = GenMeshCube(2.0f, 2.0f, 2.0f);
    this->mModel = LoadModelFromMesh(mesh);
};

}