from .sort import SortType
from .bubble_sort import BubbleSort
from .perf_measurer import PerfMeasurer


def test_bubble_sort():
    arr = [76, 34, 67, 32, 78, 45]
    sorter = BubbleSort()
    sorter.sort(arr)
    expected_asc = [32, 34, 45, 67, 76, 78]
    assert arr == expected_asc

    sorter.sort(arr, SortType.desc)
    expected_desc = [78, 76, 67, 45, 34, 32]
    assert arr == expected_desc

    perfMeasurer = PerfMeasurer(sorter)
    print(perfMeasurer.reportPerf())
