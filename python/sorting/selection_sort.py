from .sort import SortType, Sort


class SelectionSort(Sort):
    def sort(self, arr: list[int], type=SortType.asc):
        length: int = len(arr)

        for i in range(length - 1):
            min_index = i
            for j in range(i + 1, length):
                if super().compare(arr[min_index], arr[j], type):
                    min_index = j

            arr[i], arr[min_index] = arr[min_index], arr[i]

        return arr
