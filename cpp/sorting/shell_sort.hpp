#include <iostream>

#include "sort.hpp"

using namespace std;

template <typename T> class ShellSort : public Sort<T> {

public:
  ShellSort(){};
  ~ShellSort(){};

  const T *sort(T *arr, const int length, SortType type = asc) const;
  const string toString(T *arr, const int length) const;
};

template <typename T>
const T *ShellSort<T>::sort(T *arr, const int length, SortType type) const {

  int gap;
  for (gap = 1; gap < length / 9; gap = gap * 3 + 1) {
  }

  for (; gap > 0; gap /= 3) {
    for (int i = gap; i < length; i++) {
      int j = i;
      while (j >= gap && Sort<T>::compare(&arr[j - gap], &arr[j], type)) {
        Sort<T>::swap(&arr[j - gap], &arr[j]);
        j--;
      }
    }
  }

  return arr;
}

template <typename T>
const string ShellSort<T>::toString(T *arr, const int length) const {
  return Sort<T>::toString(arr, length);
};