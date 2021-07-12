from .sort import SortType
from .selection_sort import SelectionSort
from .perf_measurer import PerfMeasurer


def test_selection_sort():
    arr = [76, 34, 67, 32, 78, 45]
    sorter = SelectionSort()
    sorter.sort(arr)
    expected_asc = [32, 34, 45, 67, 76, 78]
    assert arr == expected_asc

    sorter.sort(arr, SortType.desc)
    expected_desc = [78, 76, 67, 45, 34, 32]
    assert arr == expected_desc

    perfMeasurer = PerfMeasurer(sorter)
    print(perfMeasurer.reportPerf())
