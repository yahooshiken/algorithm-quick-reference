package algorithm.sorting;

public class SelectionSort extends Sort {
  @Override
  protected int[] sort(int[] arr, SortType type) {
    int length = arr.length;

    for (int i = 0; i < length - 1; i++) {
      int minIndex = i;
      for (int j = i + 1; j < length; j++) {
        if (super.compare(arr[minIndex], arr[j], type)) {
          minIndex = j;
        }
      }
      super.swap(arr, minIndex, i);
    }
    return arr;
  }
}
