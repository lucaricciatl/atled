#ifndef MODEL_HPP
#define MODEL_HPP

#include <memory>
#include <Frame.hpp>
#include "Mesh.hpp"

namespace graphics {

// Base class Model
class Model {
public:
    Model()
        : frame(std::make_shared<physics::Frame>(
            std::make_shared<physics::Position>(0.0, 0.0, 0.0),
            math::Quaternion(1.0, 0.0, 0.0, 0.0))) {}
    virtual ~Model() = default;

    // Pure virtual function for drawing
    virtual void Draw() = 0;

    std::shared_ptr<graphics::Mesh> GetMesh() {
        return mMesh;
    }

    void SetFrame(std::shared_ptr<physics::Frame> aFrame) {
        frame = aFrame;
    }

protected:
    std::shared_ptr<physics::Frame> frame;
    std::shared_ptr<graphics::Mesh> mMesh;
};

}  // namespace graphics

#endif  // MODEL_HPP
