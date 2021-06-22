#include "dfs.h"

void dfsVisit(Graph const &graph, int u, vector<int> &pred,
              vector<vertexColor> &color) {
  color[u] = Gray;

  for (VertexList::const_iterator edge_iter = graph.begin(u);
       edge_iter != graph.end(u); ++edge_iter) {
    int v = edge_iter->first;

    if (color[v] == White) {
      pred[v] = u;
      dfsVisit(graph, v, pred, color);
    }
  }

  color[u] = Black;
}

void dfsSearch(Graph const &graph, int s, vector<int> &pred) {
  const int n = graph.numVertices();
  vector<vertexColor> color(n, White);
  pred.assign(n, -1);

  dfsVisit(graph, s, pred, color);

  for (int u = 0; u < n; u++) {
    if (color[u] == White) {
      dfsVisit(graph, u, pred, color);
    }
  }
}
