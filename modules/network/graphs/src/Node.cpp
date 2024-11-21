#include "Node.hpp"
#include "Edge.hpp"

Node::Node(const std::string &name) : name(name) {}

const std::string &Node::getName() const { return name; }

const std::vector<Edge *> &Node::getEdges() const { return edges; }

void Node::addEdge(Edge *edge) {
  if (edge) {
    edges.push_back(edge);
  }
}

bool Node::isConnectedTo(const Node *other) const {
  for (const auto &edge : edges) {
    if (edge->getDestination() == other || edge->getSource() == other) {
      return true;
    }
  }
  return false;
}
