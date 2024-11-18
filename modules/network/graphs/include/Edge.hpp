#ifndef EDGE_HPP
#define EDGE_HPP

#include "Node.hpp"

class Edge {
public:
  Edge(Node *source, Node *destination, double weight = 1.0);

  // Getters
  Node *getSource() const;
  Node *getDestination() const;
  double getWeight() const;

  // Connect the edge to its source and destination nodes
  void connect();

private:
  Node *source;
  Node *destination;
  double weight;
};

#endif // EDGE_HPP
