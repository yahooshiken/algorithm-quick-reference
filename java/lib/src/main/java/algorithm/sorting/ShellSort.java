package algorithm.sorting;

public class ShellSort extends Sort {
  @Override
  protected int[] sort(int[] arr, SortType type) {
    int length = arr.length;

    int gap = 1;
    while (gap < length / 9) {
      gap = gap * 3 + 1;
    }

    while (gap > 0) {
      for (int i = gap; i < length; i++) {
        int j = i;
        while (j >= gap && super.compare(arr[j - gap], arr[j], type)) {
          super.swap(arr, j - gap, j);
          j--;
        }
      }
      gap = gap / 3;
    }

    return arr;
  }
}
