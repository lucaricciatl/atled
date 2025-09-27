#ifndef RESOURCE_HPP
#define RESOURCE_HPP

#include <string>
#include <memory>
#include <stdexcept>

namespace resources {

/**
 * @brief Enum class representing resource types.
 */
enum class ResourceType {
    Mesh,
    Texture,
    Material,
    Shader,
    Audio,
    Unknown
};

class Resource {
public:
    Resource() = default;

    explicit Resource(const std::string& fileName) {
        Load(fileName);
    }

    ~Resource() {
        Unload();
    }

    bool Load(const std::string& fileName) {
        return true;
    }

    void Unload() {
    }

    bool IsLoaded() const {
        return true;
    }

private:

};

}

#endif // RESOURCE_HPP
