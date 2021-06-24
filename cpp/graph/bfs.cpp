#include <iostream>

#include "bfs.h"

void bfsSearch(Graph const &graph, int s, vector<int> &dist,
               vector<int> &pred) {
  const int n = graph.numVertices();
  pred.assign(n, -1);
  dist.assign(n, numeric_limits<int>::max());

  vector<vertexColor> color(n, White);

  dist[s] = 0;
  color[s] = Gray;

  queue<int> q;
  q.push(s);

  while (!q.empty()) {
    int u = q.front();

    for (VertexList::const_iterator iter = graph.begin(u); iter != graph.end(u);
         ++iter) {
      int v = iter->first;
      if (color[v] == White) {
        dist[v] = dist[u] + 1;
        pred[v] = u;
        color[v] = Gray;
        q.push(v);
      }
    }

    q.pop();
    color[u] = Black;
  }
}