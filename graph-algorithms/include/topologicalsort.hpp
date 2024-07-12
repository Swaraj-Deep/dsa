#ifndef TOPOSORT_H
#define TOPOSORT_H

#include <vector>

#include "graphInput.hpp"
#include "graphOutput.hpp"

class TopologicalSort : public GraphInput, public GraphOutput {
 private:
  void toposortDfs(std::vector<std::vector<int>> &adjencyList,
                   std::vector<bool> &visited, std::vector<bool> &recStack,
                   int src, std::vector<int> &ans);
  void toposortBfs(std::vector<std::vector<int>> &adjencyList,
                   std::vector<int> &ans);

 public:
  TopologicalSort(int nodes, int edges);
  void topologicalSortDfs();
  void topologicalSortBfs();
};

#endif