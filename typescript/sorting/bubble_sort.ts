import Sort, { SortType } from "./sort.ts";

class BubbleSort extends Sort {
  sort(arr: number[], type: SortType): number[] {
    const length: number = arr.length;

    for (let i = 0; i < length; i++) {
      for (let j = 0; j < length - i - 1; j++) {
        if (super.compare(arr[j], arr[j + 1], type)) {
          [arr[j + 1], arr[j]] = [arr[j], arr[j + 1]];
        }
      }
    }

    return arr;
  }
}

export default BubbleSort;
