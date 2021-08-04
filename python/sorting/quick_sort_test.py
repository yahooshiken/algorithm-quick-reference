from .sort import SortType
from .quick_sort import QuickSort
from .perf_measurer import PerfMeasurer


def test_quick_sort():
    arr = [76, 34, 67, 32, 78, 45]
    sorter = QuickSort()
    sorter.sort(arr)
    expected_asc = [32, 34, 45, 67, 76, 78]
    assert arr == expected_asc

    sorter.sort(arr, SortType.desc)
    expected_desc = [78, 76, 67, 45, 34, 32]
    assert arr == expected_desc

    perfMeasurer = PerfMeasurer(sorter)
    print(perfMeasurer.reportPerf())
