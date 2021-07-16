package algorithm.sorting;

import java.util.Collections;
import java.util.List;

/**
 * BubbleSort
 */
public class BubbleSort extends Sort {
  @Override
  protected List<Integer> sort(List<Integer> arr, SortType type) {
    int length = arr.size();

    for (int i = 0; i < length; i++) {
      for (int j = 0; j < length - i - 1; j++) {
        if (super.compare(arr.get(j), arr.get(j + 1), type)) {
          Collections.swap(arr, j, j + 1);
        }
      }
    }

    return arr;
  }
}