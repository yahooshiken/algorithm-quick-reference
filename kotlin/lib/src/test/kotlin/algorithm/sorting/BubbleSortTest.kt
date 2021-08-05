package algorithm.sorting

import kotlin.test.Test
import kotlin.test.assertEquals

class BubbleSortTest {
  @Test
  fun test() {
    val arr = arrayOf(76, 34, 67, 32, 78, 45)
    val sorter = BubbleSort()

    val expected_asc = arrayOf(32, 34, 45, 67, 76, 78)
    val sorted_asc = sorter.sort(arr)
    assertEquals(expected_asc.toList(), sorted_asc.toList())

    val expected_desc = arrayOf(78, 76, 67, 45, 34, 32)
    val sorted_desc = sorter.sort(arr, SortType.desc)
    assertEquals(expected_desc.toList(), sorted_desc.toList())
  }
}
