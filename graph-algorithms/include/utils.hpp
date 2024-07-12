#ifndef UTILS_H
#define UTILS_H

#include <algorithm>
#include <iostream>

inline void fastIo() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
}

inline void printCycle(std::vector<int>& parents, int start, int end) {
  std::vector<int> cycle;
  cycle.push_back(start);
  for (int v = end; v != start; v = parents[v]) cycle.push_back(v);
  std::reverse(cycle.begin(), cycle.end());

  std::cout << "Cycle found: ";
  for (int v : cycle) std::cout << v << " ";
  std::cout << '\n';
}

#endif