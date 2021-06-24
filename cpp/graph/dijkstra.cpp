#include "dijkstra.h"
#include "binary_heap.h"

void dijkstra(Graph const &g, int s, vector<int> &dist, vector<int> &pred) {
  const int n = g.numVertices();

  pred.assign(n, -1);
  dist.assign(n, numeric_limits<int>::max());

  dist[s] = 0;
  BinaryHeap pq(n);

  for (int u = 0; u < n; u++) {
    pq.insert(u, dist[u]);
  }

  while (!pq.isEmpty()) {
    int u = pq.smallest();

    for (VertexList::const_iterator ci = g.begin(u); ci != g.end(u); ++ci) {
      int v = ci->first;
      long newLen = dist[u];
      newLen += ci->second;

      if (newLen < dist[v]) {
        pq.decreaseKey(v, newLen);
        dist[v] = newLen;
        pred[v] = u;
      }
    }
  }
}