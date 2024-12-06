#include "Sphere.hpp"
#include "raylib.hpp"
#include "filesystem"

namespace graphics {

    Sphere::Sphere()
        : mRadius(1.0f), 
          mRings(16), 
          mSlices(16), 
          mCenterPos({0.0f, 0.0f, 0.0f}),
          mColor(raylib::WHITE) { // Initialize color to white
        UpdateMesh();
    }

    Sphere::Sphere(float radius, const raylib::Vector3& centerPos, int rings, int slices, raylib::Color aColor)
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

    void Sphere::SetCenterPos(const raylib::Vector3& centerPos) {
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

    raylib::Vector3 Sphere::GetCenterPos() const {
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
        // Create and load a simple shader dynamically
        //std::cout << "Current Working Directory: " << std::filesystem::current_path() << std::endl;

        raylib::Shader basicShader = raylib::LoadShader(
            "C:/Users/atled/source/repos/atled/assets/shaders/basic.vs",
            "C:/Users/atled/source/repos/atled/assets/shaders/basic.fs"
        );


        // Set the framebuffer size in the shader
        raylib::Vector2 screenSize = { 800.0f, 450.0f }; // Update to match your screen resolution
        //SetShaderValue(basicShader, GetShaderLocation(basicShader, "size"), &screenSize, SHADER_UNIFORM_VEC2);
        float samplesVal = 8.0f; // Number of blur samples
        float qualityVal = 2.0f; // Blur quality multiplier
        int samplesLoc = raylib::GetShaderLocation(basicShader, "samples");
        int qualityLoc = raylib::GetShaderLocation(basicShader, "quality");
        raylib::SetShaderValue(basicShader, samplesLoc, &samplesVal, raylib::SHADER_UNIFORM_FLOAT);
        raylib::SetShaderValue(basicShader, qualityLoc, &qualityVal, raylib::SHADER_UNIFORM_FLOAT);
        //SetShaderValue(basicShader, GetShaderLocation(basicShader, "samples"), &samples, SHADER_UNIFORM_FLOAT);
        //SetShaderValue(basicShader, GetShaderLocation(basicShader, "quality"), &quality, SHADER_UNIFORM_FLOAT);
        raylib::Texture2D texture = raylib::LoadTexture("C:/Users/atled/source/repos/atled/assets/textures/p.png");
        mModel.materials[0].maps[raylib::MATERIAL_MAP_DIFFUSE].texture = texture;
        mModel.materials[0].maps[raylib::MATERIAL_MAP_SPECULAR].texture = texture;
        // Assign the shader to the 3D model
        mModel.materials[0].shader = basicShader;
        raylib::DrawModel(mModel, gPos, 1.0f, raylib::BLUE);
        // Unload shader after use to avoid memory leaks (not recommended for real-time use)
        //UnloadShader(basicShader);
    }
}

    void Sphere::UpdateMesh() {
        // Clean up the old model to prevent memory leaks
        if (mModel.meshCount > 0) {
            UnloadModel(mModel);
        }

        // Generate a new mesh for the sphere and load it into mModel
        raylib::Mesh sphereMesh = raylib::GenMeshSphere(mRadius, mSlices, mRings);
        mModel = raylib::LoadModelFromMesh(sphereMesh);

        // Set the material color
        mModel.materials[0].maps[raylib::MaterialMapIndex::MATERIAL_MAP_ALBEDO].color = mColor;
    }

} // namespace graphics
