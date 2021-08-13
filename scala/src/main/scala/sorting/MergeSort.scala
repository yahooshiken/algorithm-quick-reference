package sorting

import scala.util.control.Breaks

class MergeSort() extends Sort {
  private var workArr = Array[Int]()

  def sort(arr: Array[Int], sortType: SortType): Array[Int] = {
    val length: Int = arr.length
    workArr = new Array[Int](length)
    mergeSort(arr, 0, length - 1, sortType)
  }

  def mergeSort(
      arr: Array[Int],
      low: Int,
      high: Int,
      sortType: SortType
  ): Array[Int] = {
    if (low < high) {

      val middle = (low + high) / 2
      mergeSort(arr, low, middle, sortType)
      mergeSort(arr, middle + 1, high, sortType)

      for (i <- Range(low, middle + 1, 1))
        workArr(i) = arr(i)

      var j = high
      for (i <- Range(middle + 1, high + 1, 1)) {
        workArr(i) = arr(j)
        j -= 1
      }

      var i = low
      j = high
      for (k <- Range(low, high + 1, 1)) {
        if (compare(workArr(j), workArr(i), sortType)) {
          arr(k) = workArr(i)
          i += 1
        } else {
          arr(k) = workArr(j)
          j -= 1
        }
      }
    }
    arr
  }
}
