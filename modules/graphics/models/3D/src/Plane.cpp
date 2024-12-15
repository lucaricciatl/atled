#include "Plane.hpp"
#include "Vector3.hpp"
#include "Color.hpp"
#include <Model.hpp>
#include "Palette.hpp"
namespace graphics {

// Default constructor
    Plane::Plane()
        : mCenterPos({ 0.0f, 0.0f, 0.0f }),
        mSize({ 10.0f, 10.0f }),
        mColor(getColor("Timeless Gray")) {
        UpdateMesh();
    };

// Parameterized constructor
Plane::Plane(const math::Vector3& centerPos, const raylib::Vector2& size, const Color& color)
    : mCenterPos(centerPos), mSize(size), mColor(color){
    UpdateMesh();
}

// Override draw method
void Plane::Draw() {
    auto gPos = ComputeGlobalPosition(mCenterPos);    
    raylib::DrawModel(mModel, gPos, 1.0f, toRaylibColor(mColor));
}

// Setter for center position
void Plane::SetCenterPos(const math::Vector3& centerPos) {
    mCenterPos = centerPos;
    UpdateMesh();
}

// Setter for size
void Plane::SetSize(const raylib::Vector2& size) {
    mSize = size;
    UpdateMesh();
}

// Getter for center position
math::Vector3 Plane::GetCenterPos() const {
    return mCenterPos;
}

// Getter for size
raylib::Vector2 Plane::GetSize() const {
    return mSize;
}

void Plane::UpdateMesh() {
    // Clean up the old model to prevent memory leaks
    if (mModel.meshCount > 0) {
        UnloadModel(mModel);
    }

    // Generate a new mesh for the sphere and load it into mModel
    mMesh = Mesh::CreatePlaneMesh(mSize.x, mSize.y,5,5);
    raylib::Mesh PlaneMesh = mMesh.ToRaylibMesh();
    raylib:UploadMesh(&PlaneMesh, false);
    mModel = raylib::LoadModelFromMesh(PlaneMesh);

    // Set the material color
    mModel.materials[0].maps[raylib::MaterialMapIndex::MATERIAL_MAP_ALBEDO].color = toRaylibColor(mColor);
}

}  // namespace graphics
