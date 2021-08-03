package algorithm.sorting;

public class QuickSort extends Sort {
  private int partition(int[] arr, int low, int high, SortType type) {
    int pivot = arr[high];

    int i = low - 1, j = high;

    while (true) {
      while (super.compare(pivot, arr[++i], type))
        ;

      while (i < --j && super.compare(arr[j], pivot, type))
        ;

      if (j <= i) {
        break;
      }
      super.swap(arr, i, j);
    }

    super.swap(arr, i, high);
    return i;
  }

  private int[] quickSort(int[] arr, int low, int high, SortType type) {
    if (low < high) {
      int pivot = partition(arr, low, high, type);
      quickSort(arr, low, pivot - 1, type);
      quickSort(arr, pivot + 1, high, type);
    }

    return arr;
  }

  @Override
  protected int[] sort(int[] arr, SortType type) {
    int length = arr.length;
    return quickSort(arr, 0, length - 1, type);
  }
}
