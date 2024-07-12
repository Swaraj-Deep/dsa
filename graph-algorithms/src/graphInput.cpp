#include "graphInput.hpp"

#include <iostream>

#include "utils.hpp"

GraphInput::GraphInput(int numberOfNodes, int numberOfEdges)
    : nodes(numberOfNodes),
      edges(numberOfEdges),
      adjacencyList(numberOfNodes + 10),
      weightedAdjacencyList(numberOfNodes + 10),
      inDegrees(numberOfNodes + 10, 0) {
  fastIo();
}

int GraphInput::getNodes() const { return nodes; }

int GraphInput::getEdges() const { return edges; }

std::vector<std::vector<int>> GraphInput::getAdjacencyList() const {
  return adjacencyList;
}

std::vector<std::vector<std::pair<int, int>>>
GraphInput::getWeightedAdjacencyList() const {
  return weightedAdjacencyList;
}

std::vector<int> GraphInput::getInDegrees() const { return inDegrees; }

void GraphInput::takeInputDirected() {
  int u, v;
  for (int i = 0; i < edges; i++) {
    std::cin >> u >> v;
    inDegrees[v]++;
    adjacencyList[u].push_back(v);
  }
}

void GraphInput::takeInputUndirected() {
  int u, v;
  for (int i = 0; i < edges; i++) {
    std::cin >> u >> v;
    adjacencyList[u].push_back(v);
    adjacencyList[v].push_back(u);
  }
}

void GraphInput::takeInputWeightedAndDirected() {
  int u, v, weight;
  for (int i = 0; i < edges; i++) {
    std::cin >> u >> v >> weight;
    inDegrees[v]++;
    weightedAdjacencyList[u].push_back({v, weight});
  }
}

void GraphInput::takeInputWeightedAndUndirected() {
  int u, v, weight;
  for (int i = 0; i < edges; i++) {
    std::cin >> u >> v >> weight;
    weightedAdjacencyList[u].push_back({v, weight});
    weightedAdjacencyList[v].push_back({u, weight});
  }
}