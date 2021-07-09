#include <iostream>

#include "insertion_sort.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
  int arr[] = {76, 34, 67, 32, 78, 45};
  const int length = sizeof(arr) / sizeof(*arr);
  InsertionSort<int> *insertionSort = new InsertionSort<int>();

  cout << "Before: " << insertionSort->toString(arr, length) << endl;
  insertionSort->sort(arr, length);
  cout << "After: " << insertionSort->toString(arr, length) << endl;

  int expected[] = {32, 34, 45, 67, 76, 78};
  for (int i = 0; i < length; i++) {
    assert(arr[i] == expected[i]);
  }

  cout << "Test passed" << endl;

  return 0;
}
