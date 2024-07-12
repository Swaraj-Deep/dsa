#ifndef CYCLE_IN_DIRECTED_H
#define CYCLE_IN_DIRECTED_H

#include <vector>

#include "graphInput.hpp"

class CycleInUndirected : public GraphInput {
 private:
  bool isUndirectedGraphCyclic(std::vector<std::vector<int>> &adjencyList,
                             std::vector<bool> &visited,
                             std::vector<int> &parents, int src, int par,
                             int &start, int &end);

 public:
  CycleInUndirected(int nodes, int edges);
  bool detectCycleInUndirectedGraph();
};

#endif