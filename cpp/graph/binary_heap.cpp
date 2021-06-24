#include <stdio.h>
#include <stdlib.h>

#include "binary_heap.h"

BinaryHeap::BinaryHeap(int i) {
  _n = 0;
  _elements = (ELEMENT *)calloc(i + 1, sizeof(ELEMENT));
  _pos = (int *)calloc(i + 1, sizeof(int));
}

BinaryHeap::~BinaryHeap() {
  free(_elements);
  free(_pos);
  _n = -1;
#ifdef REPORT
  printf("Num Smallest: %d\n", numSmallest);
  printf("Num Comparisons: %d\n", numComparisons);
  printf("Num Swaps: %d\n", numSwaps);
  printf("Num Insert: %d\n", numInsert);
  printf("Num Decrease: %d\n", numDecrease);
#endif
}

int BinaryHeap::smallest() {
  int id = _elements[1].id;
  int pIdx;
  INC_SMALL;

  ELEMENT last = _elements[_n];
  _n--;

  _elements[1] = last;

  pIdx = 1;
  int child = pIdx * 2;

  while (child <= _n) {
    ELEMENT sm = _elements[child];

    if (child < _n) {
      INC_COMP;
      if (sm.priority > _elements[child + 1].priority) {
        sm = _elements[++child];
      }
    }

    INC_COMP;
    if (last.priority <= sm.priority) {
      break;
    }

    INC_SWAP;
    _elements[pIdx] = sm;
    _pos[sm.id] = pIdx;

    pIdx = child;
    child = 2 * pIdx;
  }
  _elements[pIdx] = last;
  _pos[last.id] = pIdx;

  return id;
}

void BinaryHeap::insert(int id, int priority) {
  int i;

  INC_INSERT;

  i = ++_n;
  while (i > 1) {
    int pIdx = i / 2;
    ELEMENT p = _elements[pIdx];

    INC_COMP;
    if (priority > p.priority) {
      break;
    }

    INC_SWAP;
    _elements[i] = p;
    _pos[p.id] = i;
    i = pIdx;
  }

  _elements[i].id = id;
  _elements[i].priority = priority;
  _pos[id] = i;
}

void BinaryHeap::decreaseKey(int id, int newPriotiry) {
  int size = _n;
  INC_DECREASE;

  _n = _pos[id] - 1;
  insert(id, newPriotiry);

  _n = size;
}