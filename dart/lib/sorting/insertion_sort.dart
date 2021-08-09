import 'package:algorithm/sorting/sort.dart';

class InsertionSort extends Sort {
  @override
  List<int> sort(List<int> arr, {SortType type = SortType.asc}) {
    final length = arr.length;

    for (var i = 1; i < length; i++) {
      var j = i;
      while (j >= 1 && compare(arr[j - 1], arr[j], type)) {
        arr.swap(j - 1, j);
        j--;
      }
    }

    return arr;
  }
}
