import 'package:algorithm/sorting/sort.dart';

class QuickSort extends Sort {
  @override
  List<int> sort(List<int> arr, {SortType type = SortType.asc}) {
    final length = arr.length;

    return quickSort(arr, 0, length - 1, type);
  }

  int partition(List<int> arr, int low, int high, SortType type) {
    final pivot = arr[high];

    var i = low - 1;
    var j = high;

    while (true) {
      while (compare(pivot, arr[++i], type)) {}
      while (i < --j && compare(arr[j], pivot, type)) {}
      if (j <= i) break;

      arr.swap(i, j);
    }

    arr.swap(i, high);
    return i;
  }

  List<int> quickSort(List<int> arr, int low, int high, SortType type) {
    if (low < high) {
      final pivot = partition(arr, low, high, type);
      quickSort(arr, low, pivot - 1, type);
      quickSort(arr, pivot + 1, high, type);
    }
    return arr;
  }
}
