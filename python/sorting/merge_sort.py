from .sort import Sort
import sys


class MergeSort(Sort):
    def __init__(self):
        # sys.setrecursionlimit(10000)
        self.work_arr = []

    def sort(self, arr: list[int]) -> list[int]:
        length = len(arr)
        self.work_arr = [None] * length
        return self.merge_sort(arr, 0, length - 1)

    def merge_sort(self, arr: list[int], low: int, high: int) -> list[int]:
        if low >= high:
            return arr

        middle: int = int((low + high) / 2)

        self.merge_sort(arr, low, middle)
        self.merge_sort(arr, middle + 1, high)

        for i in range(low, middle + 1):
            self.work_arr[i] = arr[i]

        j: int = high
        for i in range(middle + 1, high + 1):
            self.work_arr[i] = arr[j]
            j -= 1

        i = low
        j = high

        for k in range(low, high + 1):
            if self.work_arr[i] <= self.work_arr[j]:
                arr[k] = self.work_arr[i]
                i += 1
            else:
                arr[k] = self.work_arr[j]
                j -= 1

        return arr
