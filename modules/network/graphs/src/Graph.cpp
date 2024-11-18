#include "Graph.hpp"
#include <stdexcept>

Node *Graph::addNode(const std::string &name) {
  if (nodes.find(name) != nodes.end()) {
    return nodes[name];
  }

  Node *newNode = new Node(name);
  nodes[name] = newNode;
  return newNode;
}

Edge *Graph::addEdge(const std::string &sourceName,
                     const std::string &destinationName, double weight) {
  Node *source = addNode(sourceName);
  Node *destination = addNode(destinationName);

  Edge *newEdge = new Edge(source, destination, weight);
  edges.push_back(newEdge);

  newEdge->connect(); // Automatically connect nodes and edges
  return newEdge;
}

Node *Graph::findNode(const std::string &name) const {
  auto it = nodes.find(name);
  return (it != nodes.end()) ? it->second : nullptr;
}

const std::unordered_map<std::string, Node *> &Graph::getNodes() const {
  return nodes;
}

const std::vector<Edge *> &Graph::getEdges() const {
  return
