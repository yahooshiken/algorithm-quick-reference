package algorithm.sorting;

public class MergeSort extends Sort {
  private int[] workArr;

  public void setWorkArr(int length) {
    workArr = new int[length];
  }

  private int[] mergeSort(int[] arr, int low, int high, SortType type) {
    if (low >= high) {
      return arr;
    }

    int middle = (low + high) / 2;

    mergeSort(arr, low, middle, type);
    mergeSort(arr, middle + 1, high, type);

    for (int i = low; i <= middle; i++) {
      workArr[i] = arr[i];
    }

    for (int i = middle + 1, j = high; i <= high; i++, j--) {
      workArr[i] = arr[j];
    }

    int i = low, j = high;
    for (int k = low; k <= high; k++) {
      if (super.compare(workArr[j], workArr[i], type)) {
        arr[k] = workArr[i++];
      } else {
        arr[k] = workArr[j--];
      }
    }

    return arr;
  }

  protected int[] sort(int[] arr, SortType type) {
    int length = arr.length;
    setWorkArr(length);
    return mergeSort(arr, 0, length - 1, type);
  }
}
