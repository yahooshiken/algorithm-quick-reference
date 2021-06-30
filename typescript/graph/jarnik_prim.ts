import Graph from "./graph.ts";
import PriorityQueue, { INode } from "./priority_queue.ts";

const jarnikPrim = (graph: Graph): number[] => {
  const n = graph.getVerticesNum();
  const pred: number[] = Array(n).fill(-1);
  const weights: number[] = Array(n).fill(Number.MAX_SAFE_INTEGER);
  weights[0] = 0;

  const pq = new PriorityQueue<number>();
  const inQueue: boolean[] = Array(n).fill(true);

  for (let v = 0; v < n; v++) {
    const node: INode<number> = { value: v, priority: weights[v] };
    pq.enqueue(node);
  }

  while (!pq.isEmpty()) {
    const u = pq.dequeue()?.value as number;
    inQueue[u] = false;

    for (const [v, w] of graph.getVertices(u)) {
      if (inQueue[v] && w < weights[v]) {
        pred[v] = u;
        weights[v] = w;
        pq.updatePriority({ value: v, priority: w });
      }
    }
  }

  return pred;
};

export default jarnikPrim;
