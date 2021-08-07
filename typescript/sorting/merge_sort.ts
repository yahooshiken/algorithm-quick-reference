import Sort, { SortType, SORT_TYPE } from "./sort.ts";

class MergeSort extends Sort {
  private workArr: number[];

  constructor() {
    super();
    this.workArr = [];
  }

  sort(arr: number[], type: SortType = SORT_TYPE.asc): number[] {
    const length = arr.length;
    return this.mergeSort(arr, 0, length - 1, type);
  }

  mergeSort(
    arr: number[],
    low: number,
    high: number,
    type: SortType
  ): number[] {
    if (low >= high) {
      return arr;
    }

    const middle = Math.floor((low + high) / 2);

    this.mergeSort(arr, low, middle, type);
    this.mergeSort(arr, middle + 1, high, type);

    for (let i = low; i <= middle; i++) {
      this.workArr[i] = arr[i];
    }

    for (let i = middle + 1, j = high; i <= high; i++, j--) {
      this.workArr[i] = arr[j];
    }

    let i = low;
    let j = high;

    for (let k = low; k <= high; k++) {
      if (this.compare(this.workArr[j], this.workArr[i], type)) {
        arr[k] = this.workArr[i++];
      } else {
        arr[k] = this.workArr[j--];
      }
    }
    return arr;
  }
}

export default MergeSort;
