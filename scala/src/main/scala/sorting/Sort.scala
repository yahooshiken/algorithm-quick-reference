package sorting;

sealed trait SortType
case object Asc extends SortType
case object Desc extends SortType

abstract class Sort() {
  def sort(arr: Array[Int], sortType: SortType = Asc): Array[Int]

  def swap(arr: Array[Int], index1: Int, index2: Int): Unit = {
    val tmp = arr(index1)
    arr(index1) = arr(index2)
    arr(index2) = tmp
  }

  def compare(x: Int, y: Int, sortType: SortType) = {
    sortType match {
      case Asc  => x > y
      case Desc => x < y
    }
  }
}
