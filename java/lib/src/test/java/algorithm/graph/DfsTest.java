package algorithm.graph;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

import java.util.List;

import org.checkerframework.checker.units.qual.g;
import org.junit.jupiter.api.Test;

public class DfsTest {
  @Test
  void test_dfs() {
    int n = 6;
    Graph g = new Graph(n, true);
    Dfs dfs = new Dfs();

    try {
      g.addEdge(0, 1);
      g.addEdge(0, 3);
      g.addEdge(1, 4);
      g.addEdge(2, 5);
      g.addEdge(2, 4);
      g.addEdge(3, 1);
      g.addEdge(4, 3);
      g.addEdge(5, 5);

      List<Integer> pred = dfs.dfsSearch(g, 0);
      int[] expected = { -1, 0, -1, 4, 1, 2 };

      assertArrayEquals(expected, pred.stream().mapToInt(i -> i).toArray());

    } catch (Exception e) {
    }

  }
}
