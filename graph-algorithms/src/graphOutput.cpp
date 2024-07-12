#include "graphOutput.hpp"

#include <iostream>
#include <vector>

#include "utils.hpp"

GraphOutput::GraphOutput() { fastIo(); }

std::vector<int> &GraphOutput::getAnsVector() {
  ans.clear();
  return ans;
}

void GraphOutput::printAns() {
  for (int i : ans) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}