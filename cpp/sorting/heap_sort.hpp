#ifndef _HEAP_SORT_HPP_
#define _HEAP_SORT_HPP_

#include "sort.hpp"

#include "../data_structure/binary_tree.hpp"

template <typename T> class HeapSort : public Sort<T> {
private:
  BinaryTree<T> *tree;

public:
  HeapSort() { tree = new BinaryTree<T>(); };
  ~HeapSort(){};

  const T *sort(T *arr, const int length, SortType type = asc) const;
  const string toString(T *arr, const int length) const;
};

template <typename T>
const T *HeapSort<T>::sort(T *arr, const int length, SortType type) const {

  for (int i = 0; i < length; i++) {
    tree->add(arr[i]);
  }

  for (int i = 0; i < length; i++) {
    arr[i] = tree->pop();
  }

  return arr;
}

template <typename T>
const string HeapSort<T>::toString(T *arr, const int length) const {
  return Sort<T>::toString(arr, length);
};

#endif
