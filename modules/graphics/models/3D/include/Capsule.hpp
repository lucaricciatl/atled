#ifndef CAPSULE_HPP
#define CAPSULE_HPP

#include "Model3D.hpp"
#include "raylib.hpp"  // For Vector3 and Color types

namespace graphics {
using namespace raylib;
class Capsule : public Model3D {
public:
    // Constructors
    Capsule();
    Capsule(const Vector3& startPos, const Vector3& endPos, float radius, int slices, int rings);

    // Override draw function
    void Draw() override;

    // Setters
    void SetStartPos(const Vector3& startPos);
    void SetEndPos(const Vector3& endPos);
    void SetRadius(float radius);
    void SetSlices(int slices);
    void SetRings(int rings);

    // Getters
    Vector3 GetStartPos() const;
    Vector3 GetEndPos() const;
    float GetRadius() const;
    int GetSlices() const;
    int GetRings() const;

private:
    Vector3 mStartPos;  // Start position of the capsule
    Vector3 mEndPos;    // End position of the capsule
    float mRadius;      // Radius of the capsule
    int mSlices;        // Number of slices for the capsule's sphere
    int mRings;         // Number of rings for the capsule's sphere
};

}  // namespace graphics

#endif  // CAPSULE_HPP
