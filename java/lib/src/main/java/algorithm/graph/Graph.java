package algorithm.graph;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class Graph {
  private int n;
  private boolean directed;
  private List<List<Map<Integer, Integer>>> vertices;

  public Graph() {
    this.n = 0;
    this.directed = false;
    this.vertices = new ArrayList<List<Map<Integer, Integer>>>();

    for (int i = 0; i < n; i++) {
      List<Map<Integer, Integer>> innerList = new ArrayList<Map<Integer, Integer>>();
      this.vertices.add(innerList);
    }
  }

  public Graph(int n) {
    this.n = n;
    this.directed = false;
    this.vertices = new ArrayList<List<Map<Integer, Integer>>>();

    for (int i = 0; i < n; i++) {
      List<Map<Integer, Integer>> innerList = new ArrayList<Map<Integer, Integer>>();
      this.vertices.add(innerList);
    }
  }

  public Graph(int n, boolean directed) {
    this.n = n;
    this.directed = directed;
    this.vertices = new ArrayList<List<Map<Integer, Integer>>>();

    for (int i = 0; i < n; i++) {
      List<Map<Integer, Integer>> innerList = new ArrayList<Map<Integer, Integer>>();
      this.vertices.add(innerList);
    }

  }

  public int getN() {
    return n;
  }

  public boolean isDirected() {
    return directed;
  }

  public List<Map<Integer, Integer>> getVertices(int u) {
    return vertices.get(u);
  }

  public void setVertices(int u, Map<Integer, Integer> pair) {
    this.vertices.get(u).add(pair);
  }

  public boolean isEdge(int u, int v) {
    for (Map<Integer, Integer> m : this.getVertices(u)) {
      if (m.containsKey(v)) {
        return true;
      }
    }

    return false;
  }

  public int getEdgeWeight(int u, int v) {
    for (Map<Integer, Integer> m : this.getVertices(u)) {
      if (m.containsKey(v)) {
        return m.get(v);
      }
    }

    return Integer.MIN_VALUE;

  }

  public void addEdge(int u, int v) throws Exception {
    this.addEdge(u, v, 1);
  }

  public void addEdge(int u, int v, int w) throws Exception {
    if (u > this.n || v > this.n) {
      throw new Exception("Graph::addEdge given vertex larger than graph size");
    }

    Map<Integer, Integer> edge = Map.of(v, w);
    this.setVertices(u, edge);

    if (!this.directed) {
      Map<Integer, Integer> edgeR = Map.of(u, w);
      this.setVertices(v, edgeR);

    }
  }

  boolean removeEdge(int u, int v) {
    boolean found = false;

    for (Map<Integer, Integer> m : this.getVertices(u)) {
      if (m.containsKey(v)) {
        this.getVertices(u).remove(m);
        found = true;
        break;
      }
    }

    if (!found) {
      return false;
    }

    if (!this.directed) {
      for (Map<Integer, Integer> m : this.getVertices(v)) {
        if (m.containsKey(u)) {
          this.getVertices(v).remove(m);
          break;
        }
      }
    }

    return true;
  }
}
