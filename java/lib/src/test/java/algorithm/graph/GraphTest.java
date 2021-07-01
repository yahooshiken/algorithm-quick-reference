package algorithm.graph;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;

import org.junit.jupiter.api.Test;

public class GraphTest {
  @Test
  void test_graph() {
    int n = 5;
    boolean directed = false;
    Graph g = new Graph(n, directed);

    assertEquals(n, g.getN());
    assertEquals(directed, g.isDirected());

    try {
      g.addEdge(0, 1);
      g.addEdge(1, 2);
      g.addEdge(1, 3);
      g.addEdge(1, 4);
      g.addEdge(2, 3);
      g.addEdge(4, 2);

      assertTrue(g.isEdge(0, 1));
      assertTrue(!g.isEdge(0, 2));
      assertEquals(1, g.getEdgeWeight(0, 1));

      g.removeEdge(0, 1);
      assertTrue(!g.isEdge(0, 1));
    } catch (Exception e) {
      System.out.println("Error");
    }

  }
}
