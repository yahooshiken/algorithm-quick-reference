import Sort, { SortType, SORT_TYPE } from "./sort.ts";

class QuickSort extends Sort {
  sort(arr: number[], type: SortType = SORT_TYPE.asc): number[] {
    const length = arr.length;
    return this.quickSort(arr, 0, length - 1, type);
  }

  quickSort(
    arr: number[],
    low: number,
    high: number,
    type: SortType
  ): number[] {
    if (low < high) {
      const pivot = this.partition(arr, low, high, type);
      this.quickSort(arr, low, pivot - 1, type);
      this.quickSort(arr, pivot + 1, high, type);
    }

    return arr;
  }

  partition(arr: number[], low: number, high: number, type: SortType): number {
    const pivot = arr[high];

    let i = low - 1;
    let j = high;

    while (true) {
      while (super.compare(pivot, arr[++i], type));
      while (i < --j && super.compare(arr[j], pivot, type));
      if (j <= i) break;

      [arr[i], arr[j]] = [arr[j], arr[i]];
    }

    [arr[i], arr[high]] = [arr[high], arr[i]];
    return i;
  }
}

export default QuickSort;
