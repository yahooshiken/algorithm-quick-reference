package algorithm.sorting

public class QuickSort : Sort() {
  override fun sort(arr: Array<Int>, type: SortType): Array<Int> {
    val length = arr.size
    return quickSort(arr, 0, length - 1, type)
  }

  fun partition(arr: Array<Int>, low: Int, high: Int, type: SortType): Int {
    val pivot = arr[high]
    var i = low - 1
    var j = high
    while (true) {
      while (compare(pivot, arr[++i], type)) ;
      while (i < --j && compare(arr[j], pivot, type)) ;
      if (i >= j) break
      arr.swap(i, j)
    }
    arr.swap(i, high)
    return i
  }

  fun quickSort(arr: Array<Int>, low: Int, high: Int, type: SortType): Array<Int> {
    if (low < high) {
      val pivot = partition(arr, low, high, type)
      quickSort(arr, low, pivot - 1, type)
      quickSort(arr, pivot + 1, high, type)
    }

    return arr
  }
}
