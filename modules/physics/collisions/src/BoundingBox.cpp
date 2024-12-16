#include "BoundingBox.hpp"

namespace math {

BoundingBox::BoundingBox(const Vector3& min, const Vector3& max)
    : mMin(min), mMax(max) {}

// Check if this bounding box contains another bounding box
bool BoundingBox::Contains(const BoundingBox& other) const {
    return (mMin.getX() <= other.mMin.getX() && mMax.getX() >= other.mMax.getX() &&
            mMin.getY() <= other.mMin.getY() && mMax.getY() >= other.mMax.getY() &&
            mMin.getZ() <= other.mMin.getZ() && mMax.getZ() >= other.mMax.getZ());
}

// Check if this bounding box intersects with another bounding box
bool BoundingBox::Intersects(const BoundingBox& other) const {
    return (mMin.getX() <= other.mMax.getX() && mMax.getX() >= other.mMin.getX() &&
            mMin.getY() <= other.mMax.getY() && mMax.getY() >= other.mMin.getY() &&
            mMin.getZ() <= other.mMax.getZ() && mMax.getZ() >= other.mMin.getZ());
}

// Get child bounding boxes for octree subdivision
BoundingBox BoundingBox::GetChildBounds(int index) const {
    Vector3 center = (mMin + mMax) * 0.5f;

    switch (index) {
        case 0: return BoundingBox(mMin, center);
        case 1: return BoundingBox(Vector3(center.getX(), mMin.getY(), mMin.getZ()),
                                   Vector3(mMax.getX(), center.getY(), center.getZ()));
        case 2: return BoundingBox(Vector3(mMin.getX(), center.getY(), mMin.getZ()),
                                   Vector3(center.getX(), mMax.getY(), center.getZ()));
        case 3: return BoundingBox(Vector3(center.getX(), center.getY(), mMin.getZ()),
                                   Vector3(mMax.getX(), mMax.getY(), center.getZ()));
        case 4: return BoundingBox(Vector3(mMin.getX(), mMin.getY(), center.getZ()),
                                   Vector3(center.getX(), center.getY(), mMax.getZ()));
        case 5: return BoundingBox(Vector3(center.getX(), mMin.getY(), center.getZ()),
                                   Vector3(mMax.getX(), center.getY(), mMax.getZ()));
        case 6: return BoundingBox(Vector3(mMin.getX(), center.getY(), center.getZ()),
                                   Vector3(center.getX(), mMax.getY(), mMax.getZ()));
        case 7: return BoundingBox(center, mMax);
        default: throw std::out_of_range("Invalid child index for bounding box subdivision");
    }
}

// Expand the bounding box to include a point
void BoundingBox::ExpandToFit(const Vector3& point) {
    mMin = Vector3(
        std::min(mMin.getX(), point.getX()),
        std::min(mMin.getY(), point.getY()),
        std::min(mMin.getZ(), point.getZ())
    );

    mMax = Vector3(
        std::max(mMax.getX(), point.getX()),
        std::max(mMax.getY(), point.getY()),
        std::max(mMax.getZ(), point.getZ())
    );
}

} // namespace math
