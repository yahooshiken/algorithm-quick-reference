package algorithm.sorting;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

import org.junit.jupiter.api.Test;

public class MergeSortTest {
  @Test
  void test_merge_sort() {
    int[] arr = { 76, 34, 67, 32, 78, 45 };
    MergeSort sorter = new MergeSort();

    int[] sorted_asc = sorter.sort(arr, SortType.asc);
    int[] expected_asc = { 32, 34, 45, 67, 76, 78 };

    assertArrayEquals(expected_asc, sorted_asc);

    PerfMeasurer perfMeasurer = new PerfMeasurer(sorter);
    System.out.println(perfMeasurer.reportPerf());
  }

}