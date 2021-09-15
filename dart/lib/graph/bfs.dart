import 'dart:collection';

import 'graph.dart';
import 'color.dart';

const int64Max = 9223372036854775807;

List<int> bfsSearch(Graph graph, int start) {
  final n = graph.n;
  final dist = List.generate(n, (_) => int64Max);
  final pred = List.generate(n, (_) => -1);
  final colors = List.generate(n, (_) => Color.white);

  dist[start] = 0;
  colors[start] = Color.gray;

  final q = Queue<int>();
  q.add(start);

  while (q.isNotEmpty) {
    final u = q.removeLast();
    for (var pair in graph.getVertices(u)) {
      final v = pair.first;
      if (colors[v] == Color.white) {
        dist[v] = dist[u] + 1;
        pred[v] = u;
        colors[v] = Color.gray;
        q.add(v);
      }
    }
    q.removeLast();
    colors[u] = Color.black;
  }

  return pred;
}
