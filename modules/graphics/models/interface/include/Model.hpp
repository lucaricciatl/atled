#ifndef MODEL_HPP
#define MODEL_HPP

#include <memory>
#include <Frame.hpp>

namespace graphics {

// Base class Model
class Model {
public:
    Model() {}
    virtual ~Model() = default;

    // Pure virtual function for drawing
    virtual void Draw() = 0;

    void SetFrame(std::shared_ptr<physics::Frame> aFrame) {
        frame = aFrame;
    }

protected:
    std::shared_ptr<physics::Frame> frame;

};

}  // namespace graphics

#endif  // MODEL_HPP
