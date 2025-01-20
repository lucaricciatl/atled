#include "BoundingBox.hpp"

namespace math {

BoundingBox::BoundingBox(const Vector3& min, const Vector3& max)
    : mMin(min), mMax(max) {}

// Check if this bounding box contains another bounding box
bool BoundingBox::Contains(const BoundingBox& other) const {
    return (mMin.GetX() <= other.mMin.GetX() && mMax.GetX() >= other.mMax.GetX() && mMin.GetY() <= other.mMin.GetY() &&
            mMax.GetY() >= other.mMax.GetY() && mMin.GetZ() <= other.mMin.GetZ() && mMax.GetZ() >= other.mMax.GetZ());
}

// Check if this bounding box intersects with another bounding box
bool BoundingBox::Intersects(const BoundingBox& other) const {
    return (mMin.GetX() <= other.mMax.GetX() && mMax.GetX() >= other.mMin.GetX() && mMin.GetY() <= other.mMax.GetY() &&
            mMax.GetY() >= other.mMin.GetY() && mMin.GetZ() <= other.mMax.GetZ() && mMax.GetZ() >= other.mMin.GetZ());
}

// Get child bounding boxes for octree subdivision
BoundingBox BoundingBox::GetChildBounds(int index) const {
    Vector3 center = (mMin + mMax) * 0.5f;

    switch (index) {
        case 0: return BoundingBox(mMin, center);
        case 1:
            return BoundingBox(Vector3(center.GetX(), mMin.GetY(), mMin.GetZ()),
                               Vector3(mMax.GetX(), center.GetY(), center.GetZ()));
        case 2:
            return BoundingBox(Vector3(mMin.GetX(), center.GetY(), mMin.GetZ()),
                               Vector3(center.GetX(), mMax.GetY(), center.GetZ()));
        case 3:
            return BoundingBox(Vector3(center.GetX(), center.GetY(), mMin.GetZ()),
                               Vector3(mMax.GetX(), mMax.GetY(), center.GetZ()));
        case 4:
            return BoundingBox(Vector3(mMin.GetX(), mMin.GetY(), center.GetZ()),
                               Vector3(center.GetX(), center.GetY(), mMax.GetZ()));
        case 5:
            return BoundingBox(Vector3(center.GetX(), mMin.GetY(), center.GetZ()),
                               Vector3(mMax.GetX(), center.GetY(), mMax.GetZ()));
        case 6:
            return BoundingBox(Vector3(mMin.GetX(), center.GetY(), center.GetZ()),
                               Vector3(center.GetX(), mMax.GetY(), mMax.GetZ()));
        case 7: return BoundingBox(center, mMax);
        default: throw std::out_of_range("Invalid child index for bounding box subdivision");
    }
}

// Expand the bounding box to include a point
void BoundingBox::ExpandToFit(const Vector3& point) {
    mMin = Vector3(std::min(mMin.GetX(), point.GetX()), std::min(mMin.GetY(), point.GetY()),
                   std::min(mMin.GetZ(), point.GetZ()));

    mMax = Vector3(std::max(mMax.GetX(), point.GetX()), std::max(mMax.GetY(), point.GetY()),
                   std::max(mMax.GetZ(), point.GetZ()));
}

} // namespace math
