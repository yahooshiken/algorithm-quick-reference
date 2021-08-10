import 'package:algorithm/sorting/sort.dart';

class MergeSort extends Sort {
  List<int> workArr;

  @override
  List<int> sort(List<int> arr, {SortType type = SortType.asc}) {
    final length = arr.length;
    workArr = []..length = length;
    return mergeSort(arr, 0, length - 1, type);
  }

  List<int> mergeSort(List<int> arr, int low, int high, SortType type) {
    if (low >= high) return arr;

    final middle = (low + high) ~/ 2;

    mergeSort(arr, low, middle, type);
    mergeSort(arr, middle + 1, high, type);

    for (var i = low; i <= middle; i++) {
      workArr[i] = arr[i];
    }

    for (var i = middle + 1, j = high; i <= high; i++, j--) {
      workArr[i] = arr[j];
    }

    var i = low, j = high;
    for (var k = low; k <= high; k++) {
      if (compare(workArr[j], workArr[i], type)) {
        arr[k] = workArr[i++];
      } else {
        arr[k] = workArr[j--];
      }
    }

    return arr;
  }
}
