// Cube.cpp
#include "Cube.hpp"
#include "Vector3.hpp"
#include "raylib.hpp"
#include "Vector3.hpp"
namespace graphics {

    Cube::Cube(float width, float height, float length, graphics::Color aColor)
    : mDimensions{width, height, length},
      mCenterPos{0.0f, 0.0f, 0.0f},
      mColor{aColor} 
    {
        UpdateMesh(); // Initialize mModel
    }

    void Cube::Draw() {
        raylib::Vector3 gPos = ComputeGlobalPosition(mCenterPos);
        if (ShapeIsEnabled) {
            raylib::DrawModel(mModel, gPos, 1.0f, toRaylibColor(mColor));
        }
        if (WireframeIsEnabled) {
            raylib::DrawCubeWires(gPos, mDimensions.GetX(), mDimensions.GetY(), mDimensions.GetZ(),
                                  toRaylibColor(mWireframeColor));
        }
    }

    // Setters for dimensions
    void Cube::SetWidth(float width) {
        mDimensions.SetX(width);
        UpdateMesh(); // Update the mesh
    }

    void Cube::SetHeight(float height) {
        mDimensions.SetY(height);
        UpdateMesh(); // Update the mesh
    }

    void Cube::SetLength(float length) {
        mDimensions.SetZ(length);
        UpdateMesh(); // Update the mesh
    }

    // Getters for dimensions
    float Cube::GetWidth() { return mDimensions.GetX(); }

    float Cube::GetHeight() { return mDimensions.GetY(); }

    float Cube::GetLength() { return mDimensions.GetZ(); }

    // Setter for center position
    void Cube::SetCenterPos(const math::Vector3& centerPos) {
        mCenterPos = centerPos;
    }

    // Getter for center position
    math::Vector3 Cube::GetCenterPos() const {
        return mCenterPos;
    }

    void Cube::UpdateMesh() {
        // Clean up the old model to prevent memory leaks
        if (mModel.meshCount > 0) {
            UnloadModel(mModel);
        }

        // Generate a new mesh and load it into mModel
        mMesh = std::make_shared<Mesh>(Mesh::CreateCubeMesh(mDimensions.GetX()));
        raylib::Mesh cubeMesh = mMesh->ToRaylibMesh();
        raylib:UploadMesh(&cubeMesh, false);
        mModel = raylib::LoadModelFromMesh(cubeMesh);

        // Set the material color
        mModel.materials[0].maps[raylib::MaterialMapIndex::MATERIAL_MAP_ALBEDO].color = graphics::toRaylibColor(mColor);
    }

}
