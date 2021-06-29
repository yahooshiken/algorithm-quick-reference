import Graph from "./graph.ts";
import PriorityQueue from "./priority_queue.ts";

const dijkstra = (g: Graph, start: number) => {
  const n = g.getVerticesNum();

  const pred: number[] = Array(n).fill(-1);
  const dist: number[] = Array(n).fill(Number.MAX_SAFE_INTEGER);

  dist[start] = 0;
  const pq = new PriorityQueue<number>();

  for (let u = 0; u < n; u++) {
    const node = { value: u, priority: dist[u] };
    pq.enqueue(node);
  }

  while (!pq.isEmpty()) {
    const u = pq.dequeue()?.value as number;

    for (const [v, w] of g.getVertices(u)) {
      const newLength = dist[u] + w;

      if (newLength < dist[v]) {
        pq.updatePriority({ value: v, priority: newLength });
        dist[v] = newLength;
        pred[v] = u;
      }
    }
  }

  return { pred, dist };
};

export default dijkstra;
