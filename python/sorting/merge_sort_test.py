from .merge_sort import MergeSort
from .perf_measurer import PerfMeasurer


def test_merge_sort():
    arr = [76, 34, 67, 32, 78, 45]
    sorter = MergeSort()
    sorter.sort(arr)
    expected_asc = [32, 34, 45, 67, 76, 78]
    assert arr == expected_asc

    perf_measurer = PerfMeasurer(sorter)
    print(perf_measurer.reportPerf())
