#include <sstream>
#include <string>

#include "sort.hpp"

using namespace std;

template <typename T> class BubbleSort : public Sort<T> {
public:
  BubbleSort(){};
  ~BubbleSort(){};

  const T *sort(T *arr, const int length, SortType type = asc) const;
  const string toString(T *arr, const int length) const;
};

template <typename T>
const T *BubbleSort<T>::sort(T *arr, const int length, SortType type) const {
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length - i - 1; j++) {
      if (Sort<T>::compare(&arr[j], &arr[j + 1])) {
        Sort<T>::swap(&arr[j], &arr[j + 1]);
      }
    }
  }

  return arr;
}

template <typename T>
const string BubbleSort<T>::toString(T *arr, const int length) const {
  return Sort<T>::toString(arr, length);
}
