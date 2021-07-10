#include <cassert>
#include <iostream>

#include "merge_sort.hpp"
#include "perf_measurer.hpp"

using namespace std;

int main() {
  int arr[] = {76, 34, 67, 32, 78, 45};
  const int length = sizeof(arr) / sizeof(*arr);
  MergeSort<int> *mergeSort = new MergeSort<int>();

  cout << "Before: " << mergeSort->toString(arr, length) << endl;
  mergeSort->sort(arr, length);
  cout << "After: " << mergeSort->toString(arr, length) << endl << endl;

  int expected[] = {32, 34, 45, 67, 76, 78};
  for (int i = 0; i < length; i++) {
    assert(arr[i] == expected[i]);
  }

  PerfMeasurer<int> *perfMeasurer =
      new PerfMeasurer<int>((const Sort<int> &)MergeSort<int>());

  cout << perfMeasurer->reportPerf() << endl;

  cout << "Test passed" << endl;

  return 0;
}
