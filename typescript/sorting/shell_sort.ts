import Sort, { SortType, SORT_TYPE } from "./sort.ts";

class ShellSort extends Sort {
  sort(arr: number[], type: SortType = SORT_TYPE.asc): number[] {
    const length: number = arr.length;

    let gap: number = 1;
    while (gap < length / 9) {
      gap = gap * 3 + 1;
    }

    while (gap > 0) {
      for (let i = gap; i < length; i++) {
        let j = i;
        while (j >= gap && super.compare(arr[j - gap], arr[j], type)) {
          [arr[j - gap], arr[j]] = [arr[j], arr[j - gap]];
          j--;
        }
      }

      gap = gap / 3;
    }

    return arr;
  }
}

export default ShellSort;
