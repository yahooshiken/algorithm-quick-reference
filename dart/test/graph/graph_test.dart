import 'dart:math';

import 'package:algorithm/graph/graph.dart';
import 'package:test/test.dart';

void main() {
  final n = 5;
  final directed = false;
  final g = Graph(n, directed);

  test('Graph', () {
    expect(g.n, n);
    expect(g.directed, directed);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(4, 2);

    expect(g.isEdge(0, 1), true);
    expect(g.isEdge(0, 2), false);

    expect(g.getEdgeWeight(0, 1), 1);

    expect(g.removeEdge(0, 1), true);
    expect(g.removeEdge(0, 2), false);
    expect(g.isEdge(0, 1), false);
  });
}
