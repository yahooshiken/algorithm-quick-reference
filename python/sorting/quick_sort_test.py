from .quick_sort import QuickSort
from .perf_measurer import PerfMeasurer


def test_quick_sort():
    arr = [76, 34, 67, 32, 78, 45]
    sorter = QuickSort()
    sorter.sort(arr)
    expected_asc = [32, 34, 45, 67, 76, 78]
    assert arr == expected_asc

    perfMeasurer = PerfMeasurer(sorter)
    print(perfMeasurer.reportPerf())
