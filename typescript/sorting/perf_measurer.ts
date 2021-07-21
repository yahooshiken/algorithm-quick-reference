import { performance } from "https://deno.land/std@0.102.0/node/perf_hooks.ts";

import Sort from "./sort.ts";

const shuffleArr = (arr: number[]): number[] => {
  for (let i = arr.length - 1; i > 0; i--) {
    const j = Math.floor(Math.random() * (i + 1));
    [arr[i], arr[j]] = [arr[j], arr[i]];
  }
  return arr;
};

class PerfMeasurer {
  private sorter: Sort;

  constructor(sorter: Sort) {
    this.sorter = sorter;
  }

  public reportPerf(): string {
    const sizes: number[] = [100, 200, 500, 1000, 2000, 5000, 10000];

    let str: string = "";
    for (const size of sizes) {
      const arr: number[] = [...Array(size).keys()];
      const shuffled: number[] = shuffleArr(arr);

      const start: number = performance.now();
      this.sorter.sort(shuffled);
      const end: number = performance.now();
      const diff: number = end - start;

      str += `Time to sort an array of size ${size} is ${diff / 1000} sec\n`;
    }

    return str;
  }
}

export default PerfMeasurer;
