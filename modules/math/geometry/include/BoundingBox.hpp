#pragma once

#include <array>

namespace math{

class BoundingBox {
public:
    BoundingBox(float x, float y, float z, float size);

    // Check if this bounding box contains another
    bool Contains(const BoundingBox& other) const;

    // Check if this bounding box intersects another
    bool Intersects(const BoundingBox& other) const;

    // Get the bounds of a child box for octree subdivision
    BoundingBox GetChildBounds(int index) const;

private:
    float x, y, z; // Center of the bounding box
    float size;    // Half-size of the bounding box
};

}