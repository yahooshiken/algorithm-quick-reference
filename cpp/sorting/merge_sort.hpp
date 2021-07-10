#include <array>
#include <iostream>
#include <sstream>
#include <string>

#include "sort.hpp"

using namespace std;

template <typename T> class MergeSort : public Sort<T> {
private:
  mutable T *workArr;
  const T *mergeSort(T *arr, const int low, const int high) const;
  const void newWorkArr(int length) const { workArr = new T[length]; };
  const void freeWorkArr() const { delete[] workArr; };

public:
  MergeSort(){};
  ~MergeSort(){};

  const T *sort(T *arr, const int length, SortType type = asc) const;
  const string toString(T *arr, const int length) const;
};

template <typename T>
const T *MergeSort<T>::mergeSort(T *arr, const int low, const int high) const {
  if (low >= high) {
    return arr;
  }

  int middle = (low + high) / 2;

  mergeSort(arr, low, middle);
  mergeSort(arr, middle + 1, high);

  for (int i = low; i <= middle; i++) {
    workArr[i] = arr[i];
  }

  for (int i = middle + 1, j = high; i <= high; i++, j--) {
    workArr[i] = arr[j];
  }

  int i = low, j = high;
  for (int k = low; k <= high; k++) {
    if (workArr[i] <= workArr[j]) {
      arr[k] = workArr[i++];
    } else {
      arr[k] = workArr[j--];
    }
  }

  return arr;
}

template <typename T>
const T *MergeSort<T>::sort(T *arr, const int length, SortType type) const {
  newWorkArr(length);
  mergeSort(arr, 0, length - 1);
  freeWorkArr();

  return arr;
}

template <typename T>
const string MergeSort<T>::toString(T *arr, const int length) const {
  return Sort<T>::toString(arr, length);
}
