#ifndef BFS_H
#define BFS_H

#include <vector>

#include "graphInput.hpp"

class BFS : public GraphInput {
 private:
  void bfs(std::vector<std::vector<int>>& adj, std::vector<bool>& visited,
           int src, std::vector<int>& ans);

 public:
  BFS(int nodes, int edges);
  void bfsTraversal();
};

#endif
