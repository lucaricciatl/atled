#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "Model3D.hpp"
#include "raylib.h"  // Assuming raylib is used for the Vector3 and Color types

namespace graphics {

    class Sphere : public Model, public Model3D {
    public:
        // Constructors
        Sphere();  // Default constructor
        Sphere(float radius, const Vector3& centerPos, int rings = 16, int slices = 16);

        // Override draw function
        void Draw() override;

        // Setter for radius
        void SetRadius(float radius);
        // Getter for radius
        float GetRadius() const;

        // Setter for center position
        void SetCenterPos(const Vector3& centerPos);
        // Getter for center position
        Vector3 GetCenterPos() const;

        // Setter for ring count
        void SetRings(int rings);
        // Getter for ring count
        int GetRings() const;

        // Setter for slice count
        void SetSlices(int slices);
        // Getter for slice count
        int GetSlices() const;

    private:
        float mRadius;      // Radius of the sphere
        int mRings;         // Number of rings
        int mSlices;        // Number of slices
        Vector3 mCenterPos; // Center position of the sphere
    };

}  // namespace graphics

#endif  // SPHERE_HPP