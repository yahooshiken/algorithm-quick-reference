package algorithm.sorting;

import java.time.Duration;
import java.time.Instant;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class PerfMeasurer {
  private Sort sorter;

  public PerfMeasurer(Sort sorter) {
    this.sorter = sorter;
  }

  String reportPerf() {
    StringBuilder builder = new StringBuilder();

    int[] sizes = { 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000 };

    for (int size : sizes) {
      List<Integer> l = IntStream.range(0, size).boxed().collect(Collectors.toList());
      Collections.shuffle(l);
      int[] arr = l.stream().mapToInt(i -> i).toArray();

      Instant start = Instant.now();
      sorter.sort(arr, SortType.asc);
      Instant end = Instant.now();
      Duration diff = Duration.between(start, end);

      builder.append("Time to sort an array of size " + size + " is " + diff + " sec\n");
    }

    return builder.toString();

  }
}
