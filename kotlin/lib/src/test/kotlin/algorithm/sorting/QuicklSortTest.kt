package algorithm.sorting

import kotlin.test.Test
import kotlin.test.assertEquals

class QuickSortTest {
  @Test
  fun test() {
    val arr = arrayOf(76, 34, 67, 32, 78, 45)
    val sorter = QuickSort()

    val expectedAsc = arrayOf(32, 34, 45, 67, 76, 78)
    val sortedAsc = sorter.sort(arr)
    assertEquals(expectedAsc.toList(), sortedAsc.toList())

    val expectedDesc = arrayOf(78, 76, 67, 45, 34, 32)
    val sortedDesc = sorter.sort(arr, SortType.desc)
    assertEquals(expectedDesc.toList(), sortedDesc.toList())

    val perfMeasurer = PerfMeasurer(sorter)
    println(perfMeasurer.reportPerf())
  }
}
