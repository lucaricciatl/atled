#include "Sphere.hpp"
#include "raylib.hpp"

namespace graphics {
    // Setters
    void Sphere::SetRadius(float radius) {
        if (radius <= 0) {
            throw std::invalid_argument("Sphere radius must be positive.");
        }
        mRadius = radius;
    }

    void Sphere::SetCenterPos(const Vector3& centerPos) {
        mCenterPos = centerPos;
    }

    void Sphere::SetRings(int rings) {
        if (rings < 3) {
            throw std::invalid_argument("Rings must be at least 3.");
        }
        mRings = rings;
    }

    void Sphere::SetSlices(int slices) {
        if (slices < 3) {
            throw std::invalid_argument("Slices must be at least 3.");
        }
        mSlices = slices;
    }

    // Getters
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
    // Default constructor
    Sphere::Sphere()
        : mRadius(1.0f), mRings(16), mSlices(16), mCenterPos({ 0.0f, 0.0f, 0.0f }) {}

    // Parameterized constructor
    Sphere::Sphere(float radius, const Vector3& centerPos, int rings, int slices)
        : mRadius(radius), mRings(rings), mSlices(slices), mCenterPos(centerPos) {
        if (radius <= 0) {
            throw std::invalid_argument("Sphere radius must be positive.");
        }
        if (rings < 3 || slices < 3) {
            throw std::invalid_argument("Rings and slices must be at least 3.");
        }
    }
void Sphere::Draw() {
    // Call to Raylib's DrawSphere function to render the sphere
    if (ShapeIsEnabled) {
        
    raylib::DrawSphereEx(ComputeGlobalPosition(mCenterPos), mRadius, mRings , mSlices, mColor);
    }
    if (WireframeIsEnabled) {

    raylib::DrawSphereWires(ComputeGlobalPosition(mCenterPos), mRadius, mRings, mSlices, mColor);
    }
}


}  // namespace graphics
