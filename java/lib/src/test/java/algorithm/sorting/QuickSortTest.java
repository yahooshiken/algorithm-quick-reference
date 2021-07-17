package algorithm.sorting;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

import org.junit.jupiter.api.Test;

public class QuickSortTest {
  @Test
  void test_quick_sort() {
    int[] arr = { 76, 34, 67, 32, 78, 45 };
    QuickSort sorter = new QuickSort();

    int[] sorted_asc = sorter.sort(arr, SortType.asc);
    int[] expected_asc = { 32, 34, 45, 67, 76, 78 };

    assertArrayEquals(expected_asc, sorted_asc);

    PerfMeasurer perfMeasurer = new PerfMeasurer(sorter);
    System.out.println(perfMeasurer.reportPerf());
  }

}
