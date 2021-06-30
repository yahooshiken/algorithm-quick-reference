import { assertEquals } from "https://deno.land/std@0.99.0/testing/asserts.ts";

import jarnikPrim from "./jarnik_prim.ts";
import Graph from "./graph.ts";

Deno.test("Jarnik-Prim", () => {
  const n = 5;
  const g = new Graph(n, false);

  g.addEdge(0, 1, 2);
  g.addEdge(0, 4, 4);
  g.addEdge(0, 3, 8);
  g.addEdge(1, 2, 3);
  g.addEdge(2, 3, 5);
  g.addEdge(2, 4, 1);
  g.addEdge(3, 4, 7);

  const pred = jarnikPrim(g);
  const expectedPred = [-1, 0, 1, 2, 2];

  assertEquals(pred, expectedPred);
});
