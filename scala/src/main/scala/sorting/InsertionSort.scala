package sorting

class InsertionSort() extends Sort {
  def sort(arr: Array[Int], sortType: SortType): Array[Int] = {
    val length: Int = arr.length

    for (i <- Range(1, length, 1)) {
      var j = i
      while (j >= 1 && compare(arr(j - 1), arr(j), sortType)) {
        swap(arr, j, j - 1)
        j -= 1
      }
    }
    arr
  }
}
