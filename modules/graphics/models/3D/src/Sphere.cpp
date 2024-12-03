#include "Sphere.hpp"
#include "raylib.hpp"

namespace graphics {

    Sphere::Sphere()
        : mRadius(1.0f), 
          mRings(16), 
          mSlices(16), 
          mCenterPos({0.0f, 0.0f, 0.0f}),
          mColor(WHITE) { // Initialize color to white
        UpdateMesh();
    }

    Sphere::Sphere(float radius, const Vector3& centerPos, int rings, int slices, Color mColor)
        : mRadius(radius), 
          mRings(rings), 
          mSlices(slices), 
          mCenterPos(centerPos),
          mColor(WHITE) { // Initialize color to white
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

    void Sphere::SetCenterPos(const Vector3& centerPos) {
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

    Vector3 Sphere::GetCenterPos() const {
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
        Shader shader = LoadShaderFromMemory(
            R"(
            #version 330
            layout (location = 0) in vec3 vertexPosition;
            layout (location = 1) in vec3 vertexNormal;
            uniform mat4 mvp;
            out vec3 fragNormal;
            void main() {
                fragNormal = vertexNormal;
                gl_Position = mvp * vec4(vertexPosition, 1.0);
            }
            )",
            R"(
            #version 330
            in vec3 fragNormal;
            uniform vec3 lightColor;
            out vec4 fragColor;
            void main() {
                vec3 norm = normalize(fragNormal);
                vec3 lightDir = normalize(vec3(0.0, 1.0, 1.0)); // Fixed light direction
                float diff = max(dot(norm, lightDir), 0.0);
                fragColor = vec4(diff * lightColor, 1.0);
            }
            )"
        );

        // Set shader values dynamically
        Vector3 lightColor = {1.0f, 1.0f, 1.0f};
        SetShaderValue(shader, GetShaderLocation(shader, "lightColor"), &lightColor, SHADER_UNIFORM_VEC3);

        // Assign the shader to the model's material
        mModel.materials[0].shader = shader;

        // Draw the model with the custom shader
        DrawModel(mModel, gPos, 1.0f, mColor);

        // Unload shader after use to avoid memory leaks (not recommended for real-time use)
        UnloadShader(shader);
    }
}


    void Sphere::UpdateMesh() {
        // Clean up the old model to prevent memory leaks
        if (mModel.meshCount > 0) {
            UnloadModel(mModel);
        }

        // Generate a new mesh for the sphere and load it into mModel
        Mesh sphereMesh = GenMeshSphere(mRadius, mSlices, mRings);
        mModel = LoadModelFromMesh(sphereMesh);

        // Set the material color
        mModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].color = mColor;
    }

} // namespace graphics
