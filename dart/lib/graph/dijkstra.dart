import 'package:algorithm/collections/priority_queue.dart';
import 'package:algorithm/graph/graph.dart';

const int64Max = 92233720368547758;

List<List<int>> dijkstra(Graph g, int start) {
  final n = g.n;

  final pred = List.generate(n, (_) => -1);
  final dist = List.generate(n, (_) => int64Max);

  dist[start] = 0;
  final pq = PriorityQueue<int>();

  for (var u = 0; u < n; u++) {
    final node = Node(u, dist[u]);
    pq.enqueue(node);
  }

  while (!pq.isEmpty()) {
    final u = pq.dequeue()?.value as int;

    for (final pair in g.getVertices(u)) {
      final int v = pair.first;
      final int w = pair.second;
      final newLength = dist[u] + w;

      if (newLength < dist[v]) {
        pq.updatePriority(Node(v, newLength));
        dist[v] = newLength;
        pred[v] = u;
      }
    }
  }

  return [pred, dist];
}
