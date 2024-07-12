#include "bfs.hpp"

#include <iostream>
#include <queue>

BFS::BFS(int nodes, int edges) : GraphInput(nodes, edges) {}

void BFS::bfs(std::vector<std::vector<int>>& adj, std::vector<bool>& visited,
              int src, std::vector<int>& ans) {
  std::queue<int> q;
  q.push(src);
  visited[src] = true;
  while (!q.empty()) {
    int currNode = q.front();
    q.pop();
    visited[currNode] = true;
    ans.push_back(currNode);
    for (int nextNode : adj[currNode]) {
      if (!visited[nextNode]) {
        visited[nextNode] = true;
        q.push(nextNode);
      }
    }
  }
}

void BFS::bfsTraversal() {
  std::vector<std::vector<int>> adj = getAdjacencyList();
  int nodes = getNodes();
  std::vector<bool> visited(nodes, false);
  std::vector<int> ans;
  for (int i = 0; i < nodes; i++) {
    if (!visited[i]) {
      bfs(adj, visited, i, ans);
    }
  }
  for (int n : ans) {
    std::cout << n << ' ';
  }
  std::cout << '\n';
}