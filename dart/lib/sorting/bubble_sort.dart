import 'package:algorithm/sorting/sort.dart';

class BubbleSort extends Sort {
  @override
  List<int> sort(List<int> arr, {SortType type = SortType.asc}) {
    final length = arr.length;

    for (var i = 0; i < length; i++) {
      for (var j = 0; j < length - i - 1; j++) {
        if (compare(arr[j], arr[j + 1], type)) {
          arr.swap(j, j + 1);
        }
      }
    }

    return arr;
  }
}
