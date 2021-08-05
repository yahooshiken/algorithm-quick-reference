package algorithm.sorting

public class BubbleSort : Sort() {
  override fun sort(arr: Array<Int>, type: SortType): Array<Int> {
    val length = arr.size

    for (i in 0..length - 1) {
      for (j in i + 1..length - 1) {
        if (compare(arr[i], arr[j], type)) {
          arr.swap(i, j)
        }
      }
    }

    return arr
  }
}
