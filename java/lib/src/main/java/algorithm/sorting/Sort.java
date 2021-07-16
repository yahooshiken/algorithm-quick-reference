package algorithm.sorting;

public abstract class Sort {
  public boolean compare(int x, int y, SortType type) {
    return type == SortType.asc ? x > y : x < y;
  }

  public void swap(int[] arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
  }

  protected abstract int[] sort(int[] arr, SortType type);

}
