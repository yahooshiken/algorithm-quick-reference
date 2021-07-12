import random
import time

from .sort import Sort


class PerfMeasurer:
    def __init__(self, sorter: Sort) -> None:
        self.sorter = sorter

    def reportPerf(self) -> str:
        sizes = [100, 200, 500, 1000, 2000, 5000]

        report = ""

        for size in sizes:
            ls = list(range(size))
            random.seed(0)
            random.shuffle(ls)
            start = time.time()
            self.sorter.sort(ls)
            end = time.time()

            diff = end - start

            report += "Time to sort an array of size {:5d} is {:.10f} sec\n".format(
                size, diff
            )

        return report
