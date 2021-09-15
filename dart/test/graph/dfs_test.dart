import 'package:test/test.dart';

import 'package:algorithm/graph/dfs.dart';
import 'package:algorithm/graph/graph.dart';

void main() {
  test('dfs', () {
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

    final pred = dfsSearch(g, 0);
    final expected = [-1, 0, -1, 4, 1, 2];

    expect(pred, expected);
  });
}
