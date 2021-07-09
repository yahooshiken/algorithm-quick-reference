#include "sort.hpp"

template <typename T> class InsertionSort : public Sort<T> {

public:
  InsertionSort(){};
  ~InsertionSort(){};

  T *sort(T *arr, const int length, SortType type = asc);
  string toString(T *arr, const int length);
};

template <typename T>
T *InsertionSort<T>::sort(T *arr, const int length, SortType type) {
  for (int i = 1; i < length; i++) {
    int j = i;
    while (j >= 1 && Sort<T>::compare(&arr[j - 1], &arr[j], type)) {
      Sort<T>::swap(&arr[j], &arr[j - 1]);
      j--;
    }
  }

  return arr;
}

template <typename T>
string InsertionSort<T>::toString(T *arr, const int length) {
  return Sort<T>::toString(arr, length);
};