type Vertex = [number, number];
type VertexList = Vertex[];

interface IGraph {
  n: number;
  directed: boolean;
  vertices: VertexList[];

  getVerticesNum(): number;
  isDirected(): boolean;
  getVertices(u: number): VertexList;
  isEdge(u: number, v: number): boolean;
  // TODO: isEdge(u: number, v: number, w: number): boolean;
  // TODO: getEdgeWeight(u: number, v: number): number;
  addEdge(u: number, v: number, w?: number): void;
  // TODO: removeEdge(u: number, v: number): boolean;
}

class Graph implements IGraph {
  n: number;
  directed: boolean;
  vertices: VertexList[];

  constructor(n: number, directed?: boolean) {
    this.n = n;
    this.directed = directed ?? false;
    this.vertices = Array(n).fill([]);
  }

  getVerticesNum(): number {
    return this.n;
  }

  getVertices(u: number): VertexList {
    return this.vertices[u];
  }

  isDirected(): boolean {
    return this.directed;
  }

  isEdge(u: number, v: number): boolean {
    if (u > this.n || v > this.n) {
      return false;
    }

    return this.vertices[u].some(([v_, w_]) => v === v_);
  }

  addEdge(u: number, v: number, w: number = 1): void {
    if (u > this.n || v > this.n) {
      throw new Error("Graph.addEdge given vertex larger than graph size");
    }

    const edge: Vertex = [v, w];
    this.vertices[u] = [edge, ...this.vertices[u]];

    if (!this.directed) {
      const edgeR: Vertex = [u, w];
      this.vertices[v] = [edgeR, ...this.vertices[v]];
    }
  }
}

export default Graph;
