#include "sort.hpp"

template <typename T> class InsertionSort : public Sort<T> {

public:
  InsertionSort(){};
  ~InsertionSort(){};

  const T *sort(T *arr, const int length, SortType type = asc) const;
  const string toString(T *arr, const int length) const;
};

template <typename T>
const T *InsertionSort<T>::sort(T *arr, const int length, SortType type) const {
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
const string InsertionSort<T>::toString(T *arr, const int length) const {
  return Sort<T>::toString(arr, length);
};