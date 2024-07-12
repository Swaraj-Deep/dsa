#include <iostream>

#include "topologicalsort.hpp"

/**
 * Topological Sorting - DAG (Directed Acyclic Graph) ke liye mast hai Cycle
Detection - Graph mein cycle hai ya nahi, ye pata lagane ke liye Dijkstra's
Algorithm - Shortest path nikalne ke liye, lekin negative edges nahi handle kar
sakta Bellman-Ford Algorithm - Ye negative edges ke saath bhi kaam karta hai
Floyd-Warshall Algorithm - All pairs shortest path ke liye, thoda heavy hai
Prim's Algorithm - Minimum Spanning Tree banane ke liye
Kruskal's Algorithm - Ye bhi MST ke liye hai, Union-Find use karta hai
Strongly Connected Components - Directed graph mein groups dhoondhne ke liye
Articulation Points and Bridges - Graph ke weak points nikalne ke liye
Network Flow Algorithms (Ford-Fulkerson, Edmonds-Karp) - Ye thoda advanced hai,
flow networks ke liye use hota hai
 */

int main() {
  int nodes, edges;

  std::cin >> nodes >> edges;

  try {
    TopologicalSort topologicalSort(nodes, edges);

    topologicalSort.takeInputDirected();

    std::cout << "DFS Traversal: ";
    topologicalSort.topologicalSortDfs();

    std::cout << "BFS Traversal: ";
    topologicalSort.topologicalSortBfs();

  } catch (const char* msg) {
    std::cout << "Error: " << msg << std::endl;
  }

  return 0;
}