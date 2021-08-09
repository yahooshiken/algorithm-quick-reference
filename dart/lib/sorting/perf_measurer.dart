import 'package:algorithm/sorting/sort.dart';

class PerfMeasurer {
  Sort sorter;

  PerfMeasurer(this.sorter);

  String reportPerf() {
    var str = '';

    const sizes = [100, 200, 500, 1000, 2000, 5000, 10000, 20000];

    for (final size in sizes) {
      final arr = List.generate(size, (i) => i);
      arr.shuffle();

      final stopwatch = Stopwatch();
      stopwatch.start();
      sorter.sort(arr);
      final time = stopwatch.elapsed;
      str += 'Time to sort an array of size $size is ${time.toString()} sec\n';
    }

    return str;
  }
}
