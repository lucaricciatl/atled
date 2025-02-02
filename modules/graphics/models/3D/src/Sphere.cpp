#include "Sphere.hpp"
#include "raylib.hpp"
#include "filesystem"
#include "Vector3.hpp"
#include "Palette.hpp"
#include "Mesh.hpp"
#include <RaylibShader.hpp>
#include <LightsFactory.hpp>

namespace graphics {


    Sphere::Sphere()
        : mRadius(1.0f), 
          mRings(16), 
          mSlices(16), 
          mCenterPos({0.0f, 0.0f, 0.0f}),
          mColor(getColor("Timeless Gray")) { // Initialize color to white
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

    // Create a Light. Arguments can vary depending on your needs.

    //    // Corrected version:
    //    sh->LoadFromFiles(
    //        "C:"
    //        "\\Users\\atled\\source\\repos\\atled\\modules\\external\\raylib\\examples\\shaders\\resources\\shaders\\gl"
    //        "sl120\\lighting.vs",
    //        "C:"
    //        "\\Users\\atled\\source\\repos\\atled\\modules\\external\\raylib\\examples\\shaders\\resources\\shaders\\gl"
    //        "sl120\\lighting.fs");
    //        sh->shader.locs[raylib::SHADER_LOC_VECTOR_VIEW] = raylib::GetShaderLocation(sh->shader, "viewPos");
    //int ambientLoc = raylib::GetShaderLocation(sh->shader, "ambient");
    //    float ambientColor[4] = {0.6f, 0.1f, 0.1f, 0.5f};
    //    SetShaderValue(sh->GetShader(), ambientLoc, ambientColor, raylib::SHADER_UNIFORM_VEC4);
    //    RaylibLight l;
    //    rLight light = l.CreateLight(raylib::LightType::LIGHT_POINT, math::Vector3{2, 2, 0}, math::Vector3{0, 2, 0},
    //                                 raylib::BLUE, sh->shader);


        //raylib::BeginShaderMode(mShader->GetShader());


        //mModel.materials->shader = sh->GetShader();
        raylib::DrawModel(mModel, gPos, 1.0f, toRaylibColor(mColor));
        // Unload shader after use to avoid memory leaks (not recommended for real-time use)

        //raylib::EndShaderMode();
        //raylib::UnloadShader(sh->GetShader());
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

        // Set the material color
        //mModel.materials[0].maps[raylib::MaterialMapIndex::MATERIAL_MAP_ALBEDO].color = toRaylibColor(mColor);
    }

} // namespace graphics
