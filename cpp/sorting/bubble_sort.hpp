#include <sstream>
#include <string>

#include "sort.hpp"

using namespace std;

template <typename T> class BubbleSort : public Sort<T> {
public:
  BubbleSort(){};
  ~BubbleSort(){};
  void swap(T *x, T *y);
  T *sort(T *arr, const int length);
  string toString(T *arr, const int length);
};

template <typename T> T *BubbleSort<T>::sort(T *arr, const int length) {
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }

  return arr;
}

template <typename T> void BubbleSort<T>::swap(T *x, T *y) {
  T tmp = *x;
  *x = *y;
  *y = tmp;
}

template <typename T> string BubbleSort<T>::toString(T *arr, const int length) {
  stringstream ss;

  for (int i = 0; i < length; i++) {
    ss << arr[i] << " ";
  }

  return ss.str();
}