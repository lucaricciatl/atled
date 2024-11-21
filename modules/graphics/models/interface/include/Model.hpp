#ifndef MODEL_HPP
#define MODEL_HPP

#include "Model2D.hpp"
#include "Model3D.hpp"


namespace graphics {

// Base class Model
class Model{
public:
    virtual ~Model() = default;

    // Pure virtual function for drawing
    virtual void Draw() = 0;

};

}  // namespace graphics

#endif  // MODEL_HPP
