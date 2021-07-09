#include <cassert>
#include <iostream>

#include "bubble_sort.hpp"

using namespace std;

int main() {
  int arr[] = {76, 34, 67, 32, 78, 45};
  const int length = sizeof(arr) / sizeof(*arr);
  BubbleSort<int> *bubbleSort = new BubbleSort<int>();

  cout << "Before: " << bubbleSort->toString(arr, length) << endl;
  bubbleSort->sort(arr, length);
  cout << "After: " << bubbleSort->toString(arr, length) << endl;

  return 0;
}
