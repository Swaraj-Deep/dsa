#include "topologicalsort.hpp"

#include <algorithm>
#include <queue>
#include <vector>

TopologicalSort::TopologicalSort(int nodes, int edges)
    : GraphInput(nodes, edges){};

void TopologicalSort::toposortDfs(std::vector<std::vector<int>>& adjList,
                                  std::vector<bool>& visited,
                                  std::vector<bool>& recStack, int src,
                                  std::vector<int>& ans) {
  visited[src] = true;
  recStack[src] = true;
  for (int nextNode : adjList[src]) {
    if (!visited[nextNode]) {
      toposortDfs(adjList, visited, recStack, nextNode, ans);
    } else if (recStack[nextNode]) {
      throw "Graph has Cycles";
    }
  }
  recStack[src] = false;
  ans.push_back(src);
}

void TopologicalSort::topologicalSortDfs() {
  int nodes = getNodes();
  std::vector<std::vector<int>> adjencyList = getAdjacencyList();
  std::vector<bool> visited(nodes, false);
  std::vector<bool> recStack(nodes, false);
  std::vector<int>& ans = getAnsVector();
  for (int i = 0; i < nodes; i++) {
    if (!visited[i]) {
      toposortDfs(adjencyList, visited, recStack, i, ans);
    }
  }
  std::reverse(ans.begin(), ans.end());
  printAns();
}

void TopologicalSort::toposortBfs(std::vector<std::vector<int>>& adjencyList,
                                  std::vector<int>& ans) {
  std::vector<int> inDegrees = getInDegrees();
  std::queue<int> q;
  int nodes = getNodes();
  for (int i = 0; i < nodes; ++i) {
    if (!inDegrees[i]) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    ans.push_back(node);
    for (int nextNode : adjencyList[node]) {
      inDegrees[nextNode]--;
      if (!inDegrees[nextNode]) {
        q.push(nextNode);
      }
    }
  }
  if (ans.size() != nodes) {
    throw "Graph has Cycles";
  }
}

void TopologicalSort::topologicalSortBfs() {
  int nodes = getNodes();
  std::vector<std::vector<int>> adjencyList = getAdjacencyList();
  std::vector<int>& ans = getAnsVector();
  toposortBfs(adjencyList, ans);
  printAns();
}