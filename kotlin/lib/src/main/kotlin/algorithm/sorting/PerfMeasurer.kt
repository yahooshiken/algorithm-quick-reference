package algorithm.sorting

import kotlin.system.measureNanoTime

public class PerfMeasurer(_sorter: Sort) {
  val sorter: Sort

  init {
    sorter = _sorter
  }

  fun reportPerf(): String {
    var s = ""

    val sizes = arrayOf(100, 200, 500, 1000, 2000, 5000, 10000, 20000)

    for (size in sizes) {
      val arr = Array(size) { i -> i }
      arr.shuffle()

      val nanoTime = measureNanoTime { sorter.sort(arr) }
      val time = nanoTime.toDouble() / 1000 / 1000 / 1000

      s += "Time to sort an array of size %5d is %.9f sec\n".format(size, time)
    }

    return s
  }
}
