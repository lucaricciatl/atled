#ifndef IMESH_HPP
#define IMESH_HPP

#include <string>
#include <memory>

namespace resources {

class IMesh {
public:
    virtual ~IMesh() = default;

    // Load mesh data from a file
    virtual bool LoadFromFile(const std::string& fileName) = 0;

    // Unload mesh data
    virtual void Unload() = 0;

    // Check if the mesh is loaded
    virtual bool IsLoaded() const = 0;

    // Get the number of vertices
    virtual size_t GetVertexCount() const = 0;

    // Additional methods to access mesh data
    // virtual const std::vector<Vertex>& GetVertices() const = 0;
    // virtual const std::vector<unsigned int>& GetIndices() const = 0;

    // Other mesh-related methods
};

}
#endif // IMESH_HPP
