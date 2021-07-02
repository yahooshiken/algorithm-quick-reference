package algorithm.graph

typealias Vertex = Pair<Int, Int>

typealias VertexList = MutableList<Vertex>

public class Graph(_n: Int, _directed: Boolean = false) {
  val n: Int
  val directed: Boolean
  val vertices: Array<VertexList>

  init {
    n = _n
    directed = _directed
    vertices = Array(n) { _ -> mutableListOf<Vertex>() }
  }

  fun getVertices(u: Int): VertexList {
    return vertices[u]
  }

  fun getEdgeWeight(u: Int, v: Int): Int {
    val vertex: Vertex? = vertices[u].find { pair -> pair.first == v }

    return if (vertex != null) vertex.second else Int.MIN_VALUE
  }

  fun isEdge(u: Int, v: Int): Boolean {
    if (u > n || v > n) {
      return false
    }

    return getVertices(u).any { pair -> pair.first == v }
  }

  fun addEdge(u: Int, v: Int, w: Int = 1) {
    if (u > n || v > n) {
      throw Exception("Graph.addEdge given vertex larger than graph size")
    }

    val edge: Vertex = Vertex(v, w)
    vertices[u].add(edge)

    if (!directed) {
      val edgeR: Vertex = Vertex(u, w)
      vertices[v].add(edgeR)
    }
  }

  fun removeEdge(u: Int, v: Int): Boolean {
    var found: Boolean = false

    for (vertex in vertices[u]) {
      if (v == vertex.first) {
        vertices[u].remove(vertex)
        found = true
        break
      }
    }

    if (!found) {
      return false
    }

    if (!directed) {
      for (vertex in vertices[v]) {
        if (u == vertex.first) {
          vertices[v].remove(vertex)
          break
        }
      }
    }

    return true
  }
}
