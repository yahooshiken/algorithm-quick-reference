#include "sort.hpp"
#include <iostream>

using namespace std;

template <typename T> class SelectionSort : public Sort<T> {

public:
  SelectionSort(){};
  ~SelectionSort(){};

  T *sort(T *arr, const int length, SortType type = asc);
  string toString(T *arr, const int length);
};

template <typename T>
T *SelectionSort<T>::sort(T *arr, const int length, SortType type) {
  for (int i = 0; i < length - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < length; j++) {
      if (Sort<T>::compare(&arr[minIndex], &arr[j], type)) {
        minIndex = j;
      }
    }
    Sort<T>::swap(&arr[minIndex], &arr[i]);
  }

  return arr;
}

template <typename T>
string SelectionSort<T>::toString(T *arr, const int length) {
  return Sort<T>::toString(arr, length);
};