package algorithm.sorting;

/**
 * BubbleSort
 */
public class BubbleSort extends Sort {
  @Override
  protected int[] sort(int[] arr, SortType type) {
    int length = arr.length;

    for (int i = 0; i < length; i++) {
      for (int j = 0; j < length - i - 1; j++) {
        if (super.compare(arr[j], arr[j + 1], type)) {
          super.swap(arr, j, j + 1);
        }
      }
    }

    return arr;
  }
}