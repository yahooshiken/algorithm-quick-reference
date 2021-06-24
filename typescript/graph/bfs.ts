import Graph from "./graph.ts";
import Queue from "./queue.ts";

const vertexColor = ["White", "Gray", "Black"] as const;
type VertexColor = typeof vertexColor[number];

const bfsSearch = (
  graph: Graph,
  start: number
): { dist: number[]; pred: number[] } => {
  const n = graph.getVerticesNum();
  const pred: number[] = Array(n).fill(-1);
  const dist: number[] = Array(n).fill(Number.MAX_SAFE_INTEGER);
  const color: VertexColor[] = Array(n).fill("White");

  dist[start] = 0;
  color[start] = "Gray";

  const q = new Queue<number>();
  q.enqueue(start);

  while (!q.isEmpty()) {
    const u = q.peek() as number;

    for (const [v, w] of graph.getVertices(u)) {
      if (color[v] === "White") {
        dist[v] = dist[u] + 1;
        pred[v] = u;
        color[v] = "Gray";
        q.enqueue(v);
      }
    }

    q.dequeue();
    color[u] = "Black";
  }

  return { pred, dist };
};

export default bfsSearch;
