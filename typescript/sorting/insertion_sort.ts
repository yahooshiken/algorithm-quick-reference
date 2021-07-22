import Sort, { SortType, SORT_TYPE } from "./sort.ts";

class InsertionSort extends Sort {
  sort(arr: number[], type: SortType = SORT_TYPE.asc): number[] {
    const length: number = arr.length;

    for (let i = 1; i < length; i++) {
      let j = i;
      while (j >= 1 && super.compare(arr[j - 1], arr[j], type)) {
        [arr[j - 1], arr[j]] = [arr[j], arr[j - 1]];
        j--;
      }
    }
    return arr;
  }
}

export default InsertionSort;
