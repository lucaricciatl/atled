#ifndef NODE_HPP
#define NODE_HPPgit 

#include <string>
#include <unordered_map>
#include <vector>

class Edge; // Forward declaration

class Node {
public:
  explicit Node(const std::string &name);

  // Getters
  const std::string &getName() const;
  const std::vector<Edge *> &getEdges() const;

  // Add an edge connection to this node
  void addEdge(Edge *edge);

  // Check if this node is connected to another node
  bool isConnectedTo(const Node *other) const;

private:
  std::string name;
  std::vector<Edge *> edges;
};

#endif // NODE_HPP
