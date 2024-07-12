#ifndef DFS_H
#define DFS_H

#include <vector>

#include "graphInput.hpp"

class DFS : public GraphInput {
 private:
  void dfs(std::vector<std::vector<int>>& adj, std::vector<bool>& visited,
           int src, std::vector<int>& ans);

 public:
  DFS(int nodes, int edges);
  void dfsTraversal();
};

#endif
