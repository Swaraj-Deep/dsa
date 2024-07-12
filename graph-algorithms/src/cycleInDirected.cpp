#include "cycleInDirected.hpp"

#include <algorithm>
#include <vector>

#include "utils.hpp"

bool CycleInDirected::isDirectedGraphCyclic(
    std::vector<std::vector<int>>& adjencyList, std::vector<bool>& visited,
    std::vector<bool>& inCurrentRecur, std::vector<int>& parents, int src,
    int& start, int& end) {
  visited[src] = true;
  inCurrentRecur[src] = true;
  for (int nextNode : adjencyList[src]) {
    if (!visited[nextNode] &&
        isDirectedGraphCyclic(adjencyList, visited, inCurrentRecur, parents,
                              nextNode, start, end)) {
      parents[nextNode] = src;
      return true;
    } else if (inCurrentRecur[nextNode]) {
      end = src;
      start = nextNode;
      return true;
    }
  }
  inCurrentRecur[src] = false;
  return false;
}

CycleInDirected::CycleInDirected(int nodes, int edges)
    : GraphInput(nodes, edges){};

bool CycleInDirected::detectCycleInDirectedGraph() {
  int nodes = getNodes();
  std::vector<std::vector<int>> adjencyList = getAdjacencyList();
  std::vector<bool> visited(nodes, false);
  std::vector<bool> inCurrentRecur(nodes, false);
  std::vector<int> parents(nodes, -1);
  int end, start;
  for (int i = 0; i < nodes; ++i) {
    if (!visited[i] &&
        isDirectedGraphCyclic(adjencyList, visited, inCurrentRecur, parents, i,
                              start, end)) {
      printCycle(parents, start, end);
      return true;
    }
  }
  return false;
}

bool CycleInDirected::isDirectedGraphCyclicWithColors(
    std::vector<std::vector<int>>& adjencyList, std::vector<int>& colors,
    std::vector<int>& parents, int src, int& start, int& end) {
  colors[src] = 1;
  for (int nextNode : adjencyList[src]) {
    if (colors[nextNode] == 0) {
      parents[nextNode] = src;
      if (isDirectedGraphCyclicWithColors(adjencyList, colors, parents,
                                          nextNode, start, end)) {
        return true;
      }
    } else if (colors[nextNode] == 1) {
      start = nextNode;
      end = src;
      return true;
    }
  }
  colors[src] = 2;
  return false;
}

bool CycleInDirected::detectCycleInDirectedGraphWithColors() {
  int nodes = getNodes();
  std::vector<std::vector<int>> adjencyList = getAdjacencyList();
  std::vector<int> colors(nodes, 0);
  std::vector<int> parents(nodes, -1);
  int end, start;
  for (int i = 0; i < nodes; ++i) {
    if (colors[i] == 0 && isDirectedGraphCyclicWithColors(
                              adjencyList, colors, parents, i, start, end)) {
      printCycle(parents, start, end);
      return true;
    }
  }
  return false;
}