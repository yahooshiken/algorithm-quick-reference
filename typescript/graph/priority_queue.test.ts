import { assertEquals } from "https://deno.land/std@0.99.0/testing/asserts.ts";

import PriorityQueue from "./priority_queue.ts";

Deno.test("Priority Queue", () => {
  const pq = new PriorityQueue();
  assertEquals(pq.isEmpty(), true);
  pq.enqueue({ value: 0, priority: 10 });
  assertEquals(pq.isEmpty(), false);

  pq.enqueue({ value: 1, priority: 5 });
  assertEquals(pq.dequeue()?.value, 1);
  assertEquals(pq.dequeue()?.value, 0);
  assertEquals(pq.isEmpty(), true);

  pq.enqueue({ value: 2, priority: 9 });
  pq.enqueue({ value: 3, priority: 2 });
  pq.enqueue({ value: 4, priority: 15 });
  pq.enqueue({ value: 5, priority: 11 });
  pq.enqueue({ value: 6, priority: 1 });
  assertEquals(pq.dequeue(), { value: 6, priority: 1 });
  assertEquals(pq.dequeue(), { value: 3, priority: 2 });
  pq.updatePriority({ value: 4, priority: 3 });
  assertEquals(pq.dequeue(), { value: 4, priority: 3 });
  assertEquals(pq.dequeue(), { value: 2, priority: 9 });
  assertEquals(pq.dequeue(), { value: 5, priority: 11 });
});
