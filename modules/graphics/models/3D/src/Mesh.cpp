#include "Mesh.hpp"
#include <stdexcept>

namespace graphics{
// Constructors and Destructor
Mesh::Mesh() : vertexCount(0), triangleCount(0), vaoId(0) {}

Mesh::~Mesh() {
}

// Setters
void Mesh::SetVertices(const std::vector<float>& data) {
    vertices = data;
    vertexCount = static_cast<int>(data.size() / 3); // Assuming 3 components per vertex (x, y, z)
}

void Mesh::SetTexcoords(const std::vector<float>& data) {
    texcoords = data;
}

void Mesh::SetNormals(const std::vector<float>& data) {
    normals = data;
}

void Mesh::SetIndices(const std::vector<unsigned short>& data) {
    indices = data;
    triangleCount = static_cast<int>(data.size() / 3); // Assuming 3 indices per triangle
}

// Getters
const std::vector<float>& Mesh::GetVertices() const {
    return vertices;
}

const std::vector<float>& Mesh::GetTexcoords() const {
    return texcoords;
}

const std::vector<float>& Mesh::GetNormals() const {
    return normals;
}

const std::vector<unsigned short>& Mesh::GetIndices() const {
    return indices;
}

#include <cmath>
#include <external/stb_vorbis.c>

// Helper to generate an empty Mesh
Mesh Mesh::CreateMesh() {
    return Mesh();
}

// Create a sphere mesh
Mesh Mesh::CreateSphereMesh(float radius, int slices, int stacks) {
    Mesh sphereMesh;

    std::vector<float> vertices;
    std::vector<float> normals;
    std::vector<float> texcoords;
    std::vector<unsigned short> indices;

    for (int stack = 0; stack <= stacks; ++stack) {
        float phi = M_PI * stack / stacks; // Vertical angle
        for (int slice = 0; slice <= slices; ++slice) {
            float theta = 2.0f * M_PI * slice / slices; // Horizontal angle

            // Vertex position
            float x = radius * sinf(phi) * cosf(theta);
            float y = radius * cosf(phi);
            float z = radius * sinf(phi) * sinf(theta);

            vertices.push_back(x);
            vertices.push_back(y);
            vertices.push_back(z);

            // Normal vector
            normals.push_back(x / radius);
            normals.push_back(y / radius);
            normals.push_back(z / radius);

            // Texture coordinates
            texcoords.push_back(static_cast<float>(slice) / slices);
            texcoords.push_back(static_cast<float>(stack) / stacks);

            // Generate indices
            if (stack < stacks && slice < slices) {
                unsigned short first = (stack * (slices + 1)) + slice;
                unsigned short second = first + slices + 1;

                indices.push_back(first);
                indices.push_back(second);
                indices.push_back(first + 1);

                indices.push_back(second);
                indices.push_back(second + 1);
                indices.push_back(first + 1);
            }
        }
    }

    sphereMesh.SetVertices(vertices);
    sphereMesh.SetNormals(normals);
    sphereMesh.SetTexcoords(texcoords);
    sphereMesh.SetIndices(indices);

    return sphereMesh;
}

// Create a cube mesh
Mesh Mesh::CreateCubeMesh(float size) {
    Mesh cubeMesh;

    float halfSize = size / 2.0f;
    std::vector<float> vertices = {
        // Front face
        -halfSize, -halfSize, halfSize,
         halfSize, -halfSize, halfSize,
         halfSize,  halfSize, halfSize,
        -halfSize,  halfSize, halfSize,
        // Back face
        -halfSize, -halfSize, -halfSize,
        -halfSize,  halfSize, -halfSize,
         halfSize,  halfSize, -halfSize,
         halfSize, -halfSize, -halfSize,
        // Left face
        -halfSize, -halfSize, -halfSize,
        -halfSize, -halfSize,  halfSize,
        -halfSize,  halfSize,  halfSize,
        -halfSize,  halfSize, -halfSize,
        // Right face
         halfSize, -halfSize, -halfSize,
         halfSize,  halfSize, -halfSize,
         halfSize,  halfSize,  halfSize,
         halfSize, -halfSize,  halfSize,
        // Top face
        -halfSize,  halfSize, -halfSize,
        -halfSize,  halfSize,  halfSize,
         halfSize,  halfSize,  halfSize,
         halfSize,  halfSize, -halfSize,
        // Bottom face
        -halfSize, -halfSize, -halfSize,
         halfSize, -halfSize, -halfSize,
         halfSize, -halfSize,  halfSize,
        -halfSize, -halfSize,  halfSize,
    };

    std::vector<unsigned short> indices = {
        0, 1, 2, 2, 3, 0,       // Front
        4, 5, 6, 6, 7, 4,       // Back
        8, 9, 10, 10, 11, 8,    // Left
        12, 13, 14, 14, 15, 12, // Right
        16, 17, 18, 18, 19, 16, // Top
        20, 21, 22, 22, 23, 20  // Bottom
    };

    cubeMesh.SetVertices(vertices);
    cubeMesh.SetIndices(indices);

    return cubeMesh;
}

// Create a plane mesh
Mesh Mesh::CreatePlaneMesh(float width, float depth) {
    Mesh planeMesh;

    float halfWidth = width / 2.0f;
    float halfDepth = depth / 2.0f;

    std::vector<float> vertices = {
        -halfWidth, 0.0f, -halfDepth,
         halfWidth, 0.0f, -halfDepth,
         halfWidth, 0.0f,  halfDepth,
        -halfWidth, 0.0f,  halfDepth,
    };

    std::vector<float> texcoords = {
        0.0f, 0.0f,
        1.0f, 0.0f,
        1.0f, 1.0f,
        0.0f, 1.0f,
    };

    std::vector<unsigned short> indices = {
        0, 1, 2, 2, 3, 0
    };

    planeMesh.SetVertices(vertices);
    planeMesh.SetTexcoords(texcoords);
    planeMesh.SetIndices(indices);

    return planeMesh;
}

// Create a cylinder mesh
Mesh Mesh::CreateCylinderMesh(float radius, float height, int slices) {
    Mesh cylinderMesh;

    std::vector<float> vertices;
    std::vector<unsigned short> indices;

    float halfHeight = height / 2.0f;
    for (int i = 0; i <= slices; ++i) {
        float theta = 2.0f * M_PI * i / slices;
        float x = radius * cosf(theta);
        float z = radius * sinf(theta);

        // Bottom cap
        vertices.push_back(x);
        vertices.push_back(-halfHeight);
        vertices.push_back(z);

        // Top cap
        vertices.push_back(x);
        vertices.push_back(halfHeight);
        vertices.push_back(z);

        if (i > 0) {
            int offset = i * 2;
            indices.push_back(offset - 2);
            indices.push_back(offset);
            indices.push_back(offset - 1);

            indices.push_back(offset);
            indices.push_back(offset + 1);
            indices.push_back(offset - 1);
        }
    }

    cylinderMesh.SetVertices(vertices);
    cylinderMesh.SetIndices(indices);

    return cylinderMesh;
}

#include <raylib.h> // Include raylib for the Mesh structure

raylib::Mesh Mesh::ToRaylibMesh() const {
    raylib::Mesh raylibMesh;

    // Copy vertex data
    raylibMesh.vertexCount = vertexCount;
    raylibMesh.triangleCount = triangleCount;

    if (!vertices.empty()) {
        raylibMesh.vertices = new float[vertices.size()];
        std::memcpy(raylibMesh.vertices, vertices.data(), vertices.size() * sizeof(float));
    }

    if (!texcoords.empty()) {
        raylibMesh.texcoords = new float[texcoords.size()];
        std::memcpy(raylibMesh.texcoords, texcoords.data(), texcoords.size() * sizeof(float));
    }

    if (!normals.empty()) {
        raylibMesh.normals = new float[normals.size()];
        std::memcpy(raylibMesh.normals, normals.data(), normals.size() * sizeof(float));
    }

    if (!indices.empty()) {
        raylibMesh.indices = new unsigned short[indices.size()];
        std::memcpy(raylibMesh.indices, indices.data(), indices.size() * sizeof(unsigned short));
    }

    // Allocate and initialize default OpenGL VAO/VBO IDs
    raylibMesh.vaoId = vaoId;
    if (!vboIds.empty()) {
        raylibMesh.vboId = new unsigned int[vboIds.size()];
        std::memcpy(raylibMesh.vboId, vboIds.data(), vboIds.size() * sizeof(unsigned int));
    }

    return raylibMesh;
}

}