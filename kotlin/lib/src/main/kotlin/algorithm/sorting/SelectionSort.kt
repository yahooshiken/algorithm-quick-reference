package algorithm.sorting

public class SelectionSort : Sort() {
  override fun sort(arr: Array<Int>, type: SortType): Array<Int> {
    val length = arr.size

    for (i in 0..length - 1) {
      var minIndex = i

      for (j in i + 1..length - 1) {
        if (compare(arr[minIndex], arr[j], type)) {
          minIndex = j
        }
      }
      arr.swap(minIndex, i)
    }
    return arr
  }
}
