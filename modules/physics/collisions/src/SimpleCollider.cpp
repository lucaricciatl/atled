#include <vector>
#include <set>
#include <algorithm>
#include <utility> // for std::minmax
#include "body.hpp"
#include "BoundingBox.hpp"
#include "Octree.hpp" // Assuming you have an octree implementation
#include <SimpleCollider.hpp>
#include "rigidbody.hpp"

namespace physics {
    namespace {
        math::Vector3 ComputeCollisionForce(
            const math::Vector3& position1, const math::Vector3& velocity1, float mass1,
            const math::Vector3& position2, const math::Vector3& velocity2, float mass2,
            const math::Vector3& collisionNormal, float restitution
        ) {
            // Ensure collision normal is a unit vector
            math::Vector3 normal = collisionNormal.normalized();

            // Compute relative velocity
            math::Vector3 relativeVelocity = velocity2 - velocity1;

            // Compute velocity along the collision normal
            float relativeNormalVelocity = relativeVelocity.dot(normal);

            // If the bodies are separating, no collision response is needed
            if (relativeNormalVelocity > 0) {
                return math::Vector3(0, 0, 0);
            }

            // Compute impulse magnitude
            float impulse = -(1 + restitution) * relativeNormalVelocity /
                ((1 / mass1) + (1 / mass2));

            // Compute collision force vector
            math::Vector3 collisionForce = normal * impulse;

            return collisionForce;
        }
    }

SimpleCollider::SimpleCollider()
{
    // Constructor body can be empty if initialization lists are sufficient
}

void SimpleCollider::AddBody(Body* body) {
    if (body) {
        bodies.push_back(body);
        //octree.Insert(body, body->GetBoundingBox());
    }
}

bool SimpleCollider::DetectCollisions(Body* a, Body* b) {
    // Ensure both bodies are valid
    if (!a || !b) {
        return false;
    }
    math::Vector3 collisionNormal;
    // First, do a bounding box intersection test
    if (a->GetBoundingBox().Intersects(b->GetBoundingBox())) {
        if (MeshCollisionTest(*a->mMesh, *a->mFrame, *b->mMesh, *b->mFrame, collisionNormal)) {
            HandleCollision(a, b, collisionNormal);
        }
    }

    // No intersection found
    return false;
}

bool SimpleCollider::MeshCollisionTest(const graphics::Mesh& meshA, const Frame& frameA,
    const graphics::Mesh& meshB, const Frame& frameB, math::Vector3& collisionNormal) const {
    // Transform all vertices of mesh A and mesh B into world space
    // Then test all triangles of A against all triangles of B.
    //
    // NOTE: This is a brute-force approach and not optimized.

    std::vector<math::Vector3> verticesA = meshA.GetOrderedVertices();
    std::vector<unsigned short> indicesA = meshA.GetIndices();
    std::vector<math::Vector3> verticesB = meshB.GetOrderedVertices();
    std::vector<unsigned short> indicesB = meshB.GetIndices();

    // Apply the frame transforms to vertices
    // Assuming Frame can provide a transform matrix or position/orientation:
    // If Frame has GetTransformMatrix(), use it. Otherwise, apply translation, rotation, etc.

    // For simplicity, let's say frameA and frameB have methods to transform points:
    auto transformA = [&](const math::Vector3& v) { return v; };
    auto transformB = [&](const math::Vector3& v) { return v; };

    for (size_t i = 0; i < indicesA.size(); i += 3) {
        math::Vector3 A1 = transformA(verticesA[indicesA[i]]);
        math::Vector3 A2 = transformA(verticesA[indicesA[i + 1]]);
        math::Vector3 A3 = transformA(verticesA[indicesA[i + 2]]);

        for (size_t j = 0; j < indicesB.size(); j += 3) {
            math::Vector3 B1 = transformB(verticesB[indicesB[j]]);
            math::Vector3 B2 = transformB(verticesB[indicesB[j + 1]]);
            math::Vector3 B3 = transformB(verticesB[indicesB[j + 2]]);

            if (TriangleTriangleIntersection(A1, A2, A3, B1, B2, B3)) {
                // Compute collision normal
                math::Vector3 normalA = (A2 - A1).cross(A3 - A1); // Triangle A normal
                math::Vector3 normalB = (B2 - B1).cross(B3 - B1); // Triangle B normal
                if (normalA.isZero()) {
                    // Fallback for degenerate triangles: Use a default normal or skip
                    normalA = math::Vector3(0, 1, 0); // Example fallback normal (Z-axis)
                }
                else {
                    normalA = normalA.normalized();
                }
                if (normalB.isZero()) {
                    // Fallback for degenerate triangles
                    normalB = math::Vector3(0, 1, 0); // Example fallback normal (Z-axis)
                }
                else {
                    normalB = normalB.normalized();
                }
                // Average the normals to determine the collision normal
                collisionNormal = (normalA + normalB).normalized();

                return true; // Collision detected
            }
        }
    }

    return false;
}


