#ifndef IRESOURCE_MANAGER_HPP
#define IRESOURCE_MANAGER_HPP

#include <string>
#include <memory>
#include <unordered_map>

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

/**
 * @brief Non-templated interface for managing resources of various types.
 */
class IResourceManager {
public:
    virtual ~IResourceManager() = default;

    /**
     * @brief Load a resource from a file by type and name.
     *
     * @param type The type of the resource (e.g., ResourceType::Mesh, ResourceType::Texture).
     * @param fileName The file name to load the resource from.
     * @return A shared pointer to the loaded resource as a base type.
     */
    virtual std::shared_ptr<void> Load(ResourceType type, const std::string& fileName) = 0;

    /**
     * @brief Unload a resource by type and file name.
     *
     * @param type The type of the resource.
     * @param fileName The file name of the resource to unload.
     */
    virtual void Unload(ResourceType type, const std::string& fileName) = 0;

    /**
     * @brief Check if a resource is loaded.
     *
     * @param type The type of the resource.
     * @param fileName The file name of the resource.
     * @return true if the resource is loaded, false otherwise.
     */
    virtual bool IsLoaded(ResourceType type, const std::string& fileName) const = 0;

    /**
     * @brief Unload all resources managed by the resource manager.
     */
    virtual void UnloadAll() = 0;
};

#endif // IRESOURCE_MANAGER_HPP
