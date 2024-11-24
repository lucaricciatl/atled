#ifndef RESOURCE_HPP
#define RESOURCE_HPP

#include <string>
#include <memory>
#include <stdexcept>

/**
 * @brief Resource class template to handle different resource types (e.g., IMesh, ITexture, IMaterial).
 * 
 * @tparam T The resource type (e.g., IMesh, ITexture, IMaterial).
 */
template <typename T>
class Resource {
public:
    Resource() = default;

    /**
     * @brief Constructs a resource and loads it from a file.
     * 
     * @param fileName The file name to load the resource from.
     */
    explicit Resource(const std::string& fileName) {
        Load(fileName);
    }

    /**
     * @brief Destructor to ensure resource is unloaded.
     */
    ~Resource() {
        Unload();
    }

    /**
     * @brief Loads the resource from a file.
     * 
     * @param fileName The file name to load the resource from.
     * @return true if the resource was successfully loaded, false otherwise.
     */
    bool Load(const std::string& fileName) {
        resource = std::make_shared<T>();
        if (!resource->LoadFromFile(fileName)) {
            throw std::runtime_error("Failed to load resource from file: " + fileName);
        }
        return true;
    }

    /**
     * @brief Unloads the resource.
     */
    void Unload() {
        if (resource) {
            resource->Unload();
            resource.reset();
        }
    }

    /**
     * @brief Checks if the resource is loaded.
     * 
     * @return true if the resource is loaded, false otherwise.
     */
    bool IsLoaded() const {
        return resource && resource->IsLoaded();
    }

    /**
     * @brief Gets the underlying resource.
     * 
     * @return A shared pointer to the resource.
     */
    std::shared_ptr<T> Get() const {
        return resource;
    }

private:
    std::shared_ptr<T> resource; ///< Shared pointer to the underlying resource.
};

#endif // RESOURCE_HPP
