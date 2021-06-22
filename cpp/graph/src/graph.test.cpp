#include <cassert>
#include <iostream>

#include "graph.h"

int main(int argc, char const *argv[]) {
  const int n = 5;
  const int directed = false;
  Graph g(n, directed);

  assert(g.numVertices() == n);
  assert(g.isDirected() == directed);

  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(1, 3);
  g.addEdge(1, 4);
  g.addEdge(2, 3);
  g.addEdge(4, 2);

  assert(g.isEdge(0, 1));
  assert(!g.isEdge(0, 2));
  assert(g.edgeWeight(0, 1) == 1);

  g.removeEdge(0, 1);
  assert(!g.isEdge(0, 1));

  assert(g.begin(1)->first == 4);
  assert(g.begin(1)->second == 1);

  cout << "Passed test" << endl;

  return 0;
}
