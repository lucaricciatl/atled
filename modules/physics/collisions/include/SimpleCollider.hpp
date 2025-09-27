#pragma once

#include <vector>
#include "body.hpp"
#include "Octree.hpp"
#include "BoundingBox.hpp"

namespace physics {

    class SimpleCollider {
    public:
        SimpleCollider();

        void AddBody(Body* body);
        bool DetectCollisions(Body* a, Body* b);
        void Setdt(float adt) { dt = adt; };
    private:
        // Retrieves potential collision candidates for a given bounding box

        // Performs a more expensive and precise collision check
        bool MeshCollisionTest(const graphics::Mesh& meshA, const Frame& frameA, const graphics::Mesh& meshB, const Frame& frameB, math::Vector3& collisionNormal, float& penetrationDepth) const;
        bool TriangleTriangleIntersection(const math::Vector3& A1, const math::Vector3& A2, const math::Vector3& A3, const math::Vector3& B1, const math::Vector3& B2, const math::Vector3& B3) const;
        bool areTrianglesSeparatedByAxis(
            const math::Vector3& axis,
            const math::Vector3& A1, const math::Vector3& A2, const math::Vector3& A3,
            const math::Vector3& B1, const math::Vector3& B2, const math::Vector3& B3) const;
        void HandleCollision(Body* body1, Body* body2, const math::Vector3& collisionNormal, float penetrationDepth);
        void projectTriangleOntoAxis(
            const math::Vector3& axis,
            const math::Vector3& V1, const math::Vector3& V2, const math::Vector3& V3,
            float& outMin, float& outMax) const;
        // Member variables
        //math::Octree<Body*> octree;           // Assuming this is defined elsewhere
        std::vector<Body*> bodies;
        float dt ;
    };


} // namespace physics
