#include <iostream>

#include "dijkstra.h"

using namespace std;

int main() {
  int n = 7;
  Graph g(n);

  g.addEdge(0, 1, 10);
  g.addEdge(0, 3, 5);
  g.addEdge(1, 2, 1);
  g.addEdge(1, 3, 2);
  g.addEdge(2, 4, 4);
  g.addEdge(3, 1, 3);
  g.addEdge(3, 2, 9);
  g.addEdge(3, 4, 2);
  g.addEdge(4, 0, 7);
  g.addEdge(4, 2, 6);
  g.addEdge(5, 6, 2);

  vector<int> dist(n);
  vector<int> pred(n);

  dijkstra(g, 0, dist, pred);

  for (int i = 0; i < n; i++) {
    cout << i << ". " << dist[i] << " " << pred[i] << "\n";
  }

  const int int_max = numeric_limits<int>::max();
  const int expectedDist[] = {0, 7, 8, 5, 7, int_max, int_max};
  const int expectedPred[] = {-1, 3, 1, 0, 0, -1, -1};
  for (int i = 0; i < n; i++) {
    assert(expectedDist[i] == dist[i]);
    assert(expectedPred[i] == pred[i]);
  }

  cout << "Passed test" << endl;
}