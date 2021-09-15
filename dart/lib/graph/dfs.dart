import 'graph.dart';
import 'color.dart';

void dfsVisit(Graph graph, int u, List<int> pred, List<Color> colors) {
  colors[u] = Color.gray;

  for (var pair in graph.getVertices(u)) {
    final v = pair.first;
    if (colors[v] == Color.white) {
      pred[v] = u;
      dfsVisit(graph, v, pred, colors);
    }
  }

  colors[u] = Color.black;
}

List<int> dfsSearch(Graph graph, int start) {
  final n = graph.n;
  final pred = List.generate(n, (_) => -1);
  final colors = List.generate(n, (_) => Color.white);

  dfsVisit(graph, start, pred, colors);

  for (var u = 0; u < n; u++) {
    if (colors[u] == Color.white) {
      dfsVisit(graph, u, pred, colors);
    }
  }

  return pred;
}
