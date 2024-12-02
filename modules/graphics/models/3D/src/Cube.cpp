// Cube.cpp
#include "Cube.hpp"

namespace graphics {
    using namespace raylib;

    Cube::Cube(float width, float height, float length)
        : mDimensions{ width, height, length }, mCenterPos{ 0.0f, 0.0f, 0.0f } {
        UpdateMesh(); // Initialize mModel
    }

    void Cube::Draw() {
        auto gPos = ComputeGlobalPosition(mCenterPos);
        if (ShapeIsEnabled) {
            DrawModel(mModel, gPos, 1.0f, WHITE);
        }
        if (WireframeIsEnabled) {
            ::DrawCubeWires(gPos, mDimensions.x, mDimensions.y, mDimensions.z, mWireframeColor);
        }
    }

    // Setters for dimensions
    void Cube::SetWidth(float width) {
        mDimensions.x = width;
        UpdateMesh(); // Update the mesh
    }

    void Cube::SetHeight(float height) {
        mDimensions.y = height;
        UpdateMesh(); // Update the mesh
    }

    void Cube::SetLength(float length) {
        mDimensions.z = length;
        UpdateMesh(); // Update the mesh
    }

    // Getters for dimensions
    float Cube::GetWidth() const {
        return mDimensions.x;
    }

    float Cube::GetHeight() const {
        return mDimensions.y;
    }

    float Cube::GetLength() const {
        return mDimensions.z;
    }

    // Setter for center position
    void Cube::SetCenterPos(const Vector3& centerPos) {
        mCenterPos = centerPos;
    }

    // Getter for center position
    Vector3 Cube::GetCenterPos() const {
        return mCenterPos;
    }

    void Cube::UpdateMesh() {
        // Clean up the old model to prevent memory leaks
        if (mModel.meshCount > 0) {
            UnloadModel(mModel);
        }

        // Generate a new mesh and load it into mModel
        Mesh cubeMesh = GenMeshCube(mDimensions.x, mDimensions.y, mDimensions.z);
        mModel = LoadModelFromMesh(cubeMesh);

        // Set the material color
        mModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].color = mColor;
    }

}
