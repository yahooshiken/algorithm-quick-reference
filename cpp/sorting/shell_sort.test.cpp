#include <cassert>
#include <iostream>

#include "perf_measurer.hpp"
#include "shell_sort.hpp"

using namespace std;

int main() {
  int arr[] = {76, 34, 67, 32, 78, 45};
  const int length = sizeof(arr) / sizeof(*arr);
  ShellSort<int> *shellSort = new ShellSort<int>();

  cout << "Before: " << shellSort->toString(arr, length) << endl;
  shellSort->sort(arr, length);
  cout << "After: " << shellSort->toString(arr, length) << endl;

  int expected[] = {32, 34, 45, 67, 76, 78};
  for (int i = 0; i < length; i++) {
    assert(arr[i] == expected[i]);
  }

  PerfMeasurer<int> *perfMeasurer =
      new PerfMeasurer<int>((const Sort<int> &)ShellSort<int>());

  cout << perfMeasurer->reportPerf() << endl;

  cout << "Test passed" << endl;

  return 0;
}
