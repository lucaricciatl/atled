#include "BoundingBox.hpp"

namespace math{
BoundingBox::BoundingBox(float x, float y, float z, float size)
    : x(x), y(y), z(z), size(size) {}

bool BoundingBox::Contains(const BoundingBox& other) const {
    return (other.x - other.size >= x - size && other.x + other.size <= x + size &&
            other.y - other.size >= y - size && other.y + other.size <= y + size &&
            other.z - other.size >= z - size && other.z + other.size <= z + size);
}

bool BoundingBox::Intersects(const BoundingBox& other) const {
    return (x - size <= other.x + other.size && x + size >= other.x - other.size &&
            y - size <= other.y + other.size && y + size >= other.y - other.size &&
            z - size <= other.z + other.size && z + size >= other.z - other.size);
}

BoundingBox BoundingBox::GetChildBounds(int index) const {
    float offset = size / 2.0f;
    float childSize = size / 2.0f;

    float newX = x + ((index & 1) ? offset : -offset);
    float newY = y + ((index & 2) ? offset : -offset);
    float newZ = z + ((index & 4) ? offset : -offset);

    return BoundingBox(newX, newY, newZ, childSize);
}
}