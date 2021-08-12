package sorting

import scala.util.control.Breaks

class QuickSort() extends Sort {
  def sort(arr: Array[Int], sortType: SortType): Array[Int] = {
    val length: Int = arr.length
    quickSort(arr, 0, length - 1, sortType)
  }

  def quickSort(
      arr: Array[Int],
      low: Int,
      high: Int,
      sortType: SortType
  ): Array[Int] = {
    if (low < high) {
      val pivot = partition(arr, low, high, sortType)
      quickSort(arr, low, pivot - 1, sortType)
      quickSort(arr, pivot + 1, high, sortType)
    }
    arr
  }

  def partition(
      arr: Array[Int],
      low: Int,
      high: Int,
      sortType: SortType
  ): Int = {
    val pivot = arr(high)
    var i = low - 1
    var j = high

    val break = new Breaks

    break.breakable {
      while (true) {
        i += 1
        while (compare(pivot, arr(i), sortType)) i += 1

        j -= 1
        while (i < j && compare(arr(j), pivot, sortType)) j -= 1
        if (i >= j) break.break
        swap(arr, i, j)
      }
    }
    swap(arr, i, high)
    i
  }
}
