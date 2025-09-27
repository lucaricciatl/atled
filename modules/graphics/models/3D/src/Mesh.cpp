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

const std::vector<math::Vector3>& Mesh::GetOrderedVertices() const {
    // Clear and populate a cache for ordered vertices if needed
    static std::vector<math::Vector3> OrderedPoints; // Thread-local or mutable caching is better in larger codebases
    OrderedPoints.clear();

    for (size_t i = 0; i < vertices.size(); i += 3) { // Step through the raw array in groups of 3 (xyz)
        float x = vertices[i];     // x-coordinate
        float y = vertices[i + 1]; // y-coordinate
        float z = vertices[i + 2]; // z-coordinate
        math::Vector3 v(x, y, z);
        OrderedPoints.emplace_back(v); // Add a new Vector3 to the list
    }

    return OrderedPoints; // Return the vector of Vector3s
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

    // Vertices (positions only)
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

    // Normals
    std::vector<float> normals = {
        // Front face
        0.0f,  0.0f,  1.0f,
        0.0f,  0.0f,  1.0f,
        0.0f,  0.0f,  1.0f,
        0.0f,  0.0f,  1.0f,
        // Back face
        0.0f,  0.0f, -1.0f,
        0.0f,  0.0f, -1.0f,
        0.0f,  0.0f, -1.0f,
        0.0f,  0.0f, -1.0f,
        // Left face
       -1.0f,  0.0f,  0.0f,
       -1.0f,  0.0f,  0.0f,
       -1.0f,  0.0f,  0.0f,
       -1.0f,  0.0f,  0.0f,
       // Right face
       1.0f,  0.0f,  0.0f,
       1.0f,  0.0f,  0.0f,
       1.0f,  0.0f,  0.0f,
       1.0f,  0.0f,  0.0f,
       // Top face
       0.0f,  1.0f,  0.0f,
       0.0f,  1.0f,  0.0f,
       0.0f,  1.0f,  0.0f,
       0.0f,  1.0f,  0.0f,
       // Bottom face
       0.0f, -1.0f,  0.0f,
       0.0f, -1.0f,  0.0f,
       0.0f, -1.0f,  0.0f,
       0.0f, -1.0f,  0.0f,
    };

    // Indices
    std::vector<unsigned short> indices = {
        0, 1, 2, 2, 3, 0,       // Front
        4, 5, 6, 6, 7, 4,       // Back
        8, 9, 10, 10, 11, 8,    // Left
        12, 13, 14, 14, 15, 12, // Right
        16, 17, 18, 18, 19, 16, // Top
        20, 21, 22, 22, 23, 20  // Bottom
    };

    std::vector<float> texcoords = {
        0.0f, 0.0f,
        1.0f, 0.0f,
        1.0f, 1.0f,
        0.0f, 1.0f,
        1.0f, 0.0f,
        1.0f, 1.0f,
        0.0f, 1.0f,
        0.0f, 0.0f,
        0.0f, 1.0f,
        0.0f, 0.0f,
        1.0f, 0.0f,
        1.0f, 1.0f,
        1.0f, 1.0f,
        0.0f, 1.0f,
        0.0f, 0.0f,
        1.0f, 0.0f,
        1.0f, 0.0f,
        1.0f, 1.0f,
        0.0f, 1.0f,
        0.0f, 0.0f,
        0.0f, 0.0f,
        1.0f, 0.0f,
        1.0f, 1.0f,
        0.0f, 1.0f
    }; 
    cubeMesh.SetVertices(vertices); // Set vertex positions
    cubeMesh.SetNormals(normals);   // Set normals
    cubeMesh.SetTexcoords(texcoords);
    cubeMesh.SetIndices(indices);   // Set indices
    return cubeMesh;
}

Mesh Mesh::CreatePlaneMesh(float width, float depth, int subdivisionsWidth, int subdivisionsDepth) {
    Mesh planeMesh;

    if (subdivisionsWidth < 1 || subdivisionsDepth < 1) {
        throw std::invalid_argument("Subdivision counts must be greater than 0.");
    }

    float halfWidth = width / 2.0f;
    float halfDepth = depth / 2.0f;

    float dx = width / subdivisionsWidth;   // Step size along width
    float dz = depth / subdivisionsDepth;  // Step size along depth

    std::vector<float> vertices;
    std::vector<float> texcoords;
    std::vector<unsigned short> indices;

    // Generate vertices and texture coordinates
    for (int z = 0; z <= subdivisionsDepth; ++z) {
        for (int x = 0; x <= subdivisionsWidth; ++x) {
            float px = -halfWidth + x * dx;
            float pz = -halfDepth + z * dz;
            vertices.push_back(px);  // x position
            vertices.push_back(0.0f); // y position (plane is flat)
            vertices.push_back(pz);  // z position

            texcoords.push_back(static_cast<float>(x) / subdivisionsWidth); // u
            texcoords.push_back(static_cast<float>(z) / subdivisionsDepth); // v
        }
    }

    // Generate indices
    for (int z = 0; z < subdivisionsDepth; ++z) {
        for (int x = 0; x < subdivisionsWidth; ++x) {
            int topLeft = z * (subdivisionsWidth + 1) + x;
            int topRight = topLeft + 1;
            int bottomLeft = (z + 1) * (subdivisionsWidth + 1) + x;
            int bottomRight = bottomLeft + 1;

            // First triangle
            indices.push_back(topLeft);
            indices.push_back(bottomLeft);
            indices.push_back(topRight);

            // Second triangle
            indices.push_back(topRight);
            indices.push_back(bottomLeft);
            indices.push_back(bottomRight);
        }
    }

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



raylib::Mesh Mesh::ToRaylibMesh() const {
    raylib::Mesh raylibMesh;
    raylibMesh.animVertices = NULL;
    raylibMesh.normals = NULL;
    raylibMesh.animNormals =NULL;
    raylibMesh.colors =NULL;
    raylibMesh.tangents =NULL;
    raylibMesh.texcoords2 = NULL;
    raylibMesh.boneIds = NULL;
    raylibMesh.boneWeights = NULL;
    

    // Copy vertex data
    raylibMesh.vertexCount = vertexCount;
    raylibMesh.triangleCount = triangleCount;

    if (!vertices.empty()) {
        raylibMesh.vertices = new float[vertices.size()];
        std::copy(vertices.data(), vertices.data() + vertices.size(), raylibMesh.vertices);
    }

    if (!texcoords.empty()) {
        raylibMesh.texcoords = new float[texcoords.size()];
        std::copy(texcoords.data(), texcoords.data() + texcoords.size(), raylibMesh.texcoords);
    }

    if (!normals.empty()) {
        raylibMesh.normals = new float[normals.size()];
        std::copy(normals.data(), normals.data() + normals.size(), raylibMesh.normals);
    }

    if (!indices.empty()) {
        raylibMesh.indices = new unsigned short[indices.size()];
        std::copy(indices.data(), indices.data() + indices.size(), raylibMesh.indices);
    }

    // Allocate and initialize default OpenGL VAO/VBO IDs
    raylibMesh.vaoId = vaoId;
    if (!vboIds.empty()) {
        raylibMesh.vboId = new unsigned int[vboIds.size()];
        std::copy(vboIds.data(), vboIds.data() + vboIds.size(), raylibMesh.vboId);
    }

    return raylibMesh;
}


}