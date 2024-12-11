#ifndef CUBE_HPP
#define CUBE_HPP

#include "Model3D.hpp"
#include "raylib.hpp"  // Assuming raylib is used for math::Vector3 and Color types

namespace graphics {

class Cube : public Model3D {
public:
    
    // Constructor with default dimensions
    ~Cube() = default;
    Cube(float width = 1.0f, float height = 1.0f, float length = 1.0f, graphics::Color aColor = getColor("Timeless Gray"));

    // Override draw function
    void Draw() override;

    // Setters for dimensions
    void SetWidth(float width);
    void SetHeight(float height);
    void SetLength(float length);

    // Getters for dimensions
    float GetWidth() ;
    float GetHeight();
    float GetLength();

    void UpdateMesh();
    // Setter for center position
    void SetCenterPos(const math::Vector3& centerPos);
    // Getter for center position
    math::Vector3 GetCenterPos() const;


private:
    math::Vector3 mDimensions;        // Dimensions of the cube (width, height, length)
    math::Vector3 mCenterPos;         // Center position of the cube
    raylib::Model mModel;
    graphics::Color mColor;

};

}  // namespace graphics

#endif  // CUBE_HPP
