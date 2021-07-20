import { assertEquals } from "https://deno.land/std@0.99.0/testing/asserts.ts";

import BubbleSort from "./bubble_sort.ts";
import { SORT_TYPE } from "./sort.ts";

Deno.test("Bubble sort", () => {
  const arr: number[] = [76, 34, 67, 32, 78, 45];
  const sorter: BubbleSort = new BubbleSort();

  const sorted_asc: number[] = sorter.sort(arr, SORT_TYPE.asc);
  const expected_asc: number[] = [32, 34, 45, 67, 76, 78];
  assertEquals(sorted_asc, expected_asc);

  const sorted_desc: number[] = sorter.sort(arr, SORT_TYPE.desc);
  const expected_desc: number[] = [78, 76, 67, 45, 34, 32];
  assertEquals(sorted_desc, expected_desc);
});
