package algorithm.sorting;

import static org.junit.jupiter.api.Assertions.assertEquals;

import java.util.Arrays;
import java.util.List;

import org.junit.jupiter.api.Test;

public class BubbleSortTest {
  @Test
  void test_bubble_sort() {
    List<Integer> arr = Arrays.asList(76, 34, 67, 32, 78, 45);
    BubbleSort sorter = new BubbleSort();

    List<Integer> sorted_asc = sorter.sort(arr, SortType.asc);
    List<Integer> expected_asc = Arrays.asList(32, 34, 45, 67, 76, 78);
    assertEquals(expected_asc, sorted_asc);

    List<Integer> sorted_desc = sorter.sort(arr, SortType.desc);
    List<Integer> expected_desc = Arrays.asList(78, 76, 67, 45, 34, 32);
    assertEquals(expected_desc, sorted_desc);
  }
}
