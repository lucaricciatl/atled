#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "Edge.hpp"
#include "Node.hpp"
#include <string>
#include <unordered_map>
#include <vector>

class Graph {
public:
  Node *addNode(const std::string &name);
  Edge *addEdge(const std::string &sourceName,
                const std::string &destinationName, double weight = 1.0);

  Node *findNode(const std::string &name) const;
  const std::unordered_map<std::string, Node *> &getNodes() const;
  const std::vector<Edge *> &getEdges() const;

private:
  std::unordered_map<std::string, Node *> nodes;
  std::vector<Edge *> edges;
};

#endif // GRAPH_HPP
