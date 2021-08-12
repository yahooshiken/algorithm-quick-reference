package algorithm.sorting

public class ShellSort : Sort() {
  override fun sort(arr: Array<Int>, type: SortType): Array<Int> {
    val length = arr.size

    var gap = 1
    while (gap < length / 9) {
      gap = gap * 3 + 1
    }

    while (gap > 0) {
      for (i in gap..length - 1) {
        var j = i
        while (j >= gap && compare(arr[j - gap], arr[j], type)) {
          arr.swap(j - gap, j)
          j--
        }
      }
      gap = gap / 3
    }
    return arr
  }
}
