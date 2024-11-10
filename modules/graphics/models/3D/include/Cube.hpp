#ifndef CUBE_HPP
#define CUBE_HPP

#include "Model3D.hpp"

namespace graphics {

class Cube : public Model{
 public:
    Cube(float sideLength = 1.0f) : mSideLength(sideLength) {}

    void Draw() override {
        // Implement the drawing logic for a 3D cube
        std::cout << "Drawing a 3D cube with side length: " << mSideLength << std::endl;
    }

 private:
    float mSideLength;  // Side length of the cube
};

}  // namespace graphics

#endif  // CUBE_HPP
