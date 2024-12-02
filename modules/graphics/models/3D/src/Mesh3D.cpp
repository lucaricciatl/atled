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


    DrawModel(mModel, Vector3{ 0,0,0 }, 1.0f, RED);
    ::DrawGrid(4, 1.0);
}

void Mesh3D::SetMesh() {

    mModel = LoadModelFromMesh(::GenMeshCube(2, 2, 2));
    mModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].color = RED;

};

}