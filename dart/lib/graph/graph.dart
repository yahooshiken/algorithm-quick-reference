import 'dart:developer';

import 'package:algorithm/graph/pair.dart';

class Graph {
  int n;
  bool directed;
  List<List<Pair>> vertices;

  Graph(this.n, this.directed) : vertices = List<List<Pair>>.filled(n, []);

  List<Pair> getVertices(int u, int v) {
    return vertices[u];
  }

  int getEdgeWeight(int u, int v) {
    const int64MinValue = -9223372036854775808;
    final edge = vertices[u]
        .firstWhere((p) => p.first == v, orElse: () => Pair(0, int64MinValue));
    return edge.second;
  }

  bool isEdge(int u, int v) {
    if (u > n || v > n) {
      return false;
    }

    return vertices[u].any((p) => p.first == v);
  }

  void addEdge(int u, int v, [int w = 1]) {
    if (u > n || v > n) {
      throw Exception('Graph.addEdge given vertex larger than graph size');
    }

    final edge = Pair(v, w);
    vertices[u] = [edge, ...vertices[u]];

    if (!directed) {
      final edgeR = Pair(u, w);
      vertices[v] = [edgeR, ...vertices[v]];
    }
  }

  bool removeEdge(int u, int v) {
    var found = false;

    for (var vertex in vertices[u]) {
      if (v == vertex.first) {
        vertices[u].remove(vertex);
        found = true;
        break;
      }
    }

    if (!found) {
      return false;
    }

    if (!directed) {
      for (var vertex in vertices[v]) {
        if (u == vertex.first) {
          vertices[v].remove(vertex);
          break;
        }
      }
    }

    return true;
  }
}
