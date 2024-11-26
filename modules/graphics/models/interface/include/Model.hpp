#ifndef MODEL_HPP
#define MODEL_HPP

#include <memory>

namespace graphics {

// Base class Model
class Model {
public:
    Model() {}
    virtual ~Model() = default;

    // Pure virtual function for drawing
    virtual void Draw() = 0;

    void SetFrame() {

    }

protected:

};

}  // namespace graphics

#endif  // MODEL_HPP
