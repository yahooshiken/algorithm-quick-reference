#include <sstream>
#include <string>

using namespace std;

enum SortType { asc, desc };

template <typename T> class Sort {
public:
  Sort(){};
  ~Sort(){};

  void swap(T *x, T *y);
  bool compare(T *x, T *y, SortType type = asc);
  T *sort(T *arr, const int length, SortType type = asc);
  string toString(T *arr, const int length);
};

template <typename T> void Sort<T>::swap(T *x, T *y) {
  T tmp = *x;
  *x = *y;
  *y = tmp;
}

template <typename T> bool Sort<T>::compare(T *x, T *y, SortType type) {
  return type == asc ? *x > *y : *x < *y;
}

template <typename T> string Sort<T>::toString(T *arr, const int length) {
  stringstream ss;

  for (int i = 0; i < length; i++) {
    ss << arr[i] << " ";
  }

  return ss.str();
}