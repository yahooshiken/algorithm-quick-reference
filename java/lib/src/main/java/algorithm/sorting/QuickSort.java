package algorithm.sorting;

public class QuickSort extends Sort {
  private int partition(int[] arr, int low, int high) {
    int pivot = arr[high];

    int i = low - 1, j = high;

    while (true) {
      while (arr[++i] < pivot)
        ;
      while (i < --j && arr[j] > pivot)
        ;

      if (j <= i) {
        break;
      }
      super.swap(arr, i, j);
    }

    super.swap(arr, i, high);
    return i;
  }

  private int[] quickSort(int[] arr, int low, int high) {
    if (low < high) {
      int pivot = partition(arr, low, high);
      quickSort(arr, low, pivot - 1);
      quickSort(arr, pivot + 1, high);
    }

    return arr;
  }

  @Override
  protected int[] sort(int[] arr, SortType type) {
    int length = arr.length;
    return quickSort(arr, 0, length - 1);
  }

}
