#ifndef GRAPH_OUTPUT_H
#define GRAPH_OUTPUT_H

#include <vector>

class GraphOutput {
 private:
  std::vector<int> ans;

 public:
  GraphOutput();
  std::vector<int> &getAnsVector();
  void printAns();
};

#endif