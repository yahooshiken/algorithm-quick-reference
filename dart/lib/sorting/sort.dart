enum SortType { asc, desc }

extension ListSwap<T> on List<T> {
  void swap(int index1, int index2) {
    final length = this.length;

    RangeError.checkValidIndex(index1, this, 'index1', length);
    RangeError.checkValidIndex(index2, this, 'index2', length);

    final tmp = this[index1];
    this[index1] = this[index2];
    this[index2] = tmp;
  }
}

abstract class Sort {
  bool compare(int x, int y, SortType type) {
    return type == SortType.asc ? x > y : x < y;
  }

  List<int> sort(List<int> arr, {SortType type = SortType.asc});
}
