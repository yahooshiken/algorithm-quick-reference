#include <cassert>
#include <iostream>

#include "dfs.h"
#include "graph.h"

using namespace std;

int main(int argc, char const *argv[]) {
  const int n = 6;

  Graph g(n, true);

  g.addEdge(0, 3);
  g.addEdge(0, 1);
  g.addEdge(1, 4);
  g.addEdge(2, 5);
  g.addEdge(2, 4);
  g.addEdge(3, 1);
  g.addEdge(4, 3);
  g.addEdge(5, 5);

  vector<int> pred(g.numVertices());

  dfsSearch(g, 0, pred);

  for (int i = 0; i < n; i++) {
    cout << i << ": " << pred[i] << endl;
  }

  int expected[] = {-1, 0, -1, 4, 1, 2};
  for (int i = 0; i < n; i++) {
    assert(expected[i] == pred[i]);
  }

  cout << "Passed test" << endl;

  return 0;
}
