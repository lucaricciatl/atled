// Cube.cpp
#include "Cube.hpp"
#include "Vector3.hpp"
#include "raylib.hpp"
#include "Vector3.hpp"
#include "Conversion.hpp"
namespace graphics
{

    Cube::Cube(float width, float height, float length)
        : mDimensions{width, height, length}, mCenterPos{0.0f, 0.0f, 0.0f}
    {
        UpdateMesh(); // Initialize mModel
    }

    void Cube::Draw()
    {
        math::Vector3 gPos = ComputeGlobalPosition(mCenterPos);
        if (ShapeIsEnabled)
        {
            DrawModel(mModel, gPos, 1.0f, mColor);
        }
        if (WireframeIsEnabled)
        {
            raylib::DrawCubeWires(gPos, mDimensions.getX(), mDimensions.getY(), mDimensions.getZ(), mWireframeColor);
        }
    }

    // Setters for dimensions
    void Cube::SetWidth(float width)
    {
        mDimensions.setX(width);
        UpdateMesh(); // Update the mesh
    }

    void Cube::SetHeight(float height)
    {
        mDimensions.setY(height);
        UpdateMesh(); // Update the mesh
    }

    void Cube::SetLength(float length)
    {
        mDimensions.setZ(length);
        UpdateMesh(); // Update the mesh
    }

    // Getters for dimensions
    float Cube::GetWidth()
    {
        return mDimensions.getX();
    }

    float Cube::GetHeight()
    {
        return mDimensions.getY();
    }

    float Cube::GetLength()
    {
        return mDimensions.getZ();
    }

    // Setter for center position
    void Cube::SetCenterPos(const math::Vector3 &centerPos)
    {
        mCenterPos = centerPos;
    }

    // Getter for center position
    math::Vector3 Cube::GetCenterPos() const
    {
        return mCenterPos;
    }

    void Cube::UpdateMesh()
    {
        // Clean up the old model to prevent memory leaks
        if (mModel.meshCount > 0)
        {
            UnloadModel(mModel);
        }

        // Generate a new mesh and load it into mModel
        raylib::Mesh cubeMesh = raylib::GenMeshCube(mDimensions.getX(), mDimensions.getY(), mDimensions.getZ());
        mModel = raylib::LoadModelFromMesh(cubeMesh);

        // Set the material color
        mModel.materials[0].maps[raylib::MaterialMapIndex::MATERIAL_MAP_ALBEDO].color = raylib::Color{
            static_cast<unsigned char>(mColor.getRed()),
            static_cast<unsigned char>(mColor.getGreen()),
            static_cast<unsigned char>(mColor.getBlue()),
            static_cast<unsigned char>(mColor.getAlpha())};
    }

}
