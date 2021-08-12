package sorting

class InsertionSortTest extends org.scalatest.funsuite.AnyFunSuite {
  test("Insertion sort") {

    val arr: Array[Int] = Array(76, 34, 67, 32, 78, 45)
    val sorter = new InsertionSort();

    val sortedAsc: Array[Int] = sorter.sort(arr)
    val expectedAsc: Array[Int] = Array(32, 34, 45, 67, 76, 78)
    assert(sortedAsc.sameElements(expectedAsc))

    val sortedDesc: Array[Int] = sorter.sort(arr, Desc)
    val expectedDesc: Array[Int] = Array(78, 76, 67, 45, 34, 32)
    assert(sortedDesc.sameElements(expectedDesc))

    val perfMeasurer = new PerfMeasurer(sorter)
    Console.println(perfMeasurer.reportPerf())

  }
}