    bool SimpleCollider::TriangleTriangleIntersection(
        const math::Vector3& A1, const math::Vector3& A2, const math::Vector3& A3,
        const math::Vector3& B1, const math::Vector3& B2, const math::Vector3& B3) const
    {
        // Define the triangles as edges
        math::Vector3 edgeA1 = A2 - A1;
        math::Vector3 edgeA2 = A3 - A2;
        math::Vector3 edgeA3 = A1 - A3;

        math::Vector3 edgeB1 = B2 - B1;
        math::Vector3 edgeB2 = B3 - B2;
        math::Vector3 edgeB3 = B1 - B3;

        // Step 1: Test triangle normals as separating axes
        math::Vector3 normalA = edgeA1.cross(edgeA2);
        math::Vector3 normalB = edgeB1.cross(edgeB2);

        if (areTrianglesSeparatedByAxis(normalA, A1, A2, A3, B1, B2, B3)) {
            return false; // Separated
        }
        if (areTrianglesSeparatedByAxis(normalB, A1, A2, A3, B1, B2, B3)) {
            return false; // Separated
        }

        // Step 2: Test edge cross products as separating axes
        const math::Vector3 edgesA[] = { edgeA1, edgeA2, edgeA3 };
        const math::Vector3 edgesB[] = { edgeB1, edgeB2, edgeB3 };

        for (const auto& ea : edgesA) {
            for (const auto& eb : edgesB) {
                math::Vector3 axis = ea.cross(eb);
                if (areTrianglesSeparatedByAxis(axis, A1, A2, A3, B1, B2, B3)) {
                    return false; // Separated
                }
            }
        }

        // No separating axis found; triangles intersect
        return true;
    }

    // Helper function to test separation along an axis
    bool SimpleCollider::areTrianglesSeparatedByAxis(
        const math::Vector3& axis,
        const math::Vector3& A1, const math::Vector3& A2, const math::Vector3& A3,
        const math::Vector3& B1, const math::Vector3& B2, const math::Vector3& B3) const
    {
        if (axis.isZero()) {
            return false; // Degenerate axis (zero-length), cannot separate
        }

        // Project all vertices onto the axis
        float aMin, aMax, bMin, bMax;
        projectTriangleOntoAxis(axis, A1, A2, A3, aMin, aMax);
        projectTriangleOntoAxis(axis, B1, B2, B3, bMin, bMax);

        // Check for overlap
        return (aMax < bMin || bMax < aMin); // Separated if true
    }

    // Helper function to project a triangle onto an axis
    void SimpleCollider::projectTriangleOntoAxis(
        const math::Vector3& axis,
        const math::Vector3& V1, const math::Vector3& V2, const math::Vector3& V3,
        float& outMin, float& outMax) const
    {
        // Project each vertex onto the axis
        float p1 = V1.dot(axis);
        float p2 = V2.dot(axis);
        float p3 = V3.dot(axis);

        // Compute min and max projection
        outMin = std::min({ p1, p2, p3 });
        outMax = std::max({ p1, p2, p3 });
    }

    void SimpleCollider::HandleCollision(Body* body1, Body* body2, const math::Vector3& collisionNormal) {
        // Retrieve body properties
        math::Vector3 position1 = body1->GetFrame()->GetVectorPosition();
        math::Vector3 velocity1 = body1->GetAccumulatedForce() / body1->GetMass();
        float mass1 = body1->GetMass();

        math::Vector3 position2 = body2->GetFrame()->GetVectorPosition();
        math::Vector3 velocity2 = body2->mVelocity;
        float mass2 = body2->GetMass();

        // Coefficient of restitution (adjust as needed)
        float restitution = 500.0f; // Example value for a somewhat elastic collision

        // Compute collision force
        math::Vector3 force = physics::ComputeCollisionForce(
            position1, velocity1, mass1,
            position2, velocity2, mass2,
            collisionNormal, restitution
        );

        // Apply forces to the bodies

// Check if body1 is not static and apply reaction force
        if (!body1->IsStatic()) {
            body1->ApplyForce(-force); // Reaction force on body1
        }

        // Check if body2 is not static and apply action force
        if (!body2->IsStatic()) {
            body2->ApplyForce(force); // Action force on body2
        }
    }
} 