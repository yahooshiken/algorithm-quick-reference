import 'package:algorithm/sorting/selection_sort.dart';
import 'package:algorithm/sorting/perf_measurer.dart';
import 'package:algorithm/sorting/sort.dart';
import 'package:test/test.dart';

void main() {
  final sorter = SelectionSort();

  test('Selection sort', () {
    final arr = [76, 34, 67, 32, 78, 45];

    final sortedAsc = sorter.sort(arr);
    const expectedAsc = [32, 34, 45, 67, 76, 78];
    expect(sortedAsc, expectedAsc);

    final sortedDesc = sorter.sort(arr, type: SortType.desc);
    const expectedDesc = [78, 76, 67, 45, 34, 32];
    expect(sortedDesc, expectedDesc);

    final perfMeasurer = PerfMeasurer(sorter);
    print(perfMeasurer.reportPerf());
  });
}
