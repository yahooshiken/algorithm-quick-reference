package algorithm.sorting

fun Array<Int>.swap(i: Int, j: Int) {
  val tmp = this[i]
  this[i] = this[j]
  this[j] = tmp
}

enum class SortType {
  asc,
  desc
}

public abstract class Sort {
  protected fun compare(x: Int, y: Int, type: SortType): Boolean {
    return if (type == SortType.asc) x > y else x < y
  }
  abstract fun sort(arr: Array<Int>, type: SortType = SortType.asc): Array<Int>
}
