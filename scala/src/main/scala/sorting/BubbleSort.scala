package sorting

class BubbleSort() extends Sort {
  def sort(arr: Array[Int], sortType: SortType): Array[Int] = {
    val length: Int = arr.length

    for (i <- Range(0, length, 1))
      for (j <- Range(0, length - i - 1, 1))
        if (compare(arr(j), arr(j + 1), sortType)) {
          swap(arr, j, j + 1)
        }
    arr
  }

}
