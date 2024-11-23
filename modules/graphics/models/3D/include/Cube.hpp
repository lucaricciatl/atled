#ifndef CUBE_HPP
#define CUBE_HPP

#include "Model3D.hpp"
#include "raylib.hpp"  // Assuming raylib is used for Vector3 and Color types

namespace graphics {
using namespace raylib;
class Cube : public Model3D {
public:
    
    // Constructor with default dimensions
    ~Cube() = default;
    Cube(float width = 1.0f, float height = 1.0f, float length = 1.0f);

    // Override draw function
    void Draw() override;

    // Setters for dimensions
    void SetWidth(float width);
    void SetHeight(float height);
    void SetLength(float length);

    // Getters for dimensions
    float GetWidth() const;
    float GetHeight() const;
    float GetLength() const;



    // Setter for center position
    void SetCenterPos(const Vector3& centerPos);
    // Getter for center position
    Vector3 GetCenterPos() const;


private:
    Vector3 mDimensions;        // Dimensions of the cube (width, height, length)
    Vector3 mCenterPos;         // Center position of the cube


};

}  // namespace graphics

#endif  // CUBE_HPP
