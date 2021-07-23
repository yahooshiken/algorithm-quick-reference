import Sort, { SortType, SORT_TYPE } from "./sort.ts";

class SelectionSort extends Sort {
  sort(arr: number[], type: SortType = SORT_TYPE.asc): number[] {
    const length: number = arr.length;

    for (let i = 0; i < length - 1; i++) {
      let minIndex: number = i;
      for (let j = i + 1; j < length; j++) {
        if (super.compare(arr[minIndex], arr[j], type)) {
          minIndex = j;
        }
      }
      [arr[minIndex], arr[i]] = [arr[i], arr[minIndex]];
    }
    return arr;
  }
}

export default SelectionSort;
