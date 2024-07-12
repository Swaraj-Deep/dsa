#ifndef CYCLE_IN_DIRECTED_H
#define CYCLE_IN_DIRECTED_H

#include <vector>

#include "graphInput.hpp"

class CycleInDirected : public GraphInput {
 private:
  bool isDirectedGraphCyclic(std::vector<std::vector<int>> &adjencyList,
                             std::vector<bool> &visited,
                             std::vector<bool> &inCurrentRecur,
                             std::vector<int> &parents, int src, int &start,
                             int &end);

  bool isDirectedGraphCyclicWithColors(
      std::vector<std::vector<int>> &adjencyList, std::vector<int> &colors,
      std::vector<int> &parents, int src, int &start, int &end);

 public:
  CycleInDirected(int nodes, int edges);
  bool detectCycleInDirectedGraph();

  bool detectCycleInDirectedGraphWithColors();
};

#endif