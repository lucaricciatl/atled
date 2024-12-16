#pragma once

#include <vector>
#include <array>
#include <memory>
#include "BoundingBox.hpp" // Assuming this defines a bounding box class

namespace math{
    
template <typename T>
class Octree {
public:
    Octree(const BoundingBox& bounds, int maxDepth = 5, int maxObjects = 10);
    ~Octree() = default;

    // Insert an object into the octree
    void Insert(T object, const BoundingBox& objectBounds);

    // Retrieve potential collisions for a given bounding box
    void Retrieve(std::vector<T>& results, const BoundingBox& queryBounds) const;

    // Clear the octree
    void Clear();

private:
    struct Node {
        BoundingBox bounds;
        std::vector<T> objects;
        std::array<std::unique_ptr<Node>, 8> children;
        bool isLeaf;

        Node(const BoundingBox& bounds);
    };

    // Helper methods
    void Subdivide(Node& node);
    int GetChildIndex(const Node& node, const BoundingBox& objectBounds) const;
    void RetrieveFromNode(const Node& node, std::vector<T>& results, const BoundingBox& queryBounds) const;

    Node root;
    int maxDepth;
    int maxObjects;
};

// Constructor for the Octree class
template <typename T>
Octree<T>::Octree(const BoundingBox& bounds, int maxDepth, int maxObjects)
    : root(bounds), maxDepth(maxDepth), maxObjects(maxObjects) {}

// Constructor for a Node in the Octree
template <typename T>
Octree<T>::Node::Node(const BoundingBox& bounds)
    : bounds(bounds), isLeaf(true) {}

// Insert an object into the Octree
template <typename T>
void Octree<T>::Insert(T object, const BoundingBox& objectBounds) {
    // Insert into the root node
    Node* currentNode = &root;
    for (int depth = 0; depth < maxDepth; ++depth) {
        if (currentNode->isLeaf) {
            currentNode->objects.push_back(object);

            // Subdivide if necessary
            if (currentNode->objects.size() > maxObjects && depth < maxDepth - 1) {
                Subdivide(*currentNode);
            } else {
                return;
            }
        }

        // Determine the appropriate child node
        int index = GetChildIndex(*currentNode, objectBounds);
        if (index == -1) {
            return; // Object does not fit fully within any child
        }

        currentNode = currentNode->children[index].get();
    }
}

// Retrieve potential collisions
template <typename T>
void Octree<T>::Retrieve(std::vector<T>& results, const BoundingBox& queryBounds) const {
    RetrieveFromNode(root, results, queryBounds);
}

// Clear the Octree
template <typename T>
void Octree<T>::Clear() {
    root.objects.clear();
    root.children.fill(nullptr);
    root.isLeaf = true;
}

// Subdivide a node
template <typename T>
void Octree<T>::Subdivide(Node& node) {
    BoundingBox bounds = node.bounds;
    for (int i = 0; i < 8; ++i) {
        BoundingBox childBounds = bounds.GetChildBounds(i); // Assuming this method exists
        node.children[i] = std::make_unique<Node>(childBounds);
    }
    
    // Reassign objects to children
    for (T& object : node.objects) {
        for (int i = 0; i < 8; ++i) {
            if (node.children[i]->bounds.Contains(object->GetBoundingBox())) {
                node.children[i]->objects.push_back(object);
                break;
            }
        }
    }

    node.objects.clear();
    node.isLeaf = false;
}

// Get the index of the child node for an object
template <typename T>
int Octree<T>::GetChildIndex(const Node& node, const BoundingBox& objectBounds) const {
    for (int i = 0; i < 8; ++i) {
        if (node.children[i] && node.children[i]->bounds.Contains(objectBounds)) {
            return i;
        }
    }
    return -1; // Object does not fully fit within any child
}

// Retrieve potential collisions from a node
template <typename T>
void Octree<T>::RetrieveFromNode(const Node& node, std::vector<T>& results, const BoundingBox& queryBounds) const {
    for (const T& object : node.objects) {
        results.push_back(object);
    }

    if (!node.isLeaf) {
        for (const auto& child : node.children) {
            if (child && child->bounds.Intersects(queryBounds)) {
                RetrieveFromNode(*child, results, queryBounds);
            }
        }
    }
}

}