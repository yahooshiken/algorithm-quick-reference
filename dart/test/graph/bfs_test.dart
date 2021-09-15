import 'package:test/test.dart';

import 'package:algorithm/graph/graph.dart';
import 'package:algorithm/graph/bfs.dart';

void main() {
  test('bfs', () {
    const n = 6;
    final g = Graph(n, true);

    g.addEdge(0, 3);
    g.addEdge(0, 1);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 4);
    g.addEdge(3, 1);
    g.addEdge(4, 3);
    g.addEdge(5, 5);

    final pred = bfsSearch(g, 0);
    final expected = [-1, 0, -1, 0, 1, -1];

    expect(pred, expected);
  });
}
