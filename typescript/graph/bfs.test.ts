import { assertEquals } from "https://deno.land/std@0.99.0/testing/asserts.ts";

import bfsSearch from "./bfs.ts";
import Graph from "./graph.ts";

Deno.test("BFS (Breadth First Search)", () => {
  const n = 6;
  const g = new Graph(n, true);

  g.addEdge(0, 3);
  g.addEdge(0, 1);
  g.addEdge(1, 4);
  g.addEdge(2, 5);
  g.addEdge(2, 4);
  g.addEdge(3, 1);
  g.addEdge(4, 3);
  g.addEdge(5, 5);

  const { dist, pred } = bfsSearch(g, 0);
  for (let i = 0; i < n; i++) {
    console.info(`i: ${i}, dist[i]: ${dist[i]}, pred[i]: ${pred[i]}`);
  }

  // prettier-ignore
  const expectedDist = [0, 1, Number.MAX_SAFE_INTEGER, 1, 2, Number.MAX_SAFE_INTEGER];
  assertEquals(dist, expectedDist);
  const expectedPred = [-1, 0, -1, 0, 1, -1];
  assertEquals(pred, expectedPred);
});
