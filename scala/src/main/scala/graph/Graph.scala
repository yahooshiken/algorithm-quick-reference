package graph;

class Graph(val n: Int, val directed: Boolean) {
  var vertices: Array[Seq[(Int, Int)]] = Array.fill(n)(Seq());

  def getVertices(u: Int): Seq[(Int, Int)] = vertices(u);

  def getEdgeWeight(u: Int, v: Int): Int = {
    vertices(u).find(p => p._1 == v) match {
      case Some(pair) => pair._2
      case None       => Int.MinValue
    }
  }

  def isEdge(u: Int, v: Int): Boolean = {
    if (u > n || v > n) false else getVertices(u).exists(p => p._1 == v);
  }

  def addEdge(u: Int, v: Int, w: Int = 1) = {
    if (u > n || v > n)
      throw new Exception("Graph.addEdge given vertex larger than graph size");

    val edge: (Int, Int) = (v, w);
    vertices.update(u, getVertices(u) :+ edge);

    if (!directed) {
      val edgeR: (Int, Int) = (u, w);
      vertices.update(v, getVertices(v) :+ edgeR);
    }
  }

  def removeEdge(u: Int, v: Int) = {
    vertices.update(u, getVertices(u).filter(p => p._1 != v))
  }
}
