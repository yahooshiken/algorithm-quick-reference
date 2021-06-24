#include <iostream>

#include "binary_heap.h"

using namespace std;

int main(int argc, char const *argv[]) {
  BinaryHeap heap(10);
  assert(heap.isEmpty());
  heap.insert(0, 10);
  assert(!heap.isEmpty());

  heap.insert(1, 5);
  assert(heap.smallest() == 1);
  assert(heap.smallest() == 0);
  assert(heap.isEmpty());

  heap.insert(2, 9);
  heap.insert(3, 2);
  heap.insert(4, 15);
  heap.insert(5, 11);
  heap.insert(6, 1);

  assert(heap.smallest() == 6);
  assert(heap.smallest() == 3);
  heap.decreaseKey(4, 3);
  assert(heap.smallest() == 4);
  assert(heap.smallest() == 2);
  assert(heap.smallest() == 5);
  assert(heap.isEmpty());

  cout << "Passed test" << endl;
  return 0;
}
