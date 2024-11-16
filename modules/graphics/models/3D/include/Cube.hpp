#ifndef CUBE_HPP
#define CUBE_HPP

#include "Model3D.hpp"
#include "raylib.h"  // Assuming raylib is used for Vector3 and Color types

namespace graphics {

class Cube : public Model {
public:
    
    // Constructor with default dimensions
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

    void EnableWireframe();
    void DisableWireframe();

    // Enable wireframe rendering
    void EnableShape();
    void DisableShape();
    void SetWireframeColor(Color aColor);
    Color GetWireframeColor() const;

    // Setter for center position
    void SetCenterPos(const Vector3& centerPos);
    // Getter for center position
    Vector3 GetCenterPos() const;

    // Setter for color
    void SetColor(const Color& color);
    // Getter for color
    Color GetColor() const;

private:
    Vector3 mDimensions; // Dimensions of the cube (width, height, length)
    Vector3 mCenterPos;  // Center position of the cube
    Color mColor;        // Color of the cube
    Color mWireframeColor; // Color of thr wireframe
    bool WireframeIsEnabled; // 1 for the wirefram
    bool ShapeIsEnabled; // 1 for the wirefram
};

}  // namespace graphics

#endif  // CUBE_HPP
