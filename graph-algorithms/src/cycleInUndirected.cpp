#include "cycleInUndirected.hpp"

#include "utils.hpp"

bool CycleInUndirected::isUndirectedGraphCyclic(
    std::vector<std::vector<int>>& adjencyList, std::vector<bool>& visited,
    std::vector<int>& parents, int src, int par, int& start, int& end) {
  visited[src] = true;
  for (int nextNode : adjencyList[src]) {
    if (nextNode == par) continue;
    if (visited[nextNode]) {
      end = src;
      start = nextNode;
      return true;
    }
    parents[nextNode] = src;
    if (isUndirectedGraphCyclic(adjencyList, visited, parents, nextNode, src,
                                start, end)) {
      return true;
    }
  }
  return false;
}

CycleInUndirected::CycleInUndirected(int nodes, int edges)
    : GraphInput(nodes, edges) {}

bool CycleInUndirected::detectCycleInUndirectedGraph() {
  int nodes = getNodes();
  std::vector<std::vector<int>> adjencyList = getAdjacencyList();
  std::vector<bool> visited(nodes, false);
  std::vector<int> parents(nodes, -1);
  int end, start;
  for (int i = 0; i < nodes; ++i) {
    if (!visited[i] && isUndirectedGraphCyclic(adjencyList, visited, parents, i,
                                               -1, start, end)) {
      printCycle(parents, start, end);
      return true;
    }
  }
  return false;
}
