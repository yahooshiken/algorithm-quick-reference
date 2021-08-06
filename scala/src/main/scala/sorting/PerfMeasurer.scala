package sorting

import scala.util.Random

class PerfMeasurer(val sorter: Sort) {
  def reportPerf(): String = {

    val builder = new StringBuilder
    val sizes = Array(100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000)

    for (size <- sizes) {
      var arr: Array[Int] = Array.range(0, size)
      val shuffled = Random.shuffle(arr)

      val start = System.nanoTime()
      sorter.sort(arr)
      val end = System.nanoTime()
      val diff = (end - start).toDouble / 1000 / 1000 / 1000

      builder.append(
        f"Time to sort an array of size $size%5d is $diff%.8f sec\n"
      )
    }

    builder.result()
  }
}
