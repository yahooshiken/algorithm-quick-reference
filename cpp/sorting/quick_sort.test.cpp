#include <cassert>
#include <iostream>

#include "perf_measurer.hpp"
#include "quick_sort.hpp"

using namespace std;

int main() {
  int arr[] = {76, 34, 67, 32, 78, 45};
  const int length = sizeof(arr) / sizeof(*arr);
  QuickSort<int> *quickSort = new QuickSort<int>();

  quickSort->sort(arr, length);
  int expectedAsc[] = {32, 34, 45, 67, 76, 78};
  for (int i = 0; i < length; i++) {
    assert(arr[i] == expectedAsc[i]);
  }

  quickSort->sort(arr, length, desc);
  int expectedDesc[] = {78, 76, 67, 45, 34, 32};
  for (int i = 0; i < length; i++) {
    assert(arr[i] == expectedDesc[i]);
  }

  PerfMeasurer<int> *perfMeasurer =
      new PerfMeasurer<int>((const Sort<int> &)QuickSort<int>());

  cout << perfMeasurer->reportPerf() << endl;

  cout << "Test passed" << endl;

  return 0;
}
