#ifndef MESH_HPP
#define MESH_HPP

#include <vector>
#include <memory>
#include "raylib.hpp" // Include Matrix definition or replace with a suitable type

namespace graphics{
class Mesh {
public:
    // Constructors and Destructor
    Mesh();
    ~Mesh();

    // Mesh Data Management
    void SetVertices(const std::vector<float>& vertices);
    void SetTexcoords(const std::vector<float>& texcoords);
    void SetNormals(const std::vector<float>& normals);
    void SetIndices(const std::vector<unsigned short>& indices);

    const std::vector<float>& GetVertices() const;
    const std::vector<float>& GetTexcoords() const;
    const std::vector<float>& GetNormals() const;
    const std::vector<unsigned short>& GetIndices() const;


    // Getter for OpenGL VAO ID
    unsigned int GetVAO() const { return vaoId; }


    static Mesh CreateSphereMesh(float radius = 1.0f, int slices = 16, int stacks = 16);
    static Mesh CreateCubeMesh(float size = 1.0f);
    static Mesh CreatePlaneMesh(float width, float depth, int subdivisionsWidth, int subdivisionsDepth);
    static Mesh CreateCylinderMesh(float radius = 1.0f, float height = 1.0f, int slices = 16);
    static Mesh CreateMesh();

    raylib::Mesh ToRaylibMesh() const;
    const std::vector<math::Vector3>& GetOrderedVertices() const;

private:
    int vertexCount;              // Number of vertices stored in arrays
    int triangleCount;            // Number of triangles stored (indexed or not)

    std::vector<float> vertices;  // Vertex positions
    std::vector<float> texcoords; // Texture coordinates
    std::vector<float> normals;   // Normals
    std::vector<unsigned short> indices; // Indices

    // OpenGL identifiers
    unsigned int vaoId;           // OpenGL Vertex Array Object id
    std::vector<unsigned int> vboIds; // OpenGL Vertex Buffer Objects ids
};



}
#endif // MESH_HPP
