package algorithm.graph;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Map;

public class Dfs {
  void dfsVisit(Graph graph, int u, List<Integer> pred, List<Color> colors) {
    colors.set(u, Color.gray);

    for (Map<Integer, Integer> m : graph.getVertices(u)) {
      for (Integer v : m.keySet()) {
        if (colors.get(v) == Color.white) {
          pred.set(v, u);
          dfsVisit(graph, v, pred, colors);
        }
      }
    }
    colors.set(u, Color.black);
  }

  List<Integer> dfsSearch(Graph graph, int start) {
    int n = graph.getN();
    List<Integer> pred = new ArrayList<Integer>(Collections.nCopies(n, -1));
    List<Color> colors = new ArrayList<Color>(Collections.nCopies(n, Color.white));

    dfsVisit(graph, start, pred, colors);

    for (int u = 0; u < n; u++) {
      if (colors.get(u) == Color.white) {
        dfsVisit(graph, u, pred, colors);
      }
    }

    return pred;
  }

}
