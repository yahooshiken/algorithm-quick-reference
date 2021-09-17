import 'package:algorithm/graph/dijkstra.dart';
import 'package:algorithm/graph/graph.dart';
import 'package:test/test.dart';

void main() {
  test('Dijkstra', () {
    const n = 7;
    final g = Graph(n, false);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(3, 1, 3);
    g.addEdge(3, 2, 9);
    g.addEdge(3, 4, 2);
    g.addEdge(4, 0, 7);
    g.addEdge(4, 2, 6);
    g.addEdge(5, 6, 2);

    final result = dijkstra(g, 0);
    final expectedPred = [-1, 3, 1, 0, 0, -1, -1];
    final expectedDist = [0, 7, 8, 5, 7, int64Max, int64Max];

    expect(result[0], expectedPred);
    expect(result[1], expectedDist);
  });
}
