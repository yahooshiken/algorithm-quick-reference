from .sort import SortType, Sort


class InsertionSort(Sort):
    def sort(self, arr: list[int], type: SortType = SortType.asc):
        length = len(arr)

        for i in range(1, length):
            j = i
            while j >= 1 and super().compare(arr[j - 1], arr[j], type):
                arr[j - 1], arr[j] = arr[j], arr[j - 1]
                j += -1

        return arr
