from .sort import SortType, Sort


class BubbleSort(Sort):
    def sort(self, arr, type=SortType.asc):
        length = len(arr)

        for i in range(length):
            for j in range(length - i - 1):
                if self.compare(arr[j], arr[j + 1], type):
                    arr[j], arr[j + 1] = arr[j + 1], arr[j]

        return arr
