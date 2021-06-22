#include "graph.h"

bool Graph::isEdge(int u, int v) const {
  for (VertexList::const_iterator edge_iter = vertices_[u].begin();
       edge_iter != vertices_[u].end(); ++edge_iter) {
    if (edge_iter->first == v) {
      return true;
    }
  }

  return false;
}

bool Graph::isEdge(int u, int v, int &w) const {
  for (VertexList::const_iterator edge_iter = vertices_[u].begin();
       edge_iter != vertices_[u].end(); ++edge_iter) {
    if (edge_iter->first == v) {
      w = edge_iter->second;
      return true;
    }
  }

  return false;
}

void Graph::addEdge(int u, int v, int w) {
  if (u > n_ || v > n_) {
    throw "Graph::addEdge given vertex larger than graph size";
  }

  pair<int, int> edge(v, w);
  vertices_[u].push_front(edge);

  if (!directed_) {
    pair<int, int> edgeR(u, w);
    vertices_[v].push_front(edgeR);
  }
}

bool Graph::removeEdge(int u, int v) {
  bool found = false;

  for (VertexList::const_iterator edge_iter = vertices_[u].begin();
       edge_iter != vertices_[u].end(); ++edge_iter) {
    if (edge_iter->first == v) {
      vertices_[u].remove(*edge_iter);
      found = true;
      break;
    }
  }

  if (!found) {
    return false;
  }

  if (!directed_) {
    for (VertexList::const_iterator edge_iter = vertices_[v].begin();
         edge_iter != vertices_[v].end(); ++edge_iter) {
      if (edge_iter->first == u) {
        vertices_[v].remove(*edge_iter);
        break;
      }
    }
  }

  return true;
}

int Graph::edgeWeight(int u, int v) const {
  for (VertexList::const_iterator edge_iter = vertices_[u].begin();
       edge_iter != vertices_[u].end(); ++edge_iter) {
    if (edge_iter->first == v) {
      return edge_iter->second;
    }
  }

  return numeric_limits<int>::min();
}
