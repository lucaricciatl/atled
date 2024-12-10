#include "Cylinder.hpp"
#include "Vector3.hpp"
#include "raylib.hpp"

namespace graphics
{

    Cylinder::Cylinder()
        : mPos({0.0f, 0.0f, 0.0f}),
          mHeight(1.0f),
          mRadius(0.5f),
          mSides(64),
          mColor(getColor("White"))
    {
        UpdateMesh();
    }

    Cylinder::Cylinder(const math::Vector3 &aPos, float aRadius, float height, int sides, Color aColor)
        : mPos(aPos), mRadius(aRadius), mSides(sides), mHeight(height), mColor(aColor)
    {
        UpdateMesh();
    }

    void Cylinder::Draw()
    {
        math::Vector3 gPos = ComputeGlobalPosition(mPos);

        if (ShapeIsEnabled)
        {
            //raylib::DrawModel(mModel, gPos, 1.0f, getColor("White"));
        }
    }

    void Cylinder::SetPos(const math::Vector3 &aPos)
    {
        mPos = aPos;
        UpdateMesh();
    }

    void Cylinder::SetRadius(float aRadius)
    {
        mRadius = aRadius;
        UpdateMesh();
    }

    void Cylinder::SetSides(int sides)
    {
        mSides = sides;
        UpdateMesh();
    }

    float Cylinder::GetRadius() const
    {
        return mRadius;
    }

    int Cylinder::GetSides() const
    {
        return mSides;
    }

    void Cylinder::UpdateMesh()
    {
        // Clean up the old model to prevent memory leaks
        if (mModel.meshCount > 0)
        {
            UnloadModel(mModel);
        }

        // Generate a new mesh for the cylinder and load it into mModel
        raylib::Mesh cylinderMesh = raylib::GenMeshCylinder(mRadius, mHeight, mSides);
        mModel = raylib::LoadModelFromMesh(cylinderMesh);

        // Set the material color
        mModel.materials[0].maps[raylib::MaterialMapIndex::MATERIAL_MAP_ALBEDO].color = raylib::Color{
            static_cast<unsigned char>(mColor.getRed()),
            static_cast<unsigned char>(mColor.getGreen()),
            static_cast<unsigned char>(mColor.getBlue()),
            static_cast<unsigned char>(mColor.getAlpha())};
    }

} // namespace graphics
