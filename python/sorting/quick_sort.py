from .sort import Sort


class QuickSort(Sort):
    def sort(self, arr: list[int]) -> list[int]:
        length = len(arr)
        return self.quick_sort(arr, 0, length - 1)

    def quick_sort(self, arr: list[int], low: int, high: int) -> list[int]:
        if low < high:
            pivot = self.partition(arr, low, high)
            self.quick_sort(arr, low, pivot - 1)
            self.quick_sort(arr, pivot + 1, high)

        return arr

    def partition(self, arr: list[int], low: int, high: int) -> int:
        pivot = arr[high]

        i = low - 1
        j = high

        while True:
            i += 1
            while arr[i] < pivot:
                i += 1

            j -= 1
            while i < j and arr[j] > pivot:
                j -= 1

            if j <= i:
                break

            arr[i], arr[j] = arr[j], arr[i]

        arr[i], arr[high] = arr[high], arr[i]

        return i
