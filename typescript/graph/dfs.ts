import Graph from "./graph.ts";

const vertexColor = ["White", "Gray", "Black"] as const;
type VertexColor = typeof vertexColor[number];

const dfsVisit = (
  graph: Graph,
  u: number,
  pred: number[],
  color: VertexColor[]
) => {
  color[u] = "Gray";

  for (const [v, w] of graph.getVertices(u)) {
    if (color[v] === "White") {
      pred[v] = u;
      dfsVisit(graph, v, pred, color);
    }
  }

  color[u] = "Black";
};

const dfsSearch = (graph: Graph, start: number): number[] => {
  const n = graph.getVerticesNum();
  const color: VertexColor[] = Array(n).fill("White");
  const pred: number[] = Array(n).fill(-1);

  dfsVisit(graph, start, pred, color);

  for (let u = 0; u < n; u++) {
    if (color[u] == "White") {
      dfsVisit(graph, u, pred, color);
    }
  }

  return pred;
};

export default dfsSearch;
