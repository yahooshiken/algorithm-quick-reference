from .sort import Sort, SortType


class MergeSort(Sort):
    def __init__(self):
        self.work_arr = []

    def sort(self, arr: list[int], type: SortType = SortType.asc) -> list[int]:
        length = len(arr)
        self.work_arr = [None] * length
        return self.merge_sort(arr, 0, length - 1, type)

    def merge_sort(
        self, arr: list[int], low: int, high: int, type: SortType
    ) -> list[int]:
        if low >= high:
            return arr

        middle: int = int((low + high) / 2)

        self.merge_sort(arr, low, middle, type)
        self.merge_sort(arr, middle + 1, high, type)

        for i in range(low, middle + 1):
            self.work_arr[i] = arr[i]

        j: int = high
        for i in range(middle + 1, high + 1):
            self.work_arr[i] = arr[j]
            j -= 1

        i = low
        j = high

        for k in range(low, high + 1):
            if self.compare(self.work_arr[j], self.work_arr[i], type):
                arr[k] = self.work_arr[i]
                i += 1
            else:
                arr[k] = self.work_arr[j]
                j -= 1

        return arr
