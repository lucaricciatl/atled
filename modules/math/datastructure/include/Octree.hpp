#pragma once

#include <vector>
#include <array>
#include <memory>
#include "BoundingBox.hpp" // Make sure this header defines math::BoundingBox with methods like Contains(), Intersects(), and GetChildBounds()

namespace math {

    template <typename T>
    class Octree {
    public:
        Octree(const BoundingBox& bounds, int maxDepth = 5, int maxObjects = 10);
        ~Octree() = default;

        // Insert an object into the Octree.
        // object: The object to insert.
        // objectBounds: The bounding box of the object.
        void Insert(T object, const BoundingBox& objectBounds);

        // Retrieve potential collisions for a given bounding box.
        // results: The vector to store retrieved objects.
        // queryBounds: The bounding box to query against.
        void Retrieve(std::vector<T>& results, const BoundingBox& queryBounds) const;

        // Clear the Octree completely, removing all objects and subdivisions.
        void Clear();

    private:
        struct Node {
            BoundingBox bounds;
            std::vector<T> objects;
            std::array<std::unique_ptr<Node>, 8> children;
            bool isLeaf;

            explicit Node(const BoundingBox& bounds);
        };

        // Subdivide a leaf node into eight child nodes.
        void Subdivide(Node& node);

        // Determine which child node (if any) can completely contain the given bounds.
        // Returns the index of the child node, or -1 if no single child can contain it.
        int GetChildIndex(const Node& node, const BoundingBox& objectBounds) const;

        // Recursively retrieve objects from a node that might intersect the query bounds.
        void RetrieveFromNode(const Node& node, std::vector<T>& results, const BoundingBox& queryBounds) const;

        Node root;
        int maxDepth;
        int maxObjects;
    };

    // ---- Implementation ----

    template <typename T>
    Octree<T>::Octree(const BoundingBox& bounds, int maxDepth, int maxObjects)
        : root(bounds), maxDepth(maxDepth), maxObjects(maxObjects) {
    }

    template <typename T>
    Octree<T>::Node::Node(const BoundingBox& bounds)
        : bounds(bounds), isLeaf(true) {
    }

    template <typename T>
    void Octree<T>::Insert(T object, const BoundingBox& objectBounds) {
        Node* currentNode = &root;
        for (int depth = 0; depth < maxDepth; ++depth) {
            if (currentNode->isLeaf) {
                currentNode->objects.push_back(object);
                // If we exceed the max objects and aren't at the max depth, subdivide.
                if (static_cast<int>(currentNode->objects.size()) > maxObjects && depth < maxDepth - 1) {
                    Subdivide(*currentNode);
                }
                else {
                    return; // Inserted successfully; either no subdiv needed or at max depth
                }
            }

            // Now that node may no longer be a leaf, find the appropriate child for the object.
            int index = GetChildIndex(*currentNode, objectBounds);
            if (index == -1) {
                // Object doesn't fit entirely within a single child node, so we stop.
                // It stays in this node.
                return;
            }

            currentNode = currentNode->children[index].get();
        }
    }

    template <typename T>
    void Octree<T>::Retrieve(std::vector<T>& results, const BoundingBox& queryBounds) const {
        RetrieveFromNode(root, results, queryBounds);
    }

    template <typename T>
    void Octree<T>::Clear() {
        root.objects.clear();
        root.children.fill(nullptr);
        root.isLeaf = true;
    }

    template <typename T>
    void Octree<T>::Subdivide(Node& node) {
        const BoundingBox& bounds = node.bounds;

        // Create eight children using the subdivided bounding boxes.
        for (int i = 0; i < 8; ++i) {
            BoundingBox childBounds = bounds.GetChildBounds(i);
            node.children[i] = std::make_unique<Node>(childBounds);
        }

        // Distribute objects that were in this node to the new children if they fit.
        for (T& object : node.objects) {
            const BoundingBox& objBounds = object->GetBoundingBox();
            for (int i = 0; i < 8; ++i) {
                if (node.children[i]->bounds.Contains(objBounds)) {
                    node.children[i]->objects.push_back(object);
                    break;
                }
            }
        }

        // This node is no longer a leaf.
        node.objects.clear();
        node.isLeaf = false;
    }

    template <typename T>
    int Octree<T>::GetChildIndex(const Node& node, const BoundingBox& objectBounds) const {
        for (int i = 0; i < 8; ++i) {
            if (node.children[i] && node.children[i]->bounds.Contains(objectBounds)) {
                return i;
            }
        }
        return -1; // The object does not fit fully within any single child.
    }

    template <typename T>
    void Octree<T>::RetrieveFromNode(const Node& node, std::vector<T>& results, const BoundingBox& queryBounds) const {
        // Add all objects in this node.
        for (const T& object : node.objects) {
            results.push_back(object);
        }

        // If not a leaf, recurse into children that intersect the query.
        if (!node.isLeaf) {
            for (const auto& child : node.children) {
                if (child && child->bounds.Intersects(queryBounds)) {
                    RetrieveFromNode(*child, results, queryBounds);
                }
            }
        }
    }

} // namespace math
