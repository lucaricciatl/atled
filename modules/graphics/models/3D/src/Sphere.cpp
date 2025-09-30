#include "Sphere.hpp"
#include "raylib.hpp"
#include "filesystem"
#include "Vector3.hpp"
#include "Palette.hpp"
#include "Mesh.hpp"
#include <raylibShader.hpp>
#include <LightsFactory.hpp>

namespace graphics {


    Sphere::Sphere()
        : mRadius(1.0f), 
          mRings(16), 
          mSlices(16), 
          mCenterPos({0.0f, 0.0f, 0.0f}),
          mColor(getColor("Timeless Gray")),
          Model3D() { // Initialize color to white
        UpdateMesh();
    }

    Sphere::Sphere(float radius, const math::Vector3& centerPos, int rings, int slices, const graphics::Color& aColor)
        : mRadius(radius), 
          mRings(rings), 
          mSlices(slices), 
          mCenterPos(centerPos),
          mColor(aColor) { // Initialize color to white
        if (radius <= 0) {
            throw std::invalid_argument("Sphere radius must be positive.");
        }
        if (rings < 3 || slices < 3) {
            throw std::invalid_argument("Rings and slices must be at least 3.");
        }
        UpdateMesh();
    }

    void Sphere::SetRadius(float radius) {
        if (radius <= 0) {
            throw std::invalid_argument("Sphere radius must be positive.");
        }
        mRadius = radius;
        UpdateMesh();
    }

    void Sphere::SetCenterPos(const math::Vector3& centerPos) {
        mCenterPos = centerPos;
        UpdateMesh();
    }

    void Sphere::SetRings(int rings) {
        if (rings < 3) {
            throw std::invalid_argument("Rings must be at least 3.");
        }
        mRings = rings;
        UpdateMesh();
    }


    void Sphere::SetSlices(int slices) {
        if (slices < 3) {
            throw std::invalid_argument("Slices must be at least 3.");
        }
        mSlices = slices;
        UpdateMesh();
    }

    float Sphere::GetRadius() const {
        return mRadius;
    }

    math::Vector3 Sphere::GetCenterPos() const {
        return mCenterPos;
    }

    int Sphere::GetRings() const {
        return mRings;
    }

    int Sphere::GetSlices() const {
        return mSlices;
    }

void Sphere::Draw() {
    auto gPos = ComputeGlobalPosition(mCenterPos);

    if (ShapeIsEnabled) {
        raylib::DrawModel(mModel, gPos, 1.0f, toRaylibColor(mColor));
    }
    if (WireframeIsEnabled) {
        raylib::DrawSphereWires(gPos, mRadius, mRings, mSlices,
                              toRaylibColor(mWireframeColor));
    }
}

    void Sphere::UpdateMesh() {
        // Clean up the old model to prevent memory leaks
        if (mModel.meshCount > 0) {
            UnloadModel(mModel);
        }
        mMesh = std::make_shared<Mesh>(Mesh::CreateSphereMesh(mRadius, mSlices, mRings));
        // Generate a new mesh for the sphere and load it into mModel
        raylib::Mesh SphereMesh = mMesh->ToRaylibMesh();
        raylib:UploadMesh(&SphereMesh, false);

        mModel = raylib::LoadModelFromMesh(SphereMesh);
    }

} // namespace graphics
