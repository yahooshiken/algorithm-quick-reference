package algorithm.sorting

public class InsertionSort : Sort() {
  override fun sort(arr: Array<Int>, type: SortType): Array<Int> {
    val length = arr.size

    for (i in 1..length - 1) {
      var j = i
      while (j >= 1 && compare(arr[j - 1], arr[j], type)) {
        arr.swap(j - 1, j)
        j--
      }
    }

    return arr
  }
}
