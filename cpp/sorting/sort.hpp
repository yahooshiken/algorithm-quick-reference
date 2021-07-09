#ifndef _SORT_HPP_
#define _SORT_HPP_

#include <sstream>
#include <string>

using namespace std;

enum SortType { asc, desc };

template <typename T> class Sort {
public:
  Sort(){};
  ~Sort(){};

  const void swap(T *x, T *y) const;
  const bool compare(T *x, T *y, SortType type = asc) const;
  string const toString(T *arr, const int length) const;
  virtual const T *sort(T *arr, const int length,
                        SortType type = asc) const = 0;
};

template <typename T> const void Sort<T>::swap(T *x, T *y) const {
  T tmp = *x;
  *x = *y;
  *y = tmp;
}

template <typename T>
const bool Sort<T>::compare(T *x, T *y, SortType type) const {
  return type == asc ? *x > *y : *x < *y;
}

template <typename T>
string const Sort<T>::toString(T *arr, const int length) const {
  stringstream ss;

  for (int i = 0; i < length; i++) {
    ss << arr[i] << " ";
  }

  return ss.str();
}

#endif
