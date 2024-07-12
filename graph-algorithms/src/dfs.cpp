#include "dfs.hpp"

#include <iostream>

DFS::DFS(int nodes, int edges) : GraphInput(nodes, edges) {}

void DFS::dfs(std::vector<std::vector<int>>& adj, std::vector<bool>& visited,
              int src, std::vector<int>& ans) {
  ans.push_back(src);
  visited[src] = true;
  for (int nextNode : adj[src]) {
    if (!visited[nextNode]) {
      dfs(adj, visited, nextNode, ans);
    }
  }
}

void DFS::dfsTraversal() {
  std::vector<std::vector<int>> adj = getAdjacencyList();
  int nodes = getNodes();
  std::vector<bool> visited(nodes, false);
  std::vector<int> ans;
  for (int i = 0; i < nodes; i++) {
    if (!visited[i]) {
      dfs(adj, visited, i, ans);
    }
  }
  for (int n : ans) {
    std::cout << n << ' ';
  }
  std::cout << '\n';
}