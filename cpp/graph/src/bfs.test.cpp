#include <cassert>
#include <iostream>

#include "bfs.h"

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

  vector<int> dist(g.numVertices());
  vector<int> pred(g.numVertices());

  bfsSearch(g, 0, dist, pred);

  cout << "i: dist[i], pred[i]" << endl;
  for (int i = 0; i < n; i++) {
    cout << i << ": " << dist[i] << ", " << pred[i] << endl;
  }

  cout << "Passed test" << endl;

  return 0;
}
