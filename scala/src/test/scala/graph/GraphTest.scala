package graph

class GraphTest extends org.scalatest.funsuite.AnyFunSuite {
  test("Graph init") {
    val n: Int = 5;
    val directed: Boolean = false;

    val g = new Graph(n, directed);
    assert(g.n == n);
    assert(g.directed == directed);

    g.addEdge(0, 1)
    g.addEdge(1, 2)
    g.addEdge(1, 3)
    g.addEdge(1, 4)
    g.addEdge(2, 3)
    g.addEdge(4, 2)

    assert(g.isEdge(0, 1) == true);
    assert(g.isEdge(0, 2) == false);

    assert(g.getEdgeWeight(0, 1) == 1);

    g.removeEdge(0, 1);
    assert(g.isEdge(0, 1) == false);
  }
}
