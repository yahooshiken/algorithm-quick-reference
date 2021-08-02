import { assertEquals } from "https://deno.land/std@0.99.0/testing/asserts.ts";

import QuickSort from "./quick_sort.ts";
import { SORT_TYPE } from "./sort.ts";
import PerfMeasurer from "./perf_measurer.ts";

Deno.test("Quick sort", () => {
  const arr: number[] = [76, 34, 67, 32, 78, 45];
  const sorter: QuickSort = new QuickSort();

  const sortedAsc: number[] = sorter.sort(arr, SORT_TYPE.asc);
  const expectedAsc: number[] = [32, 34, 45, 67, 76, 78];
  assertEquals(sortedAsc, expectedAsc);

  const perfMeasurer = new PerfMeasurer(sorter);
  console.log(perfMeasurer.reportPerf());
});
