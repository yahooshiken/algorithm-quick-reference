package algorithm.sorting

public class MergeSort : Sort() {
  var workArr: Array<Int?> = arrayOf()

  override fun sort(arr: Array<Int>, type: SortType): Array<Int> {
    val length = arr.size
    workArr = arrayOfNulls(length)

    return mergeSort(arr, 0, length - 1, type)
  }

  fun mergeSort(arr: Array<Int>, low: Int, high: Int, type: SortType): Array<Int> {
    if (low < high) {
      val middle = (low + high) / 2

      mergeSort(arr, low, middle, type)
      mergeSort(arr, middle + 1, high, type)

      for (i in low..middle) {
        workArr[i] = arr[i]
      }
      var j = high
      for (i in middle + 1..high) {
        workArr[i] = arr[j]
        j--
      }

      var i = low
      j = high

      for (k in low..high) {
        if (compare(workArr[j] as Int, workArr[i] as Int, type)) {
          arr[k] = workArr[i] as Int
          i++
        } else {
          arr[k] = workArr[j] as Int
          j--
        }
      }
    }

    return arr
  }
}
