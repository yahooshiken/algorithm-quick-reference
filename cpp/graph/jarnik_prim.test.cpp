#include <cassert>
#include <iostream>

#include "jarnik_prim.h"

using namespace std;

int main() {
  const int n = 5;
  Graph g(n, false);

  g.addEdge(0, 1, 2);
  g.addEdge(0, 4, 4);
  g.addEdge(0, 3, 8);
  g.addEdge(1, 2, 3);
  g.addEdge(2, 3, 5);
  g.addEdge(2, 4, 1);
  g.addEdge(3, 4, 7);

  vector<int> pred(n);

  jarnikPrim(g, pred);

  assert(pred[0] == -1);
  assert(pred[1] == 0);
  assert(pred[2] == 1);
  assert(pred[3] == 2);
  assert(pred[4] == 2);

  cout << "Tests passed" << endl;

  return 0;
}
