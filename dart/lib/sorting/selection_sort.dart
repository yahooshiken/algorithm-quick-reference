import 'package:algorithm/sorting/sort.dart';

class SelectionSort extends Sort {
  @override
  List<int> sort(List<int> arr, {SortType type = SortType.asc}) {
    final length = arr.length;

    for (var i = 0; i < length - 1; i++) {
      var minIndex = i;
      for (var j = i + 1; j < length; j++) {
        if (compare(arr[minIndex], arr[j], type)) {
          minIndex = j;
        }
      }
      arr.swap(minIndex, i);
    }
    return arr;
  }
}
