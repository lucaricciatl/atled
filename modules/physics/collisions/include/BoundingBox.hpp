#pragma once

#include "Vector3.hpp"

namespace math {

class BoundingBox {
public:
    BoundingBox() = default;

    // Constructor with min and max points
    BoundingBox(const Vector3& min, const Vector3& max);

    // Check if this bounding box contains another bounding box
    bool Contains(const BoundingBox& other) const;

    // Check if this bounding box intersects another bounding box
    bool Intersects(const BoundingBox& other) const;

    // Get child bounding boxes for octree subdivision
    BoundingBox GetChildBounds(int index) const;

    // Accessors
    const Vector3& GetMin() const { return mMin; }
    const Vector3& GetMax() const { return mMax; }

    // Expand the bounding box to include a point
    void ExpandToFit(const Vector3& point);

private:
    Vector3 mMin;
    Vector3 mMax;
};

} // namespace math
