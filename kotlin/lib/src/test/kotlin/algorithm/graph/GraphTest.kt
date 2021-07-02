package algorithm.graph

import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertFalse
import kotlin.test.assertTrue

class GraphTest {
  @Test
  fun test() {
    val n: Int = 5
    val directed: Boolean = false
    val g = Graph(n, directed)

    assertEquals(n, g.n)
    assertEquals(directed, g.directed)

    g.addEdge(0, 1)
    g.addEdge(1, 2)
    g.addEdge(1, 3)
    g.addEdge(1, 4)
    g.addEdge(2, 3)
    g.addEdge(4, 2)

    assertTrue(g.isEdge(0, 1))
    assertFalse(g.isEdge(0, 2))
    assertEquals(g.getEdgeWeight(0, 1), 1)

    assertTrue(g.removeEdge(0, 1))
    assertFalse(g.isEdge(0, 1))
  }
}
