package algorithm.sorting;

import java.util.List;

public abstract class Sort {
  public boolean compare(int x, int y, SortType type) {
    return type == SortType.asc ? x > y : x < y;
  }

  protected abstract List<Integer> sort(List<Integer> arr, SortType type);

}
