from .sort import SortType, Sort


class ShellSort(Sort):
    def sort(self, arr: list[int], type=SortType.asc):
        length: int = len(arr)

        gap: int = 1
        while gap < length / 9:
            gap = gap * 3 + 1

        while gap > 0:
            for i in range(gap, length):
                j: int = i
                while j >= gap and super().compare(arr[j - gap], arr[j], type):
                    arr[j - gap], arr[j] = arr[j], arr[j - gap]
                    j -= 1

            gap = int(gap / 3)

        return arr
