package sorting

class SelectionSort() extends Sort {
  def sort(arr: Array[Int], sortType: SortType): Array[Int] = {
    val length: Int = arr.length

    for (i <- Range(0, length - 1, 1)) {
      var minIndex = i
      for (j <- Range(i + 1, length, 1))
        if (compare(arr(minIndex), arr(j), sortType)) {
          minIndex = j
        }
      swap(arr, i, minIndex)
    }
    arr
  }
}
