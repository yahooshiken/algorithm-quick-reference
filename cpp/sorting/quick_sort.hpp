#include <iostream>

#include "sort.hpp"

using namespace std;

template <typename T> class QuickSort : public Sort<T> {
private:
  const int partition(T *arr, int low, int high, SortType type) const;
  const T *quick_sort(T *arr, int low, int high, SortType type) const;

public:
  QuickSort(){};
  ~QuickSort(){};

  const T *sort(T *arr, const int length, SortType type = asc) const;
  const string toString(T *arr, const int length) const;
};

template <typename T>
const T *QuickSort<T>::sort(T *arr, const int length, SortType type) const {
  quick_sort(arr, 0, length - 1, type);
  return arr;
}

template <typename T>
const string QuickSort<T>::toString(T *arr, const int length) const {
  return Sort<T>::toString(arr, length);
};

template <typename T>
const int QuickSort<T>::partition(T *arr, int low, int high,
                                  SortType type) const {
  int pivot = arr[high];

  int i = low - 1, j = high;

  while (true) {
    while (Sort<T>::compare(&pivot, &arr[++i], type))
      ;
    while (i < --j && Sort<T>::compare(&arr[j], &pivot, type))
      ;

    if (j <= i) {
      break;
    }
    Sort<T>::swap(&arr[i], &arr[j]);
  }

  Sort<T>::swap(&arr[i], &arr[high]);
  return i;
}

template <typename T>
const T *QuickSort<T>::quick_sort(T *arr, int low, int high,
                                  SortType type) const {
  if (low < high) {
    int pivot = partition(arr, low, high, type);

    quick_sort(arr, low, pivot - 1, type);
    quick_sort(arr, pivot + 1, high, type);
  }

  return arr;
}