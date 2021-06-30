#include "binary_heap.h"
#include "graph.h"

void jarnikPrim(Graph const &graph, vector<int> &pred) {
  const int n = graph.numVertices();
  pred.assign(n, -1);

  vector<int> key(n, numeric_limits<int>::max());
  key[0] = 0;

  BinaryHeap pq(n);
  vector<bool> inQueue(n, true);

  for (int v = 0; v < n; v++) {
    pq.insert(v, key[v]);
  }

  while (!pq.isEmpty()) {
    int u = pq.smallest();
    inQueue[u] = false;

    for (VertexList::const_iterator ci = graph.begin(u); ci != graph.end(u);
         ++ci) {
      int v = ci->first;
      if (inQueue[v]) {
        int w = ci->second;

        if (w < key[v]) {
          pred[v] = u;
          key[v] = w;
          pq.decreaseKey(v, w);
        }
      }
    }
  }
}