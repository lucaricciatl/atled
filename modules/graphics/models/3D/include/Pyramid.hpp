#ifndef PYRAMID_HPP
#define PYRAMID_HPP

#include "Cube.hpp"
#include "Sphere.hpp"
#include "Pyramid.hpp"
#include "Model3D.hpp"

namespace graphics {

class Pyramid : public Model {
public:
    Pyramid(float baseWidth = 1.0f, float height = 1.0f)
        : mBaseWidth(baseWidth), mHeight(height) {}

    void Draw() override {
        // Implement the drawing logic for a 3D pyramid
        std::cout << "Drawing a 3D pyramid with base width: " << mBaseWidth
                  << " and height: " << mHeight << std::endl;
    }

private:
    float mBaseWidth;  // Width of the pyramid base
    float mHeight;     // Height of the pyramid
};

}  // namespace graphics

#endif  // PYRAMID_HPP
