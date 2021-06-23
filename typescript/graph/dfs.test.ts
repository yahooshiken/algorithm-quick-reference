import { assertEquals } from "https://deno.land/std@0.99.0/testing/asserts.ts";
import dfsSearch from "./dfs.ts";
import Graph from "./graph.ts";

Deno.test("DFS (Depth First Search)", () => {
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

  const pred = dfsSearch(g, 0);
  const expected = [-1, 0, -1, 4, 1, 2];

  assertEquals(pred, expected);
});
