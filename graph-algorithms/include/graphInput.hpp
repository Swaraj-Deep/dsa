#ifndef GRAPHINPUT_H
#define GRAPHINPUT_H

#include <iostream>
#include <vector>

class GraphInput {
 private:
  int nodes, edges;
  std::vector<std::vector<int>> adjacencyList;
  std::vector<std::vector<std::pair<int, int>>> weightedAdjacencyList;
  std::vector<int> inDegrees;

 public:
  GraphInput(int numberOfNodes, int numberOfEdges);
  int getNodes() const;
  int getEdges() const;
  std::vector<std::vector<int>> getAdjacencyList() const;
  std::vector<std::vector<std::pair<int, int>>> getWeightedAdjacencyList()
      const;
  std::vector<int> getInDegrees() const;
  void takeInputDirected();
  void takeInputUndirected();
  void takeInputWeightedAndDirected();
  void takeInputWeightedAndUndirected();
};

#endif