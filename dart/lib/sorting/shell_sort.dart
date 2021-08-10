import 'package:algorithm/sorting/sort.dart';

class ShellSort extends Sort {
  @override
  List<int> sort(List<int> arr, {SortType type = SortType.asc}) {
    final length = arr.length;

    var gap = 1;
    while (gap < length / 9) {
      gap = gap * 3 + 1;
    }

    while (gap > 0) {
      for (var i = gap; i < length; i++) {
        var j = i;
        while (j >= gap && compare(arr[j - gap], arr[j], type)) {
          arr.swap(j - gap, j);
          j--;
        }
      }

      gap = gap ~/ 3;
    }

    return arr;
  }
}
