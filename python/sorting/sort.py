from enum import Enum


class SortType(Enum):
    asc = "asc"
    desc = "desc"


class Sort:
    def compare(self, x, y, type):
        return x > y if type == SortType.asc else x < y

    def sort(arr):
        pass
