#include <string>


class MeshResource {
public:
    MeshResource() = default;

    explicit MeshResource(const std::string& path) {

    }

    ~MeshResource() {
        Unload();
    }

    bool Load(const std::string& path) {
        return true;
    }

    void Unload() {
    }

    bool IsLoaded() const {
    }

    void Get();

private:

};