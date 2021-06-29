import { assertEquals } from "https://deno.land/std@0.99.0/testing/asserts.ts";
import dijkstra from "./dijkstra.ts";
import Graph from "./graph.ts";

Deno.test("Dijkstra", () => {
  const n = 7;
  const g = new Graph(n);

  g.addEdge(0, 1, 10);
  g.addEdge(0, 3, 5);
  g.addEdge(1, 2, 1);
  g.addEdge(1, 3, 2);
  g.addEdge(2, 4, 4);
  g.addEdge(3, 1, 3);
  g.addEdge(3, 2, 9);
  g.addEdge(3, 4, 2);
  g.addEdge(4, 0, 7);
  g.addEdge(4, 2, 6);
  g.addEdge(5, 6, 2);

  const { pred, dist } = dijkstra(g, 0);
  const INT_MAX = Number.MAX_SAFE_INTEGER;
  const expectedPred = [-1, 3, 1, 0, 0, -1, -1];
  const expectedDist = [0, 7, 8, 5, 7, INT_MAX, INT_MAX];

  assertEquals(pred, expectedPred);
  assertEquals(dist, expectedDist);
});
