package algorithm.sorting;

public class InsertionSort extends Sort {
  @Override
  protected int[] sort(int[] arr, SortType type) {
    int length = arr.length;

    for (int i = 1; i < length; i++) {
      int j = i;
      while (j >= 1 && super.compare(arr[j - 1], arr[j], type)) {
        super.swap(arr, j - 1, j);
        j--;
      }
    }

    return arr;
  }
}
