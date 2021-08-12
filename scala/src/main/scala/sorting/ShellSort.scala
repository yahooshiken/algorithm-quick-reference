package sorting

class ShellSort() extends Sort {
  def sort(arr: Array[Int], sortType: SortType): Array[Int] = {
    val length: Int = arr.length

    var gap = 1
    while (gap < length / 9) {
      gap = gap * 3 + 1
    }
    while (gap > 0) {
      for (i <- Range(gap, length, 1)) {
        var j = i
        while (j >= 1 && compare(arr(j - gap), arr(j), sortType)) {
          swap(arr, j, j - gap)
          j -= 1
        }
      }
      gap = gap / 3
    }
    arr
  }
}
