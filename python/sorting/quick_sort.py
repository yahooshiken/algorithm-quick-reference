from .sort import Sort, SortType


class QuickSort(Sort):
    def sort(self, arr: list[int], type: SortType = SortType.asc) -> list[int]:
        length = len(arr)
        return self.quick_sort(arr, 0, length - 1, type)

    def quick_sort(
        self, arr: list[int], low: int, high: int, type: SortType
    ) -> list[int]:
        if low < high:
            pivot = self.partition(arr, low, high, type)
            self.quick_sort(arr, low, pivot - 1, type)
            self.quick_sort(arr, pivot + 1, high, type)

        return arr

    def partition(self, arr: list[int], low: int, high: int, type: SortType) -> int:
        pivot = arr[high]

        i = low - 1
        j = high

        while True:
            i += 1
            while self.compare(pivot, arr[i], type):
                i += 1

            j -= 1
            while i < j and self.compare(arr[j], pivot, type):
                j -= 1

            if j <= i:
                break

            arr[i], arr[j] = arr[j], arr[i]

        arr[i], arr[high] = arr[high], arr[i]

        return i
