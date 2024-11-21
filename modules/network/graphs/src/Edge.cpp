#include "Edge.hpp"

Edge::Edge(Node *source, Node *destination, double weight)
    : source(source), destination(destination), weight(weight) {}

Node *Edge::getSource() const { return source; }

Node *Edge::getDestination() const { return destination; }

double Edge::getWeight() const { return weight; }

void Edge::connect() {
  if (source) {
    source->addEdge(this);
  }
  if (destination) {
    destination->addEdge(this);
  }
}
